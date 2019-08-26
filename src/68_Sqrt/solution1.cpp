//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 1.binary search
 *      deserve to notice that when x=INT_MAX, there may happens int overflow if mid is an integer.
 */
#include <climits>
class Solution {
public:
    static int mySqrt(int x) {
        if(x==1) return 1;
        if(x==0) return 0;
        int low=1,high=x;
        long long mid=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(x/mid==mid) return mid;
            else if(x/mid<mid) high=mid-1;
            else low=mid+1;
        }
        return high;
    }
};

int main(){
    Solution::mySqrt(INT_MAX);
    return 0;
}