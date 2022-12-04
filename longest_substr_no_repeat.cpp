// Given a string s, find the length of the longest substring without repeating characters.
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<string> substrs;
        set<char> curr_chars;

        string curr_str;
        size_t curr_i = 0;
        bool init = false;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (curr_chars.insert(s[i]).second)
            {
                curr_str.push_back(s[i]);
                if (!init)
                {
                    curr_i = i;
                    init = true;
                }
            }
            else
            {
                substrs.push_back(curr_str);
                curr_chars = {};
                curr_str = {};
                init = false;
                i = curr_i;
            }
        }
        if (curr_str.size())
        {
            substrs.push_back(curr_str);
        }

        auto it = max_element(substrs.begin(), substrs.end(), [](string lhs, string rhs)
                              { return lhs.size() < rhs.size(); });
        if (it == substrs.end())
        {
            return 0;
        }
        return it->size();
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abc") << endl;
}