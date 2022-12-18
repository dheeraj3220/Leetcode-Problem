class Solution {
public:
    int similarPairs(vector<string>& words) {
        
        int count=0;
        for(int i=0;i<words.size();i++){
            unordered_map<char,int> mapp;
            for(int j=0;j<words[i].size();j++) mapp[words[i][j]]=1;
            for(int j=i+1;j<words.size();j++){
                unordered_map<char,int> mappi;
                for(auto it : words[j]) mappi[it]=1;
                
                if(mapp==mappi) count++;
            }
        }
        return count;
    }
};