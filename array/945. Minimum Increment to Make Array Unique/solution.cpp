/***********************************************************************************************************************
 * Created by caffe on 2019/11/26.
 * 945. Minimum Increment to Make Array Unique
 * Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.

    Return the least number of moves to make every value in A unique.

    Example 1:

    Input: [1,2,2]
    Output: 1
    Explanation:  After 1 move, the array could be [1, 2, 3].

    Example 2:

    Input: [3,2,1,2,1,7]
    Output: 6
    Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
    It can be shown with 5 or less moves that it is impossible for the array to have all unique values.

    Note:

        0 <= A.length <= 40000
        0 <= A[i] < 40000

 **********************************************************************************************************************/
/**
 * solution 1 : set 法
 * 时间复杂度：O（n）
 * 空间复杂u=度：O（n）
 */
 //Time Limit Exceed
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        unordered_set<int > hashset;
        int cnt=0;
        vector<int> count(40000);
        for(int num:A) count[num]++;
        for(int i=0;i<40000;++i){
            if(count[i]!=0){
                for(int j=0;j<count[i];++j){
                    int num=i;
                    while(hashset.find(num)!=hashset.end()){
                        num++;
                        cnt++;
                    }
                    hashset.insert(num);
                }
            }
        }
        return cnt;
    }
};
/**
 * solution 2 : count 法
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        vector<int> count(100000,0);
        for(int num:A) ++count[num];
        int taken=0,cnt=0;
        for(int i=0;i<100000;++i){
            if(count[i]>=2){
                taken+=count[i]-1;
                cnt-=i*(count[i]-1);
            }else if(taken>0 && count[i]==0){
                taken--;
                cnt+=i;
            }
        }
        return cnt;
    }
};