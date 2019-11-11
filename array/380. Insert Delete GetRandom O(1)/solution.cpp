/***********************************************************************************************************************
 * Created by caffe on 2019/11/6.
 * 380. Insert Delete GetRandom O(1)
 * Design a data structure that supports all following operations in average O(1) time.
    1)insert(val): Inserts an item val to the set if not already present.
    2)remove(val): Removes an item val from the set if present.
    3)getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
 **********************************************************************************************************************/
/**
 * solution1:unordered_map
 *      由于时间复杂度均为O（1），那么考虑用hash map来实现。具体的做法是将数据存储在一个Vector里面，将数组的对应的值和下标存储在一个hash
 *      set中，这样就能保证插入和删除都是O（1）的时间复杂度。
 * 时间复杂度：O（1）
 * 空间复杂度：O（n）
 */

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(find(val)) return false;
        data.push_back(val);
        valpos[val]=data.size()-1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!find(val)) return false;
        int _idx=valpos[val];
        int _val=data.back();
        data[_idx]=_val;
        valpos[_val]=_idx;
        valpos.erase(val);
        data.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return data[rand()%data.size()];
    }
private:
    unordered_map<int,int> valpos;
    vector<int> data;
    bool find(int val){
        return (valpos.find(val)!=valpos.end());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */