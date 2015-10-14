#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
	
	vector<int> twoSum(vector<int> &nums, int target) {

		unordered_map<int,int> uno_map;
		vector<int> result;

		//init map 
		for(int i = 0; i < nums.size(); i++) {

			uno_map[nums[i]] = i;
		}

		//find the target - nums[i] 
		for(int i = 0; i < nums.size(); i++) {

			const int other = target - nums[i];
			//uno_map[other] > i -> uno_map[other]'s position is more than i 
			if(uno_map.find(other) != uno_map.end() && uno_map[other] > i) {

				result.push_back(i + 1);
				result.push_back(uno_map[other] + 1);
				break;
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