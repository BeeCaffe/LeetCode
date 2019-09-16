//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 实际上二进制转格雷码是有公式的，i^(i>>1)，自己与自己右移一位进行异或，得到的就是它的格雷码。
 * 解码的过程是：左边第一位不变，从左边第二位开始，将每位与左边一位解码后的值异或作为该位解码的值。
 **/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        int maxNum=1<<n;
        for(size_t i=0;i<maxNum;++i){
            int grayCode=i^(i>>1);
            ret.push_back(grayCode);
        }
        return ret;
    }
};