#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<string> result;

        int left = 0;
        int right = 0;
        std::queue<std::tuple<int,int,string>> q;
        q.push({left, right, ""});
        while(!q.empty()) {
            int l = std::get<0>(q.front());
            int r = std::get<1>(q.front());
            string s = std::get<2>(q.front());
            q.pop();
            if(s.length() == 2 * n) {
                result.push_back(s);
            }
            if(l < n) {
                string ss = s + "(";
                q.push({l + 1, r, ss});
            }
            if(r < l) {
                string ss = s + ")";
                q.push({l, r + 1, ss});
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    std::vector<string> res = s.generateParenthesis(4);
    for(auto& i : res) {
        std::cout << i << std::endl;
    }

}