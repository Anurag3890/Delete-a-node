class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class LinkedList:
    def __init__(self):
        self.head=None

    def insert_end(self,val):
        newnode=Node(val)
        if not self.head:self.head=newnode;return
        temp=self.head
        while temp.next:temp=temp.next
        temp.next=newnode

    def delete_pos(self,pos):
        if not self.head:return
        if pos==0:self.head=self.head.next;return
        temp=self.head
        for _ in range(pos-1):
            if not temp.next:return
            temp=temp.next
        if not temp.next:return
        temp.next=temp.next.next

    def display(self):
        temp=self.head
        while temp: print(temp.data,end=" "); temp=temp.next
        print()

ll=LinkedList()
ll.insert_end(10); ll.insert_end(20); ll.insert_end(30); ll.insert_end(40)
ll.delete_pos(2)
ll.display()
