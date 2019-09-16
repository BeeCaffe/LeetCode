//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0) return vector<int>(1,0);
        vector<string> retStr;
        help(retStr,n-1);
        vector<int> ret;
        for(auto str:retStr){
            int temp=0,pow=1;
            for(int i=str.size()-1;i>=0;i--){
                temp+=(str[i]-'0')*pow;
                pow=pow<<1;
            }
            ret.push_back(temp);
        }
        return ret;
    }
    void help(vector<string>& retStr,int n){
        if(n==0){
            retStr.push_back("0");
            retStr.push_back("1");
            return;
        }
        help(retStr,n-1);
        vector<string> tempStr(retStr);
        for(size_t i=0;i<retStr.size();++i){
            retStr[i]="0"+retStr[i];
        }
        for(int i=tempStr.size()-1;i>=0;i--){
            retStr.push_back("1"+tempStr[i]);
        }
    }
};