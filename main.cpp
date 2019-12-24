#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
    static string convertToTitle(int n) {
        if(n==0) return "";
        string ans="";
        int tmp;
        string str=" ";
        while(n>0){
            tmp = n%26;
            if(tmp==0){
                str[0]='A'+25;
                ans += str;
            }else{
                str[0]='A'+n%26-1;
                ans += str;
            }
            n/=26;
        }
        return ans;
    }
};
int main()
{
    string  s = "123";
    string s1="456";
    cout<<Solution::convertToTitle(701)<<endl;
    return 0;
}