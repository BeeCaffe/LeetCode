/***********************************************************************************************************************
 * Author: BeeCaffe.
 * GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
 *
***********************************************************************************************************************/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size()>12) return res;
        for(int i=0;i<s.size();++i){
            for(int j=i+1;j<s.size();++j){
                for(int k=j+1;k<s.size();++k){
                    string ip1=s.substr(0,i+1);
                    string ip2=s.substr(i+1,j-i);
                    string ip3=s.substr(j+1,k-j);
                    string ip4=s.substr(k+1);
                    if(check(ip1)&&check(ip2)&&check(ip3)&&check(ip4)){
                        string ip=ip1+"."+ip2+"."+ip3+"."+ip4;
                        res.push_back(ip);
                    }
                }
            }
        }
        return res;
    }
    bool check(const string& ip){
        long value=atol(ip.c_str());
        if(ip.size()==0) return false;
        if(ip[0]=='0'){
            return ip.size()==1;
        }else{
            if(value<=255) return true;
            else return false;
        }
    }
};