//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 1.big data computation
 *      this problem is very simple as well.the time complexity is O(n).
 */
class Solution {
public:
    string addBinary(string a, string b) {
        string l_str=a.size()>b.size() ? a:b;
        string s_str=a.size()>b.size() ? b:a;
        string res="";
        int remain=0,sum=0;
        for(int i=(l_str.size()-1),j=(s_str.size()-1);i>=0;i--,j--){
            if(j>=0){
                sum=remain+(l_str[i]-'0')+(s_str[j]-'0');
                res=to_string(sum%2)+res;
                remain=sum/2;
            }else{
                sum=remain+(l_str[i]-'0');
                res=to_string(sum%2)+res;
                remain=sum/2;
            }
        }
        if(remain>0) res='1'+res;
        return res;
    }
};