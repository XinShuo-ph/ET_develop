#!/usr/bin/env python3

class EinsteinToolkitScorer:
    """Score generated code based on build and test results"""
    
    def __init__(self):
        # Scoring weights
        self.weights = {
            'build_success': 0.4,  # 40% of score comes from successful build
            'test_success_rate': 0.5,  # 50% from test success rate
            'error_penalty': 0.1   # 10% penalty for various errors
        }
    
    def calculate_score(self, build_result, test_result):
        """
        Calculate overall score based on build and test results
        
        Args:
            build_result: Dict with build information
            test_result: Dict with test results
        
        Returns:
            Dict with score breakdown and overall score (0-100)
        """
        
        # Build score component
        build_score = 100.0 if build_result.get('success', False) else 0.0
        
        # Test score component
        if test_result.get('total_tests', 0) > 0:
            test_success_rate = test_result.get('passed_tests', 0) / test_result.get('total_tests', 1)
            test_score = test_success_rate * 100.0
        else:
            test_success_rate = 0.0
            test_score = 0.0
        
        # Error penalty calculation
        error_penalty = 0.0
        
        # Penalty for build errors
        if not build_result.get('success', False):
            if 'error' in build_result.get('stderr', '').lower():
                error_penalty += 20.0
            if 'fatal' in build_result.get('stderr', '').lower():
                error_penalty += 30.0
        
        # Penalty for test errors
        if test_result.get('test_results'):
            for test in test_result['test_results']:
                if not test.get('success', False):
                    if 'timeout' in test.get('error', '').lower():
                        error_penalty += 5.0
                    elif 'missing' in test.get('error', '').lower():
                        error_penalty += 10.0
        
        # Cap error penalty at 50
        error_penalty = min(error_penalty, 50.0)
        
        # Calculate weighted overall score
        overall_score = (
            build_score * self.weights['build_success'] +
            test_score * self.weights['test_success_rate'] -
            error_penalty * self.weights['error_penalty']
        )
        
        # Ensure score is between 0 and 100
        overall_score = max(0.0, min(100.0, overall_score))
        
        return {
            'overall_score': overall_score,
            'build_score': build_score,
            'test_score': test_score,
            'error_penalty': error_penalty,
            'breakdown': {
                'build_success': build_result.get('success', False),
                'total_tests': test_result.get('total_tests', 0),
                'passed_tests': test_result.get('passed_tests', 0),
                'failed_tests': test_result.get('failed_tests', 0),
                'test_success_rate': test_success_rate if test_result.get('total_tests', 0) > 0 else 0.0
            },
            'grade': self._get_letter_grade(overall_score)
        }
    
    def _get_letter_grade(self, score):
        """Convert numerical score to letter grade"""
        if score >= 90:
            return 'A'
        elif score >= 80:
            return 'B'
        elif score >= 70:
            return 'C'
        elif score >= 60:
            return 'D'
        else:
            return 'F'
    
    def generate_detailed_report(self, thorn_name, src_filename, build_result, test_result, score_result):
        """Generate a detailed text report"""
        
        report = []
        report.append("=" * 80)
        report.append(f"EINSTEINTOOLKIT CODE GENERATION REPORT")
        report.append("=" * 80)
        report.append(f"Thorn: {thorn_name}")
        report.append(f"File: {src_filename}")
        report.append(f"Overall Score: {score_result['overall_score']:.1f}/100 (Grade: {score_result['grade']})")
        report.append("")
        
        # Build results
        report.append("BUILD RESULTS:")
        report.append("-" * 40)
        if build_result.get('success'):
            report.append("✅ Build SUCCEEDED")
        else:
            report.append("❌ Build FAILED")
            if build_result.get('stderr'):
                report.append(f"Error: {build_result['stderr'][:200]}...")
        
        report.append(f"Build Score: {score_result['build_score']:.1f}/100")
        report.append("")
        
        # Test results
        report.append("TEST RESULTS:")
        report.append("-" * 40)
        breakdown = score_result['breakdown']
        report.append(f"Total Tests: {breakdown['total_tests']}")
        report.append(f"Passed: {breakdown['passed_tests']}")
        report.append(f"Failed: {breakdown['failed_tests']}")
        report.append(f"Success Rate: {breakdown['test_success_rate']:.1%}")
        
        if test_result.get('test_results'):
            report.append("\nIndividual Test Results:")
            for test in test_result['test_results']:
                status = "✅ PASS" if test.get('success') else "❌ FAIL"
                report.append(f"  {status} {test.get('test_name', 'Unknown')}")
                if not test.get('success') and test.get('error'):
                    report.append(f"    Error: {test['error']}")
        
        report.append(f"\nTest Score: {score_result['test_score']:.1f}/100")
        report.append("")
        
        # Error penalties
        if score_result['error_penalty'] > 0:
            report.append("ERROR PENALTIES:")
            report.append("-" * 40)
            report.append(f"Total Penalty: -{score_result['error_penalty']:.1f} points")
            report.append("")
        
        # Summary
        report.append("SUMMARY:")
        report.append("-" * 40)
        report.append(f"Generated code quality: {score_result['grade']}")
        if score_result['overall_score'] >= 80:
            report.append("🎉 Excellent! Code builds and tests pass successfully.")
        elif score_result['overall_score'] >= 60:
            report.append("👍 Good! Code builds with some test issues.")
        elif score_result['overall_score'] >= 40:
            report.append("⚠️  Needs improvement. Build or test issues detected.")
        else:
            report.append("❌ Poor quality. Significant build/test failures.")
        
        report.append("=" * 80)
        
        return "\n".join(report)

