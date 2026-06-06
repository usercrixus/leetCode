#include <vector>
#include <algorithm>
#include <cstddef>
#include <iostream>

#define K 4

class Solution {
public:

    void twoSum(std::vector<int>& nums, std::vector<int>& tested, int target, std::size_t start, std::vector<std::vector<int>>& result)
    {
            std::size_t i = start;
            std::size_t j = nums.size() - 1;
            long long selectedSum = 0;
            for (int element : tested)
                selectedSum += element;
            while (i < j)
            {
                long long sum = selectedSum + nums[i] + nums[j];
                if (sum == target)
                {
                    std::vector<int> candidate = tested;
                    candidate.push_back(nums[i]);
                    candidate.push_back(nums[j]);
                    result.push_back(candidate);
                    ++i;
                    --j;
                    while (i < j && nums[i] == nums[i - 1])
                        ++i;
                    while (i < j && nums[j] == nums[j + 1])
                        --j;
                }
                else if (sum < target)
                    ++i;
                else
                    --j;
            }
    }

    void recur(std::vector<int>& nums, std::vector<int>& tested, int target, std::size_t start, std::size_t size, std::vector<std::vector<int>>& result)
    {
        if (tested.size() == size - 2)
        {
            twoSum(nums, tested, target, start, result);
        }
        else
        {
            std::size_t numbersNeeded = size - tested.size();
            for (std::size_t i = start; i + numbersNeeded <= nums.size(); ++i)
            {
                if (i > start && nums[i] == nums[i - 1])
                    continue;
                tested.push_back(nums[i]);
                recur(nums, tested, target, i + 1, size, result);
                tested.pop_back();
            }
        }
    }

    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
    {
        std::vector<std::vector<int>> result;
        if (nums.size() < K)
            return result;
        std::sort(nums.begin(), nums.end());
        std::vector<int> tested;
        recur(nums, tested, target, 0, K, result);
        return result;
    }
};

int main()
{
    std::vector<int> tested = {1,0,-1,0,-2,2};
    Solution s;
    std::vector<std::vector<int>> f = s.fourSum(tested, 0);
    for (std::size_t i = 0; i < f.size(); ++i)
    {
        for (std::size_t j = 0; j < f[i].size(); ++j)
            std::cout << f[i][j] << " ";
        std::cout << std::endl;
    }
}
