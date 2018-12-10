import sys

class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        result = 0
        diff = sys.maxsize
        for index, a in enumerate(nums):
            left = index + 1
            right = len(nums) -1
            
            while left < right:
                b = nums[left]
                c = nums[right]
                total = a + b + c
                if total == target:
                    return total
                if abs(total-target) < diff:
                    diff = abs(total-target)
                    result = total
                if total < target:
                    left += 1
                if total > target:
                    right -=1
        return result
    