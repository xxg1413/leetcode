#!/usr/bin/env python

class Solution(object):
	def twoSum(self, nums, target):
		d = {}
		for i in range(len(nums)):
			if d.get(target - nums[i], None) == None:      #not found 
				d[nums[i]] = i
			else:
				return [d[target - nums[i] ] + 1 , i + 1]  #rtype list 



nums = [6,1,2,7]
target = 9

s = Solution()
result = s.twoSum(nums, target)
print result
