class Node(object):
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache(object):
    def __init__(self, capacity=2):
        self.capacity = capacity
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.dict = OrderedDict()

    def put(self, key, value):
        if key in self.dict:
            node = self.dict[key]
            self.remove(node)
        node = Node(key, value)
        self.add(node)
        self.dict[key] = node
        
        if len(self.dict) >= self.capacity:
            node = self.tail
            self.remove(node)

    def get(self, key):
        if key in self.dict:
            node = self.dict[key]
            value = node.value
            self.remove(node)
            node = Node(key, value)
            self.add(node)
            self.dict[key] = node
            return value
        return None

    def add(self, node):
        self.head.next.prev = node
        node.next = self.head.next
        self.head.next = node
        node.prev = self.head

    def remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
