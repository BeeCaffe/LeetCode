//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 1.采用动态规划算法
 *   当n=3的时候，有下面几种排列方式["123""132""213""231""312""321"]
 *   我们可以把第一个为1分为一组有“123”，“132”,同样把开头为2和3的分别分为一组，那么实际上对于n可以分为n！/(n-1)！=n组，
 *   每组的长度=(n-1)!，当给出k的时候，我们可以用(k-1)/(每组的长度)来确定其分在哪一组，对应的首元素就应该是组号对于位置处
 *   的元素。
 *   当第一个元素确定之后，那么我们可以同样解决n-1个数的排列问题，现在k就应该是上面一次的榆树，但是要加上1，也就是k=（k-1）/(n-1)! + 1
 *   如此递推就可以确定每一个元素。
 */
#include <string>
#include <vector>
using  namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> list;
        vector<int> res_vec;
        for(int i=0;i<n;i++){
            list.push_back(i+1);
        }
        int loops=n;
        for(int i=0;i<loops;i++){
            int loc=(k-1)/mul(n-1);
            res_vec.push_back(list[loc]);
            list.erase(list.begin()+loc);
            k=(k-1)%mul(n-1)+1;
            n--;
        }
        string res="";
        for(auto data:res_vec){
            res+=to_string(data);
        }
        return res;
    }
    int mul(int n){
        int res=1;
        for(int i=0;i<n;i++) res*=i+1;
        return res;
    }
};

int main(){
    int n=3,k=2;
    Solution::getPermutation(n,k);
    return 0;
}
