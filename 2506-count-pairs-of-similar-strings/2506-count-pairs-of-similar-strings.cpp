class Solution {
public:
    int similarPairs(vector<string>& words) {
        
        int count=0;
        for(int i=0;i<words.size();i++){
            unordered_map<char,int> mapp;
            for(int j=0;j<words[i].size();j++) mapp[words[i][j]]++;
            for(int j=i+1;j<words.size();j++){
                unordered_map<char,int> mappi;
                for(auto it : words[j]) mappi[it]++;
                bool flag=true;
                for(char ch ='a';ch<='z';ch++){
                    if(mapp.count(ch)==1 && mappi.count(ch)==0 || mapp.count(ch)==0 && mappi.count(ch)==1){
                        flag=false;
                        break;
                    }
                };
                if(flag) count++;
            }
        }
        return count;
    }
};