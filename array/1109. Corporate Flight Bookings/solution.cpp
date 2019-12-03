/***********************************************************************************************************************
 * Created by caffe on 2019/12/3.
 * 1109. Corporate Flight Bookings
 * There are n flights, and they are labeled from 1 to n.

We have a list of flight bookings.  The i-th booking bookings[i] = [i, j, k] means that we booked k seats from flights labeled i to j inclusive.

Return an array answer of length n, representing the number of seats booked on each flight in order of their label.

Example 1:

Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
Output: [10,55,45,25,25]

Constraints:

    1 <= bookings.length <= 20000
    1 <= bookings[i][0] <= bookings[i][1] <= n <= 20000
    1 <= bookings[i][2] <= 10000
 **********************************************************************************************************************/
/**
 * solution 1 : analysis
 * time complexity : O(nm)
 * space complexity : O(n)
 */
 //Time Limit Exceed
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(vector<int> book:bookings){
            int s=book[0],e=book[1],k=book[2];
            for(int i=s;i<=e;++i) if(i-1<n) ans[i-1]+=k;
        }
        return ans;
    }
};
/**
 * solution 2 ： 区间标记法
 * 没太懂
 * 时间复杂度 ： O（n+m）
 * 空间复杂度 ： O（n）
 */
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(vector<int> book:bookings){
            int l=book[0],r=book[1],k=book[2];
            ans[l-1]+=k;
            if(r<n) ans[r]-=k;
        }
        for(int i=1;i<n;++i) ans[i]+=ans[i-1];
        return ans;
    }
};