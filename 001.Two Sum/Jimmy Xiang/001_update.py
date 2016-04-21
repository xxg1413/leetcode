class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for i in range(len(nums)):
            find = target  - nums[i]
            if d.get(find, None) == None:
                d[nums[i]] = i
            else:
                return [d[find], i]
