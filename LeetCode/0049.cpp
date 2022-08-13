#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<string, vector<string>> mm;
        for (auto& s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mm[t].emplace_back(s);
        }

        for (auto it : mm) {
            ret.emplace_back(it.second);
        }
        return ret;
    }
};

//  for test
//  time: 100%, memory: 33.93%
int main()
{
    Solution sol;
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    //  res = {["bat"],["nat","tan"],["ate","eat","tea"]}

    auto vv = sol.groupAnagrams(strs);
    for (auto& v : vv){
        for (auto& s : v) {
            cout << s << ", ";
        }
        cout << endl;
    }

    return 0;
}