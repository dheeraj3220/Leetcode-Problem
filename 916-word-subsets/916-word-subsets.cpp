class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> main,temp,word1Substr;
        vector<string> res;
        for(auto subString: words2){
            for(int i=0;i<subString.size();i++){
                temp[subString[i]]++;
            }
            for(auto iter=temp.begin();iter!=temp.end();iter++){
                main[iter->first]=max(main[iter->first],iter->second);
            }
            temp.clear();
        }
        for(auto subString: words1){
            for(int i=0;i<subString.size();i++){
                word1Substr[subString[i]]++;
            }
            int flag=0;
            for(auto iter=main.begin();iter!=main.end();iter++){
                if(word1Substr.count(iter->first)==0 || word1Substr[iter->first]<main[iter->first]) {
                    flag=0;
                    break;
                }
                flag=1;
            }
            if(flag==1) res.push_back(subString);
            word1Substr.clear();
        }
        return res;
    }
};