
class Node(object):
    def __init__(self, val):
        self.val = val
        self.prev = None
        self.next = None
# 
class BaseLinkedList(object):
    def __init__(self):
        self.nil = Node(0)
        self.nil.next = self.nil
        self.nil.prev = self.nil
    
    def get(self, index):
        pass

    def add_at_head(self, val):
        pass
    
    def add_at_tail(self, val):
        pass

    def add_at_index(self, index):
        pass

    def delete_at_index(self, index):
        pass

    def print_all(self):
        node = self.nil.next
        dlist = []
        while node != self.nil:
           dlist.append(node.val)
           node = node.next
        print(dlist)

# circular doubly linked list with sentinel
class MyLinkedList(BaseLinkedList):
    def __init__(self):
        super(MyLinkedList, self).__init__()

    def get(self, index):
        node = self.nil.next
        while node != self.nil and index > 0:
            node = node.next
            index -= 1
        if index != 0 or node == self.nil:
            return -1
        return node.val

    def add_at_head(self, val):
        node = Node(val)
        node.next = self.nil.next
        self.nil.next.prev = node
        node.prev = self.nil
        self.nil.next = node
    
    def add_at_tail(self, val):
        node = Node(val)
        node.prev = self.nil.prev
        self.nil.prev.next = node
        node.next = self.nil
        self.nil.prev = node

    def add_at_index(self, index, val):
        node = self.nil.next
        while node != self.nil and index > 0:
            node = node.next
            index -= 1
        if index != 0:
            return
        cur = Node(val)
        cur.prev = node.prev
        node.prev.next = cur
        cur.next = node
        node.prev = cur

    def delete_at_index(self, index):
        node = self.nil.next
        while node != self.nil and index > 0:
            node = node.next
            index -= 1
        if index != 0 or node == self.nil:
            return 
        node.next.prev = node.prev
        node.prev.next = node.next

def test():
    obj = MyLinkedList()
    print(obj.get(0))

    obj.add_at_head(1)
    obj.add_at_tail(2)
    obj.add_at_tail(3)
    obj.add_at_index(3, 4)
    obj.delete_at_index(5)
    obj.print_all()
    print(obj.get(4))

if __name__ == '__main__':
    test()
