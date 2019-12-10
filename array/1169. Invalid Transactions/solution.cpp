/***********************************************************************************************************************
 * Created by caffe on 2019/12/4.
 * 1169. Invalid Transactions
 * A transaction is possibly invalid if:

        the amount exceeds $1000, or;
        if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.

    Each transaction string transactions[i] consists of comma separated values representing the name, time (in minutes), amount, and city of the transaction.

    Given a list of transactions, return a list of transactions that are possibly invalid.  You may return the answer in any order.

    Example 1:

    Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
    Output: ["alice,20,800,mtv","alice,50,100,beijing"]
    Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.

    Example 2:

    Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
    Output: ["alice,50,1200,mtv"]

    Example 3:

    Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
    Output: ["bob,50,1200,mtv"]

    Constraints:

        transactions.length <= 1000
        Each transactions[i] takes the form "{name},{time},{amount},{city}"
        Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
        Each {time} consist of digits, and represent an integer between 0 and 1000.
        Each {amount} consist of digits, and represent an integer between 0 and 2000.
 **********************************************************************************************************************/
/**
 * solution 1 : map method
 * the idea of this solution is very simply,
 * first of all, we decleare a struct Msg to store the message of a transaction.
 * secondly, for every transaction restore it message to a struct Msg
 * thirdly, we save pair{name,Msg} into a hash map
 * then, we travel all transactions, and insert all Msg into hashmap,if we find invalid Msg,put it
 * into answers.
 * time complexity : O(nm)
 * space complexity : O(n)
 */
class Solution {
public:
    struct Msg{
        string trans;
        string name;
        int time;
        int amount;
        string city;
        bool is_pushed;
    };
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> ans;
        unordered_map<string,vector<struct Msg>> mp;
        for(string trans:transactions){
            struct Msg tmp;
            getMsg(trans,tmp);
            string name=tmp.name;
            if(tmp.amount>1000){
                if(!tmp.is_pushed) {ans.push_back(tmp.trans);tmp.is_pushed=true;}
            }
            for(auto iter=mp[name].begin();iter<mp[name].end();++iter){
                if(iter->city!=tmp.city&&abs(iter->time-tmp.time)<=60) {
                    if(!tmp.is_pushed){ans.push_back(tmp.trans);tmp.is_pushed=true;}
                    if(!iter->is_pushed){ans.push_back(iter->trans);iter->is_pushed=true;}
                }
            }
            mp[name].push_back(tmp);
        }
        return ans;
    }

    void getMsg(const string &trans,struct Msg &msg){
        int lastindex[3];
        int idx=0;
        for(int i=0;i<trans.size();++i){
            if(trans[i]==',') lastindex[idx++]=i;
        }
        msg.trans=trans;
        msg.name = trans.substr(0,lastindex[0]-1);
        msg.time = atol(trans.substr(lastindex[0]+1,lastindex[1]-lastindex[0]-1).c_str());
        msg.amount = atol(trans.substr(lastindex[1]+1,lastindex[2]-lastindex[1]-1).c_str());
        msg.city = trans.substr(lastindex[2]+1);
        msg.is_pushed=false;
    }
};