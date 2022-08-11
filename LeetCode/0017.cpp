#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<char>> m {make_pair('2', vector<char>{'a','b','c'}),
    make_pair('3', vector<char>{'d','e','f'}), make_pair('4', vector<char>{'g','h','i'}),
    make_pair('5', vector<char>{'j','k','l'}), make_pair('6', vector<char>{'m','n','o'}),
    make_pair('7', vector<char>{'p','q','r', 's'}), make_pair('8', vector<char>{'t','u','v'}),
    make_pair('9', vector<char>{'w','x','y', 'z'})};

class Solution {
public:
    void dfs(vector<string>& res, const string& digits, string t, int index = 0) {
        if (index == digits.size()) {
            res.emplace_back(t);
            return;
        }
        
        const auto& v = m[digits[index]];
        for (auto& ch : v) {
            dfs(res, digits, t + ch, index + 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {return {};}
        vector<string> res;
        dfs(res, digits, "");
        return res;
    }
};

//  for test
//  time: 0ms(100%), memory: 6.4MB(33.93%)
int main()
{
    Solution sol;
    auto res = sol.letterCombinations("");
    for (auto& s : res) {
        cout << s << endl;
    }

    return 0;
}