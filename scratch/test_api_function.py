#!/usr/bin/env python3

import os
import json
import openai

def generate_code_with_api(prompt_text, api_key=None, max_tokens=4000):
    """Generate code using the remote API based on api_usage.py"""
    
    if api_key is None:
        api_key = os.environ.get("SEED_LLM_API_KEY")
        if not api_key:
            print("Error: SEED_LLM_API_KEY not set!")
            return None
    
    base_url = "https://gpt-i18n.byteintl.net/gpt/openapi/online/v2/crawl/openai/deployments/gpt_openapi"
    api_version = "2024-03-01-preview"
    model_name = "gcp-claude4-sonnet"
    
    client = openai.AzureOpenAI(
        azure_endpoint=base_url,
        api_version=api_version,
        api_key=api_key,
    )

    try:
        completion = client.chat.completions.create(
            model=model_name,
            messages=[
                {
                    "role": "user",
                    "content": [
                        {
                            "type": "text",
                            "text": prompt_text
                        }
                    ]
                }
            ],
            max_tokens=max_tokens,
            extra_headers={"X-TT-LOGID": ""},
        )
        
        # Parse the response JSON
        response_json = json.loads(completion.model_dump_json())
        
        # Extract the generated content
        if 'choices' in response_json and response_json['choices']:
            if 'message' in response_json['choices'][0] and 'content' in response_json['choices'][0]['message']:
                return response_json['choices'][0]['message']['content']
        
        print("Error: Could not extract content from API response")
        return None
        
    except Exception as e:
        print(f"Error calling API: {e}")
        return None

def test_api_function():
    """Test the API function with a simple prompt"""
    
    # Test if we have an API key
    api_key = os.environ.get("SEED_LLM_API_KEY")
    if not api_key:
        print("No API key found in environment. Please set SEED_LLM_API_KEY environment variable.")
        print("For testing, let's create a mock function instead.")
        return None
    
    test_prompt = "Write a simple Hello World program in C++."
    
    print("Testing API function...")
    result = generate_code_with_api(test_prompt)
    
    if result:
        print("API call successful!")
        print(f"Generated content: {result[:200]}...")  # Show first 200 chars
        return result
    else:
        print("API call failed.")
        return None

if __name__ == "__main__":
    test_api_function()