def test_scoring_system():
    """Test the scoring system with various scenarios"""
    
    scorer = EinsteinToolkitScorer()
    
    # Test scenario 1: Perfect success
    print("Testing Scenario 1: Perfect Success")
    build_result_1 = {'success': True, 'stderr': ''}
    test_result_1 = {
        'success': True,
        'total_tests': 3,
        'passed_tests': 3,
        'failed_tests': 0,
        'test_results': [
            {'test_name': 'test1', 'success': True},
            {'test_name': 'test2', 'success': True},
            {'test_name': 'test3', 'success': True}
        ]
    }
    
    score_1 = scorer.calculate_score(build_result_1, test_result_1)
    print(f"Score: {score_1['overall_score']:.1f}/100 (Grade: {score_1['grade']})")
    print()
    
    # Test scenario 2: Build success, partial test failure
    print("Testing Scenario 2: Build Success, Partial Test Failure")
    build_result_2 = {'success': True, 'stderr': ''}
    test_result_2 = {
        'success': False,
        'total_tests': 3,
        'passed_tests': 2,
        'failed_tests': 1,
        'test_results': [
            {'test_name': 'test1', 'success': True},
            {'test_name': 'test2', 'success': True},
            {'test_name': 'test3', 'success': False, 'error': 'timeout'}
        ]
    }
    
    score_2 = scorer.calculate_score(build_result_2, test_result_2)
    print(f"Score: {score_2['overall_score']:.1f}/100 (Grade: {score_2['grade']})")
    print()
    
    # Test scenario 3: Build failure
    print("Testing Scenario 3: Build Failure")
    build_result_3 = {'success': False, 'stderr': 'fatal error: compilation failed'}
    test_result_3 = {
        'success': False,
        'total_tests': 0,
        'passed_tests': 0,
        'failed_tests': 0,
        'test_results': []
    }
    
    score_3 = scorer.calculate_score(build_result_3, test_result_3)
    print(f"Score: {score_3['overall_score']:.1f}/100 (Grade: {score_3['grade']})")
    print()
    
    # Test detailed report
    print("Testing Detailed Report:")
    print()
    report = scorer.generate_detailed_report(
        "CactusExamples/Poisson", 
        "uniform_charge.c",
        build_result_2,
        test_result_2,
        score_2
    )
    print(report)

if __name__ == "__main__":
    test_scoring_system()
