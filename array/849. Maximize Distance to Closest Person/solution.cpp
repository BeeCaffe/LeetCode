/***********************************************************************************************************************
 * Created by caffe on 2019/11/24.
 * 849. Maximize Distance to Closest Person
 * In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty.

    There is at least one empty seat, and at least one person sitting.

    Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.

    Return that maximum distance to closest person.

    Example 1:

    Input: [1,0,0,0,1,0,1]
    Output: 2
    Explanation:
    If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
    If Alex sits in any other open seat, the closest person has distance 1.
    Thus, the maximum distance to the closest person is 2.

    Example 2:

    Input: [1,0,0,0]
    Output: 3
    Explanation:
    If Alex sits in the last seat, the closest person is 3 seats away.
    This is the maximum distance possible, so the answer is 3.

    Note:

        1 <= seats.length <= 20000
        seats contains only 0s or 1s, at least one 0, and at least one 1.
 **********************************************************************************************************************/
/**
 * solution 1 : 分析法
 * 对于每个没人座的位置，向左右两边寻找最近的人，将最近的距离作为该位置的距离。在所有距离中找到最大的那个并返回就可以了，同时
 * 需要注意的是对于最边上的两个位置需要特殊讨论
 * 时间复杂度：O（n）
 * 空间复杂度：O（1）
 */

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int pleft,pright;
        int ans=0;
        for(int i=0;i<seats.size();++i){
            if(seats[i]==0){
                int mid=i,pleft=i-1,pright=i+1;
                while(pleft>=0 && seats[pleft]==0) --pleft;
                while(pright<seats.size() && seats[pright]==0) ++pright;
                if(mid==0) ans=max(ans,pright-mid);
                else if(mid==seats.size()-1) ans=max(ans,mid-pleft);
                else{
                    int dist=min(mid-pleft,pright-mid);
                    ans=max(dist,ans);
                }
            }
        }
        return ans;
    }
};