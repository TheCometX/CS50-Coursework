def questions():
    import json
    from random import choice

    questionList = []

    with open('trivia_api.json', 'r') as file:
        questions = json.load(file)
        for x in range(10):
            question = choice(questions["results"])
            questionList.append(Question(question["question"], list(question["correct_answer"]) + question["incorrect_answers"], question["correct_answer"]))

        return questionList

class Question:
    def __init__(self, question, answers, correct):
        self._question = question
        self._answers = answers
        self._correct = correct
