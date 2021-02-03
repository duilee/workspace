class MyCircularQueue:

    def __init__(self, k: int):
        self.circleq = []
        self.num_elem = 0
        self.max_num_elem = k

    def enQueue(self, value: int) -> bool:
        if self.num_elem < self.max_num_elem:
            self.circleq.append(value)
            self.num_elem += 1
            return True
        else:
            return False

    def deQueue(self) -> bool:
        if len(self.circleq) > 0:
            self.num_elem -= 1
            self.circleq.pop(0)
            return True
        else:
            return False

    def Front(self) -> int:
        if len(self.circleq) != 0:
            return self.circleq[0]
        else:
            return -1

    def Rear(self) -> int:
        if len(self.circleq) != 0:
            return self.circleq[self.num_elem - 1]
        else:
            return -1

    def isEmpty(self) -> bool:
        return len(self.circleq) == 0

    def isFull(self) -> bool:
        return len(self.circleq) == self.max_num_elem

# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()