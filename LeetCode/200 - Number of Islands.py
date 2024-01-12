# https://leetcode.com/problems/number-of-islands/description/

from collections import deque

class Solution:
    def traverseLand(self, land, visited, grid):
        m, n = len(grid), len(grid[0])
        delta_v = [-1, 1, 0, 0]
        delta_h = [0, 0, -1, 1]
        while len(land) != 0:
            i, j = land.popleft()
            for k in range(4):
                if i + delta_v[k] >= m or i + delta_v[k] < 0:
                    continue
                if j + delta_h[k] >= n or j + delta_h[k] < 0:
                    continue
                if grid[i + delta_v[k]][j + delta_h[k]] != '1':
                    continue
                if (i + delta_v[k], j + delta_h[k]) not in visited:
                    visited.add((i + delta_v[k], j + delta_h[k]))
                    land.append((i + delta_v[k], j + delta_h[k]))

    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        que = deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    que.append((i, j))
        visited = set()
        islands = 0
        while len(que) != 0:
            i, j = que.popleft()
            if (i, j) in visited:
                continue
            islands += 1
            visited.add((i, j))
            land = deque()
            land.append((i, j))
            self.traverseLand(land, visited, grid)
        return islands