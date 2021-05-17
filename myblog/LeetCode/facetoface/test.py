class WordsFrequency:

    def __init__(self, book):
        self.words = {}
        for word in book:
            try:
                if self.words[word]:
                    self.words[word] +=1
            except:
                self.words[word] = 1

    def get(self, word: str) -> int:
        return self.words[word]
        
book = WordsFrequency(["i","have","an","apple","he","have","a","pen"])
for i in ["i","have","an","apple","he","have","a","pen"]:
    print(book.get(i))


