# -*- coding: utf-8 -*-  
# Base Stack 

#class Stack(object):
#    def __init__(self):
#        self._items = []
#
#    def is_empty(self):
#        return self._items == []
#
#    def push(self, item):
#        self._items.append(item)
#
#    def pop(self):
#        return self._items.pop()


class Stack(object):
    """Example:
        s = Stack(10)
        s.s1.push(2)
        s.s2.push(3)

    """
    def __init__(self, size):
        self._size = size
        self._items = [0 for i in range(self._size)]
        self.top = 0

    def empty(self):
        if self.top == 0:
            return True
        else:
            return False
    
    def push(self, key):
        if self.top + 1 >= self._size:
            return "Stack is full"
        self.top += 1
        self._items[self.top] = key

    def pop(self):
        if self.empty():
            return "Stack is empty"
        self.top -= 1
        return self._items[self.top + 1]
        
s = Stack(10)
s.push(2)
s.push(4)
s.push(5)
print(s.pop())
print(s.pop())
