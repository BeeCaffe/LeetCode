/***********************************************************************************************************************
 * Created by caffe on 2019/11/11.
 * 605. Can Place Flowers
 * Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

    Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

    Example 1:

    Input: flowerbed = [1,0,0,0,1], n = 1
    Output: True

    Example 2:

    Input: flowerbed = [1,0,0,0,1], n = 2
    Output: False

    Note:

        The input array won't violate no-adjacent-flowers rule.
        The input array size is in the range of [1, 20000].
        n is a non-negative integer which won't exceed the input array size.
 **********************************************************************************************************************/
/**
 * solution 1 : 分析法
 * 对于一个地方能不能栽花只需要判断左右两边是否为0就可以了，遍历一遍，数出可以栽花的地方，然后同n比较就可以得出结果
 * 但是，需要注意的是，有很多边界条件需要判断。
 * 时间复杂度：O(n)
 * 空间复杂度：O（1）
 */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        if(flowerbed.empty()) return false;
        if(flowerbed.size()==1){
            if(flowerbed[0]==0) return n<=1;
            else return false;
        }
        int count=0;
        int sz=flowerbed.size();
        for(int i=0;i<sz;++i){
            if(i==0){
                if(flowerbed[i]==0 && flowerbed[i+1]==0){
                    ++count;
                    flowerbed[i]=1;
                }
            }else if(i==sz-1){
                if(flowerbed[sz-1]==0 && flowerbed[sz-2]==0){
                    ++count;
                    flowerbed[sz-1]=1;
                }
                continue;
            }else{
                if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
                    ++count;
                    flowerbed[i]=1;
                }
            }
        }
        return n<=count;
    }
};