# https://leetcode.com/problems/lru-cache/description/

from collections import OrderedDict

class LRUCache:

    def __init__(self, capacity: int):
        self.c = capacity
        self.d = OrderedDict()

    def get(self, key: int) -> int:
        if key in self.d:
            self.d.move_to_end(key)
            return self.d[key]
        return -1

    def put(self, key: int, value: int) -> None:
        if key not in self.d and len(self.d) == self.c:
            self.d.popitem(last=False)
        self.d[key] = value
        self.d.move_to_end(key)