class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        std::string str=countAndSay(n-1);
        int count=1,len=str.size();
        std::string res="";
        for(size_t i=0;i<len;i++){
            if(str[i]==str[i+1]) count++;    
            else{
                res+=std::to_string(count)+str[i];
                count=1;
            }
        }
        return res;
    }
};
