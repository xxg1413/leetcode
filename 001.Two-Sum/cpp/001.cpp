class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> indies;
        
        //init map
        for(int i=0; i<nums.size(); ++i){
            indies[nums[i]] = i;
        }
        
        //find the key
        for(int i=0; i< nums.size(); ++i){
            int key = target - nums[i];

            if(indies.count(key) && indies[key] != i) {
                return {i, indies[key]};
            }
        }
        return {};
    }
};