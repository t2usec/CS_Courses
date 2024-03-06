class Node:
    data = None
    next = None

    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next


def CreateHeader():
    head = Node()
    return head

def Insert(head, data):
    new_node = Node(data)
    new_node.next = head.next
    head.next = new_node