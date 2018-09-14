# circular, doubly linked list with sentinel
class Node(object):
    def __init__(self, value):
        self.value = value
        self.prev = None
        self.next = None

class DoubleLinkedList(object):
    def __init__(self):
        self.head = Node(0)
        self.head.prev = self.head
        self.head.next = self.head

    def insert(self, value):
        node = Node(value)
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node
        node.prev = self.head
        
    def delete(self, value):
        #node = self.head.next
        #while node != self.head and node.value != value:
        #    node = node.next

        node = self.search(value)
        if node:
            node.next.prev = node.prev
            node.prev.next = node.next

    def search(self, value):
        node = self.head.next
        while node != self.head and node.value != value:
            node = node.next
        if node.value == value:
            return node
        else:
            return None

    def print_list(self):
        node = self.head.next
        value_list = []
        while node != self.head:
            value_list.append(node.value)
            node = node.next
        
        print(value_list)

def test():
    dlist = DoubleLinkedList()
    dlist.insert(2)
    dlist.insert(5)
    dlist.insert(7)
    dlist.insert(9)

    dlist.print_list()

    dlist.delete(9)
    dlist.print_list()

    node = dlist.search(5)
    print(node.value)

if __name__ == '__main__':
    #import pdb
    #pdb.set_trace()
    test()
