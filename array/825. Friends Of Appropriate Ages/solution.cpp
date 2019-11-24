/***********************************************************************************************************************
 * Created by caffe on 2019/11/24.
 * 825. Friends Of Appropriate Ages
 * Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person.

    Person A will NOT friend request person B (B != A) if any of the following conditions are true:

        age[B] <= 0.5 * age[A] + 7
        age[B] > age[A]
        age[B] > 100 && age[A] < 100

    Otherwise, A will friend request B.

    Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.

    How many total friend requests are made?

    Example 1:

    Input: [16,16]
    Output: 2
    Explanation: 2 people friend request each other.

    Example 2:

    Input: [16,17,18]
    Output: 2
    Explanation: Friend requests are made 17 -> 16, 18 -> 17.

    Example 3:

    Input: [20,30,100,110,120]
    Output:
    Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.



    Notes:

        1 <= ages.length <= 20000.
        1 <= ages[i] <= 120.
 **********************************************************************************************************************/
/**
 * error solution 1 : two pointer
 * time complexity : O(n2)
 * space complexity : O(1)
 */
 //Time Limit Exceed
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        if(ages.size()==1) return 0;
        int ans=0;
        for(int i=0;i<ages.size();++i){
            for(int j=i+1;j<ages.size();++j){
                int A=ages[i],B=ages[j];
                if(B<=0.5*A+7 || B>A || (B>100&&A<100)){}
                else ++ans;
                B=ages[i];A=ages[j];
                if(B<=0.5*A+7 || B>A || (B>100&&A<100)){}
                else ++ans;
            }
        }
        return ans;
    }
};
/**
 * solution 1 : two pointer
 * 由于年龄设置的最大为120岁，而数组可能最大的尺寸有2000个，因此如果我们直接组合每两个人的话可能造成时间复杂度过高，无法AC。
 * 因此，这里采取的办法是考虑两个年龄的人能否组合成朋友。注意的是，当年龄相同人数大于2时，它们能成为朋友的对数是N（N-1）对。
 * O(120^2)
 * O(1)
 */
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        if(ages.size()==1) return 0;
        int ans=0;
        vector<int> age_arr(121,0);
        for(int age:ages) age_arr[age]++;
        for(int i=1;i<121;++i){
            for(int j=1;j<121;++j){
                if(i==j||age_arr[i]==0||age_arr[j]==0) continue;
                int A=i,B=j;
                if(B<=0.5*A+7 || B>A || (B>100&&A<100)){}
                else{
                    ans+=age_arr[A]*age_arr[B];
                }
            }
        }
        for(int i=1;i<121;++i){
            if(age_arr[i]<2) continue;
            int A=i,B=i;
            if(B<=0.5*A+7 || B>A || (B>100&&A<100)){}
            else ans+=age_arr[i]*(age_arr[i]-1);
        }
        return ans;
    }
};