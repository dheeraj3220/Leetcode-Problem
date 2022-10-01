class Solution {
public:
    bool equalFrequency(string word) {

        unordered_map<int,int> mapp;
        for(auto s: word) mapp[s]++;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(auto i=mapp.begin();i!=mapp.end();i++){
            maxi=max(maxi,i->second);
            mini=min(mini,i->second);
        }
        if(maxi==1 && mini==1) return true;
        if(mapp.size()==1) return true;
        int maxC1=0,minC1=0;
         for(auto i=mapp.begin();i!=mapp.end();i++){
            if(maxi==i->second) maxC1++;
            if(mini==i->second) minC1++;
        }
        if(minC1==1 && maxC1*(maxi)==word.size()-mini && maxi-mini==1 ) return true;
        if(maxC1==1 && minC1*(mini)==word.size()-maxi && maxi-mini==1) return true;
        
        return false;
        
    }
};