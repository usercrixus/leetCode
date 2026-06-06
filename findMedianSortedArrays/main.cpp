#include <vector>
#include <iostream>
#include <cmath>
class Solution {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		int i = 0;
		int j = 0;
		int current = 0;
		int previous = 0;
		int count = nums1.size() + nums2.size();
		for (int k = 0; k <= count / 2; k++)
		{
			previous = current;
			if (i < nums1.size() && (j >= nums2.size() || nums1[i] <= nums2[j]))
				current = nums1[i++];
			else
				current = nums2[j++];
		}
		if (count % 2 == 0)
			return (current + previous) / 2.0;
		return current;
	}
};

int main()
{
	std::vector<int> one = {1,3};
	std::vector<int> two = {2,4};
	Solution s;
	double r = s.findMedianSortedArrays(one, two);
	std::cout << r << std::endl;
	return 0;
}
