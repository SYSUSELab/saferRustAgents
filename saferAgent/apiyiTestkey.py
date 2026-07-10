import os

from openai import APIConnectionError, APITimeoutError, OpenAI


API_KEY = os.environ.get("SAFER_AGENT_API_KEY") or os.environ.get("DEEPSEEK_API_KEY")
BASE_URL = os.environ.get("SAFER_AGENT_BASE_URL", "https://api.deepseek.com")
MODEL_NAME = os.environ.get("SAFER_AGENT_MODEL", "deepseek-reasoner")
REQUEST_TIMEOUT_SECONDS = 60.0


def fail_with_request_error(exc: Exception) -> None:
    if isinstance(exc, APITimeoutError):
        raise SystemExit(
            f"Request timed out after {REQUEST_TIMEOUT_SECONDS}s. "
            f"Please check the API path, model name, or server responsiveness at {BASE_URL}."
        ) from exc
    if isinstance(exc, APIConnectionError):
        raise SystemExit(
            f"Failed to connect to {BASE_URL}. "
            f"This is usually a DNS/network/proxy issue: {exc}"
        ) from exc
    raise SystemExit(f"Request failed: {type(exc).__name__}: {exc}") from exc


def main() -> None:
    if not API_KEY:
        raise SystemExit(
            "Missing API key. Set SAFER_AGENT_API_KEY or DEEPSEEK_API_KEY before running this test."
        )

    client = OpenAI(
        api_key=API_KEY,
        base_url=BASE_URL,
        timeout=REQUEST_TIMEOUT_SECONDS,
        max_retries=0,
    )

    try:
        print("Step 1/2: testing authentication with models.list() ...")
        models = client.models.list()
        model_ids = [model.id for model in list(models.data)[:5]]
        print(f"models.list() ok, first models: {model_ids}")
    except Exception as exc:
        fail_with_request_error(exc)

    try:
        print(f"Step 2/2: testing chat.completions.create() with model={MODEL_NAME!r} ...")
        completion = client.chat.completions.create(
            model=MODEL_NAME,
            stream=False,
            messages=[
                {"role": "system", "content": "You are a helpful assistant."},
                {"role": "user", "content": "Hello! What is your model name?"},
            ],
        )
    except Exception as exc:
        fail_with_request_error(exc)

    print(completion.choices[0].message.content)


if __name__ == "__main__":
    main()
