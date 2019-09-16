//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 1。large data computation
 *      this problem is very simple,travels the vector form the end to the begin ,add one in the last place,
 *      put sum%10 into previous location and use sum/10 plus next location's number.In the end, if leave data
 *      is bigger than 1, then insert this data into first location of vector.
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int move=1;
        int sz=digits.size();
        for(int i=sz-1;i>=0;i--){
            int sum=digits[i]+move;
            digits[i]=sum%10;
            move=sum/10;
        }
        if(move>0) digits.insert(digits.begin(),move);
        return digits;
    }
};