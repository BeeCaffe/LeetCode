/***********************************************************************************************************************
 * Created by caffe on 2019/11/12.
 * 611. Valid Triangle Number
 * Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

    Example 1:

    Input: [2,2,3,4]
    Output: 3
    Explanation:
    Valid combinations are:
    2,3,4 (using the first 2)
    2,3,4 (using the second 2)
    2,2,3

    Note:

        The length of the given array won't exceed 1000.
        The integers in the given array are in the range of [0, 1000].
 **********************************************************************************************************************/
/**
 * solution 1 ： 模式匹配
 * 使用深度优先搜索遍历出来所有的结果，然后依次判断是否符合三角形的条件。
 * 时间复杂度：
 * 空间复杂度：
 */
 //使用三层循环来做深度优先，此时的时间复杂度为O(n3),这个时候是无法AC的。
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res=0,sz=nums.size();
        if(sz<3) return 0;
        vector<int> edges;
        for(int i=0;i<sz;++i){
            for(int j=i+1;j<sz;++j){
                for(int k=j+1;k<sz;++k){
                    if(isTriangle(nums[i],nums[j],nums[k])) ++res;
                }
            }
        }
        return res;
    }
    bool isTriangle(int x,int y,int z){
        if(x+y>z && x+z>y &&y+z>x &&abs(x-y)<z&&abs(x-z)<y&&abs(y-z)<x) return true;
        return false;
    }
};
/**
 * solution 2： 二分查找
 * 这里要注意找到三角形三条边的一个不等式关系，假设我们将所有数据进行了一个排序，然后依次从中找出3个数a，b，c，那么必然有a<b<c，此时，由于c
 * 始终是最大的，所以a+c>b,b+c>a，这时需要判断的条件仅仅是a+b>c。因此我们的做法是，先对数组进行一个排序，然后从中依次找到两个，第三个数就用
 * 二分查找去查找，这样一来时间复杂度就缩减到了O（n2logn）
 * 时间复杂度：O（n2logn）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        int sz=nums.size();
        int res=0;
        for(int i=0;i<sz;++i){
            int k=i+2;
            for(int j=i+1;j<sz&&nums[i]!=0;++j){
                k=binarySearch(nums,k,sz-1,nums[i]+nums[j]);
                res+=k-j-1;
            }
        }
        return res;
    }

    int binarySearch(vector<int> &nums,int left,int right,int key){
        while(left<=right && right<nums.size()){
            int mid=left+(right-left)/2;
            if(nums[mid]>=key)
                right=mid-1;
            else left=mid+1;
        }
        return left;
    }
};
/**
 * solution 3 ： 线性扫描
 * 前面的思路和解法二一样，不同的地方在于查找第三个数的时候采用的是直接向后扫描而不是二分查找。
 * 时间复杂度：O（n2）（因为第三个while循环只查找了一部分）
 * 空间复杂度：O（logn）（快速排序消耗掉的内存）
 */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        int sz=nums.size();
        int res=0;
        for(int i=0;i<sz;++i){
            int k=i+2;
            for(int j=i+1;j<sz&&nums[i]!=0;++j){
                while(k<sz&&nums[i]+nums[j]>nums[k]) ++k;
                res+=k-j-1;
            }
        }
        return res;
    }
};