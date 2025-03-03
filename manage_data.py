import json
import sqlite3


class Questions:
    def add_questions():
        database = sqlite3.connect('')

with open('https://opentdb.com/api.php?amount=50&type=multiple', 'r') as file:
    data = json.load(file)
    for x in data['results']:
        print(x)
