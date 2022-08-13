#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string str = countAndSay(n - 1);
        string ret;
        int index = 0, cnt = 0;
        char ch = str[0];
        while (index < str.size()) {
            while (index < str.size() && ch == str[index]){
                index++;
                cnt++;
            }
            ret += to_string(cnt);
            ret += to_string(ch - '0');
            cnt = 0;
            if (index < str.size()) {
                ch = str[index];
            }
        }
        return ret;
    }
};

//  for test
//  time: 100%, memory: 33.93%
int main()
{
    Solution sol;
    cout << sol.countAndSay(1);

    return 0;
}