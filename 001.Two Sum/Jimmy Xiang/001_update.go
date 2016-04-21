func twoSum(nums []int, target int) []int {
    res := [2]int{-1,-1}
    
    for i, v := range nums {
        for j, o := range nums {
            if i < j && (target-v) == o {
                res[0]=i
                res[1]=j
                
                return res[:]
            }
        }
    }
    
    return res[:]
}
