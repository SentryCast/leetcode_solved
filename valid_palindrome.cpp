// Transform string s to lower case, 
// leave only alphanumeric characters in it 
// and check if s is Valid Polidrome
#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <optional>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        transform(s.begin(), s.end(),
                  s.begin(),
                  [](unsigned char c)
                  {
                      return tolower(c);
                  });
        s.erase(remove_if(s.begin(), s.end(), [](auto c) -> bool
                          { return !isalnum(c); }),
                s.end());

        if (s.size() == 0 || s.size() == 1)
            return true;

        bool isEven = false;
        optional<size_t> mid = nullopt;
        if (s.size() % 2 == 0)
        {
            isEven = true;
            mid = s.size() / 2;
        }
        else
        {
            mid = s.size() / 2;
        }

        for (size_t i = 0; i < mid; i++)
        {
            if (s[i] != s[s.size() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string test1 = "Abc";   // false
    string test2 = "ABa";   // true
    string test3 = " ";     // true
    string test4 = "a";     // true
    string test5 = "abcF";  // false
    string test6 = "abcba"; // true

    Solution sol;
    cout << sol.isPalindrome(test1) << endl;
    cout << sol.isPalindrome(test2) << endl;
    cout << sol.isPalindrome(test3) << endl;
    cout << sol.isPalindrome(test4) << endl;
    cout << sol.isPalindrome(test5) << endl;
    cout << sol.isPalindrome(test6) << endl;
}
