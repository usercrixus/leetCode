#include <string>
#include <iostream>

class Solution {
public:
    std::string getPalindrome(const std::string &s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    std::string longestPalindrome(std::string s) {
        std::string res = "";
        int i = 0;
        while (i < s.length())
        {
            std::string odd = getPalindrome(s, i, i);
            std::string even = getPalindrome(s, i, i + 1);

            if (odd.length() > res.length())
                res = odd;
            if (even.length() > res.length())
                res = even;
            i++;
        }
        return res;
    }
};

int main()
{
    std::string test = "babad";
    Solution s;
    std::cout << s.longestPalindrome(test) << std::endl;
}
