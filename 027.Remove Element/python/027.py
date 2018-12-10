class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        
        num = 0
        
        for index, value in enumerate(nums):
            if value !=val:
                nums[num]=nums[index]
                num +=1
            
        return num 