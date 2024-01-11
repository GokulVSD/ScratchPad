# https://leetcode.com/problems/valid-sudoku/description/

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        val = set(['1', '2', '3', '4', '5', '6', '7', '8', '9'])
        hor = [set() for _ in range(9)]
        ver = [set() for _ in range(9)]
        cube = [[set(), set(), set()] for _ in range(3)]
        for i in range(9):
            for j in range(9):
                c = board[i][j]
                if c == '.':
                    continue
                if c not in val or c in hor[i] or c in ver[j] or c in cube[i // 3][j // 3]:
                    return False
                hor[i].add(c)
                ver[j].add(c)
                cube[i // 3][j // 3].add(c)
        return True