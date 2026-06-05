#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
class Solution {
public:
	std::vector<std::pair<int, int>> getdata(std::vector<int>& nums)
	{
		std::vector<std::pair<int, int>> res;
		for (int i = 0; i < nums.size(); i++)
			res.push_back(std::pair(nums[i], i));
		std::sort(res.begin(), res.end());
		return res;
	}

    std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<std::pair<int, int>> data = getdata(nums);
        int i = 0;
        int j = nums.size() - 1;
        while (i != j)
        {
            int res = data[i].first + data[j].first;
            if (res == target)
                return {data[i].second, data[j].second};
            if (res > target)
                j--;
            else
                i++;
        }
		return {};
    }
};

int main()
{
	std::vector<int> nums = {2, 7, 11, 15};
	int target = 9;
	Solution solution;
	std::vector<int> result = solution.twoSum(nums, target);
	if (result.size() == 2)
		std::cout << result[0] << " " << result[1] << std::endl;
	else
		std::cout << "No solution found" << std::endl;
	return 0;
}
