import json
import sqlite3


class Questions:
    def add_questions():
        database = sqlite3.connect('')

with open('trivia_api.json', 'r') as file:
    data = json.load(file)
    for x in data['results']:
        print(x)
