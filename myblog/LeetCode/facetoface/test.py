class StreamRank:

    def __init__(self):
        self.list = []


    def track(self, x: int) -> None:
        self.list.append(x)
        self.list.sort(reverse=True)


    def getRankOfNumber(self, x: int) -> int:
        self.track(x)
        index = self.list.index(x)
        if index == len(self.list)-1:
            self.list.pop(index)
            return 0
        num = len(self.list)-self.list.index(x)-1
        self.list.pop(index)
        return num

s = StreamRank()
s.track(4)
s.track(3)
s.track(5)
s.getRankOfNumber(8)
s.track(3)
s.getRankOfNumber(2)
