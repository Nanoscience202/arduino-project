import ollama

stream = ollama.generate(
    model="mistral",
    prompt="What is the theory of relativity?",
    stream=True,
)

for chunk in stream:
    rse = ""
    if isinstance(chunk, str):
        res = chunk.replace("\n", " ")
    else:
        res = chunk["response"].replace("\n", " ")

    print(res, end="", flush=True)
