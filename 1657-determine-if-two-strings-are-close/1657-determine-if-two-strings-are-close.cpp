class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        int count1[26]={0},count2[26]={0};
        for(int i=0;i<word1.size();i++){
            count1[word1[i]-'a']++;
            count2[word2[i]-'a']++;
        }
        // unordered_map<int,int> mapp;
       
        for(int i=0;i<26;i++){
            if((count1[i]==0 || count2[i]==0) && count1[i]!=count2[i]) return false;
            // mapp[count1[i]]++;
        }
        sort(count1,count1+26);
        sort(count2,count2+26);
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i]) return false;
        }
        
        // for(int i=0;i<26;i++){
        //     if(mapp.count(count2[i])==1){ 
        //         mapp[count2[i]]--;
        //         if(mapp[count2[i]]==0) mapp.erase(count2[i]);
        //     }    
        // }
        return true;
    }
};