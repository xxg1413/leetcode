from collections import defaultdict

class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        dic = defaultdict(set)
        res = set()
        n  = len(nums)

        for i in range(n):
        	for j in range(i+1, n):
        		 sum = nums[i] + nums[j]
        		 for half in dic[target - sum]:
        		 	res.add(tuple(list(half) + [nums[i],nums[j]]))

        	for k in range(i):
        		dic[nums[i] + nums[k]].add((nums[k],nums[i]))

        return list(res)
