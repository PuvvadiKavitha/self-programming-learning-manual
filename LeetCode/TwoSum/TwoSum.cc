#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
 public:
  static std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> res;
	int len = nums.size();
	for (int i = 0; i < len - 1; i++) {
	  for (int j = i + 1; j < len; j++) {
	    if (target == (nums[i] + nums[j])) {
		  res.push_back(i);
		  res.push_back(j);
		  return res;
		}
	  }
	}
  }

  // 2 7 11 15
  static std::vector<int> twoSum2(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> m;
	std::vector<int> res;
	
	for (int i = 0; i < nums.size(); i++) {
	  if (m.find(nums[i]) == m.end()) {
	    // m[7] = 0
	    m[target - nums[i]] = i; 
	  } else {
		// push m[7] = 0
	    res.push_back(m[nums[i]]);
		// push    i = 1
		res.push_back(i);
		break;
	  }
	}

	return res;
  }
  
  // 2 7 11 15
  static std::vector<int> twoSum3(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> m;
	std::vector<int> res;
	
	for (int i = 0; i < nums.size(); i++) {
	  if (m.find(nums[i]) == m.end()) {
	    // m[7] = 0
	    m[target - nums[i]] = i; 
	  } else {
	    return std::vector<int> { m[nums[i]], i };
	  }
	}
  }

};


int main() {
  std::vector<int> nums = { 2, 7, 11, 7, 2, 2, 15 };
  //std::vector<int> res = Solution::twoSum(nums, 9);
  //std::vector<int> res = Solution::twoSum2(nums, 9);
  std::vector<int> res = Solution::twoSum3(nums, 9);
	
  for (auto i : res)
    std::cout << i << std::endl;

  return 0;
}





