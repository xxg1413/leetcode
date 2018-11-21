class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #hash解法
        
        d = {}
        
        for i in range(len(nums)):
            find = target - nums[i]
            if d.get(find,None) == None:
                d[nums[i]] = i  #创建字典，数为key，值为下标
            else:
                return [d[find],i]
            
        