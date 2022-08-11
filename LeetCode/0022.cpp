#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<string>& res, int n, string t = "", int lCnt = 0, int rCnt = 0) {
        //  任意时刻，右括号数量不能比左括号多，否则没有左括号与之匹配
        if (lCnt > n || rCnt > n || lCnt < rCnt) {
            return;
        }
        if (lCnt + rCnt == 2 * n) {
            res.emplace_back(t);
            return;
        }
        dfs(res, n, t + '(', lCnt + 1, rCnt);
        dfs(res, n, t + ')', lCnt, rCnt + 1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, n);
        return res;
    }
};

//  for test
//  time: 4ms(65.28%), memory: 14.8MB(19.26%)
int main()
{
    Solution sol;
    auto v = sol.generateParenthesis(3);
    for (auto& s : v) {
        cout << s << endl;
    }

    return 0;
}