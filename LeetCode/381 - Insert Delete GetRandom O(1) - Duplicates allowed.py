# https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/

from collections import defaultdict
from random import randrange

class Node:
    def __init__(self, val, prev, loc):
        self.val = val
        self.prev = prev
        self.loc = loc

class RandomizedCollection:

    def __init__(self):
        self.cur = defaultdict(lambda: None)
        self.arr = []

    def insert(self, val: int) -> bool:
        node = Node(val, self.cur[val], len(self.arr))
        self.arr.append(node)
        self.cur[val] = node
        if node.prev is None:
            return True
        return False

    def remove(self, val: int) -> bool:
        if self.cur[val] is None:
            return False
        node = self.cur[val]
        self.cur[val] = node.prev
        if node.loc == len(self.arr) - 1:
            self.arr.pop()
            del node
        else:
            end_node = self.arr.pop()
            end_node.loc = node.loc
            self.arr[node.loc] = end_node
            del node
        return True

    def getRandom(self) -> int:
        num = randrange(0, len(self.arr))
        return self.arr[num].val