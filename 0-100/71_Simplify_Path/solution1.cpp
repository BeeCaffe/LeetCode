//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 1. stack
 *      using a stack to save the path.
 */
class Solution {
public:
    string simplifyPath(string path) {
        std::stack<string> mystack;
        int sz=path.size();
        for(int i=0;i<sz;){
            while(i<sz&&path[i]=='/') ++i;
            string str="";
            while(i<sz&&path[i]!='/'){
                str+=path[i++];
            }
            if(".."==str&&!mystack.empty()){
                mystack.pop();
            }else if(str!="" && str!=".." && str!="."){
                mystack.push(str);
            }
        }
        string res="";
        if(mystack.empty()) return "/";
        while(!mystack.empty()){
            res="/"+mystack.top()+res;
            mystack.pop();
        }
        return res;
    }
};