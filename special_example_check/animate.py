#!/usr/bin/env python3
"""
Animation script to compare phi_3D_diagonal.xg data files
Compares reference (wavetoyc) vs generated test output
"""

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import re
from pathlib import Path

def parse_xg_file(filepath):
    """
    Parse .xg file and extract time series data
    Returns: list of (time, coordinates, values) tuples
    """
    data_blocks = []
    
    with open(filepath, 'r') as f:
        lines = f.readlines()
    
    current_time = None
    current_coords = []
    current_values = []
    
    for line in lines:
        line = line.strip()
        
        # Check for time line
        time_match = re.match(r'"Time = ([\d\.]+)', line)
        if time_match:
            # Save previous block if it exists
            if current_time is not None and current_coords:
                data_blocks.append((current_time, np.array(current_coords), np.array(current_values)))
            
            # Start new block
            current_time = float(time_match.group(1))
            current_coords = []
            current_values = []
        
        # Check for data line (coordinate\t\tvalue)
        elif line and '\t' in line:
            parts = line.split('\t')
            if len(parts) >= 2:
                try:
                    coord = float(parts[0])
                    value = float(parts[-1])  # Take last part in case of multiple tabs
                    current_coords.append(coord)
                    current_values.append(value)
                except ValueError:
                    continue
    
    # Don't forget the last block
    if current_time is not None and current_coords:
        data_blocks.append((current_time, np.array(current_coords), np.array(current_values)))
    
    return data_blocks

def create_animation():
    """Create animated comparison of the two datasets"""
    
    # File paths
    reference_file = Path("/Users/bytedance/ET_develop/special_example_check/wavetoyc/phi_3D_diagonal.xg")
    generated_file = Path("/Users/bytedance/ET_develop/special_example_check/generated_test_output/phi_3D_diagonal.xg")
    
    print("Parsing reference data...")
    reference_data = parse_xg_file(reference_file)
    print(f"Found {len(reference_data)} time steps in reference")
    
    print("Parsing generated data...")
    generated_data = parse_xg_file(generated_file)
    print(f"Found {len(generated_data)} time steps in generated")
    
    # Ensure we have the same number of time steps
    min_steps = min(len(reference_data), len(generated_data))
    reference_data = reference_data[:min_steps]
    generated_data = generated_data[:min_steps]
    
    # Set up the figure and axis
    fig, ax = plt.subplots(figsize=(12, 8))
    ax.set_xlabel('Coordinate', fontsize=12)
    ax.set_ylabel('φ (phi)', fontsize=12)
    ax.set_title('Comparison: Reference vs Generated LinearExtrapBnd', fontsize=14)
    ax.grid(True, alpha=0.3)
    
    # Initialize empty line objects
    line_ref, = ax.plot([], [], 'b-', linewidth=2, label='Reference (wavetoyc)', marker='o', markersize=4)
    line_gen, = ax.plot([], [], 'r--', linewidth=2, label='Generated', marker='s', markersize=4)
    
    # Add legend
    ax.legend(loc='upper right')
    
    # Set axis limits based on all data
    all_coords = []
    all_values = []
    
    for _, coords, values in reference_data + generated_data:
        all_coords.extend(coords)
        all_values.extend(values)
    
    coord_margin = (max(all_coords) - min(all_coords)) * 0.05
    value_margin = (max(all_values) - min(all_values)) * 0.1
    
    ax.set_xlim(min(all_coords) - coord_margin, max(all_coords) + coord_margin)
    ax.set_ylim(min(all_values) - value_margin, max(all_values) + value_margin)
    
    # Time text
    time_text = ax.text(0.02, 0.95, '', transform=ax.transAxes, fontsize=12,
                       bbox=dict(boxstyle="round,pad=0.3", facecolor="white", alpha=0.8))
    
    def animate(frame):
        """Animation function for each frame"""
        if frame >= len(reference_data) or frame >= len(generated_data):
            return line_ref, line_gen, time_text
        
        # Get data for current frame
        ref_time, ref_coords, ref_values = reference_data[frame]
        gen_time, gen_coords, gen_values = generated_data[frame]
        
        # Update line data
        line_ref.set_data(ref_coords, ref_values)
        line_gen.set_data(gen_coords, gen_values)
        
        # Update time display
        time_text.set_text(f'Time = {ref_time:.4f}')
        
        return line_ref, line_gen, time_text
    
    # Create animation
    print("Creating animation...")
    ani = animation.FuncAnimation(fig, animate, frames=min_steps,
                                interval=500, blit=True, repeat=True)
    
    # Save as gif
    output_file = "/Users/bytedance/ET_develop/special_example_check/comparison_animation.gif"
    print(f"Saving animation to {output_file}...")
    
    # Use pillow writer for better gif quality
    writer = animation.PillowWriter(fps=2)
    ani.save(output_file, writer=writer)
    
    print(f"Animation saved successfully!")
    print(f"Number of frames: {min_steps}")
    print(f"Time range: {reference_data[0][0]:.4f} to {reference_data[-1][0]:.4f}")
    
    # Also save a static comparison plot for the final time step
    plt.figure(figsize=(12, 8))
    final_ref = reference_data[-1]
    final_gen = generated_data[-1]
    
    plt.plot(final_ref[1], final_ref[2], 'b-', linewidth=2, label='Reference (wavetoyc)', marker='o', markersize=4)
    plt.plot(final_gen[1], final_gen[2], 'r--', linewidth=2, label='Generated', marker='s', markersize=4)
    
    plt.xlabel('Coordinate', fontsize=12)
    plt.ylabel('φ (phi)', fontsize=12)
    plt.title(f'Final Comparison at Time = {final_ref[0]:.4f}', fontsize=14)
    plt.legend()
    plt.grid(True, alpha=0.3)
    
    static_file = "/Users/bytedance/ET_develop/special_example_check/final_comparison.png"
    plt.savefig(static_file, dpi=150, bbox_inches='tight')
    print(f"Static comparison saved to {static_file}")
    
    # Show some statistics
    print("\nNumerical comparison at final time:")
    ref_final_values = final_ref[2]
    gen_final_values = final_gen[2]
    
    if len(ref_final_values) == len(gen_final_values):
        diff = np.abs(ref_final_values - gen_final_values)
        max_diff = np.max(diff)
        mean_diff = np.mean(diff)
        rms_diff = np.sqrt(np.mean(diff**2))
        
        print(f"Maximum absolute difference: {max_diff:.2e}")
        print(f"Mean absolute difference: {mean_diff:.2e}")
        print(f"RMS difference: {rms_diff:.2e}")
        
        # Find point with maximum difference
        max_idx = np.argmax(diff)
        print(f"Maximum difference at coordinate: {final_ref[1][max_idx]:.6f}")
        print(f"  Reference value: {ref_final_values[max_idx]:.6f}")
        print(f"  Generated value: {gen_final_values[max_idx]:.6f}")

if __name__ == "__main__":
    create_animation()
