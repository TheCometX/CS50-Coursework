class Questions:
    allQuestions = []

    def question_list():
        from random import choice

        questionList = []

        x = 0
        while x < 10:
            question = choice(allQuestions)
            if question not in questionList:
                questionList.append(question)
                x +=1

        return questionList


