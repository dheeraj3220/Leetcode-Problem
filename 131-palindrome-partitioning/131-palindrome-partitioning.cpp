class Solution {
public:
    bool palin(string s,int i, int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void partitionHelper(string s,vector<vector<string>>&res,vector<string> ds,int index){
        if(index==s.size()){
            res.push_back(ds);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(!palin(s,index,i)) continue;
            ds.push_back(s.substr(index,i-index+1));
            partitionHelper(s,res,ds,i+1);
            ds.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ds;
        partitionHelper(s,res,ds,0);
        return res;
    }
};