#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
	
	vector<int> twoSum(vector<int> &nums, int target) {

		unordered_map<int,int> uno_map;
		vector<int> result;

		for(int i = 0; i < nums.size(); i++) {

			//not found 
			if(uno_map.find(nums[i]) == uno_map.end()) {
				uno_map[target - nums[i]] = i;

			} else  {

				result.push_back(uno_map[nums[i]] + 1);
				result.push_back(i + 1);
			}
		}

		return result;
	}

};


int main()
{

	vector<int> test={2,7,11,15};
	vector<int> result;

	Solution s;
	result=s.twoSum(test, 17);


	for(auto i:result) {
		cout<<i<<" ";
	}

	cout<<endl;

	return 0;
}