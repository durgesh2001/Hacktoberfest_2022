import json
import requests

endpoint = "https://api.quotable.io/random"
data = requests.get(endpoint).json()

print(data['content'])
print(f"- {data['author']}")

