//
// Created by Administrator on 2019/8/8.
//
#include <vector>
#include <map>
using namespace std;
/**
 * this solution utilized the stl map to solve this problem, because map's fundamental implement is
 * based on red-black tree,so it can meet the time limmit of Ologn.
 * 1.put the left part to map a
 * 2.put the right part to map b
 * 3.if target >= a's begin element, find it in a
 * 4.if not find it in b.
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        map<int,int> a,b;
        int i=0,sz=nums.size(),min=INT32_MIN;
        if(sz==0) return -1;
        for(;i<sz&&min<nums.at(i);i++){
            a.insert(pair<int,int>(nums.at(i),i));
            min=nums[i];
        }
        for(;i<sz;i++){
            b.insert(pair<int,int>(nums.at(i),i));
        }
        auto it=a.begin();
        if(target>=a.begin()->first){
            if((it=a.find(target))!=a.end()){
                return it->second;
            }else return -1;
        }else{
            if((it=b.find(target))!=b.end()){
                return it->second;
            }else return -1;
        }
        return -1;
    }
};
