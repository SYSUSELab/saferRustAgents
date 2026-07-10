import os

from openai import OpenAI

api_key = os.environ.get("DEEPSEEK_API_KEY") or os.environ.get("SAFER_AGENT_API_KEY")
if not api_key:
    raise SystemExit(
        "Missing API key. Set DEEPSEEK_API_KEY or SAFER_AGENT_API_KEY before running this test."
    )

client = OpenAI(
    api_key=api_key,
    base_url=os.environ.get("DEEPSEEK_BASE_URL", "https://api.deepseek.com"),
)

response = client.chat.completions.create(
    model=os.environ.get("DEEPSEEK_MODEL", "deepseek-reasoner"),
    messages=[
        {"role": "system", "content": "You are a helpful assistant"},
        {"role": "user", "content": "Hello"},
    ],
    stream=False,
)

print(response.choices[0].message.content)
