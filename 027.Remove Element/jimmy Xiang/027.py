class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """

        num = 0

        for i in range(len(nums)):
            if nums[i] == val:
                continue
            nums[num] = nums[i]
            num += 1

        return num


