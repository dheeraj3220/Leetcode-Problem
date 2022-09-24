class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> mapp,bannedMapp;
        for(auto iter : banned) bannedMapp[iter];
        int i=0;
        string temp="";
        while(i<paragraph.size()){
            if(paragraph[i]==' ' || paragraph[i]=='!' || paragraph[i]=='?' || paragraph[i]==39 || paragraph[i]==','  || paragraph[i]==';' || paragraph[i]=='.' ){
                if(bannedMapp.count(temp)==0 && temp!="") mapp[temp]++;
                temp.clear();
            }
            else{
                temp+=tolower(paragraph[i]);
            }
            i++;
        }
        if(bannedMapp.count(temp)==0 && temp!="") mapp[temp]++;
        int maxi=INT_MIN;
        string res;
        for(auto i=mapp.begin();i!=mapp.end();i++){
            if(maxi<i->second){
                maxi=i->second;
                res=i->first;
            }
        }
        return res;
        
    }
};