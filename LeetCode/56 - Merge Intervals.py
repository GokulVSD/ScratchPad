# https://leetcode.com/problems/merge-intervals/description/

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        intervals.sort(key=lambda x: x[0])
        merged = []
        i = 0
        while i < n:
            start = intervals[i][0]
            end = intervals[i][1]
            while i + 1 < n:
                if intervals[i + 1][0] <= end:
                    end = max(end, intervals[i + 1][1])
                    i += 1
                else:
                    break
            merged.append([start, end])
            i += 1
        return merged