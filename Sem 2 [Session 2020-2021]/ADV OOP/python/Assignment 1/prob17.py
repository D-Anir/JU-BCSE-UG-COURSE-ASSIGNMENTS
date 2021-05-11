# priority queue

class PriorityQueue(object):
    elements = []
    
    # constructor
    def __init__(self):
        self.elements = []

    # print elements
    def __str__(self):
        ' '.join([str(i) for i in self.elements])

    # check if queue is empty
    def isEmpty(self):
        return len(self.elements) == 0

    # push elements in the queue
    def push(self, data, priority):
        self.elements.append((data, priority))

    # sort the queue
    def sort(self):
        lst = len(self.elements) 
        for i in range(0, lst): 
            
            for j in range(0, lst-i-1): 
                if (self.elements[j][1] < self.elements[j + 1][1]): 
                    temp = self.elements[j] 
                    self.elements[j]= self.elements[j + 1] 
                    self.elements[j + 1]= temp 

    # pop the element with highest priority
    def pop(self):
        try:
            item = self.elements[0]
            self.elements.remove(item)
            return item
    
        except IndexError:
            print()
            exit()

# main
if __name__ == '__main__':
    myQueue = PriorityQueue()

    myQueue.push('a', 2)
    myQueue.push('b', 10)
    myQueue.push('c', 8)
    myQueue.push('d', 4)

    myQueue.sort()     

    while not myQueue.isEmpty():
        print(myQueue.pop())