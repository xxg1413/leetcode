class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for i in range(len(nums)):
            if d.get(target - nums[i], None) == None:
                d[nums[i]] = i
            else:
                return (d[target - nums[i] ], i)

