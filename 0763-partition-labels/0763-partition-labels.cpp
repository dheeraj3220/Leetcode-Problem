class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> index(26,0);
        for(int i=0;i<s.size();i++){
            index[s[i]-'a']=i;
        }
        int i=0,j=0;
        vector<int> res;
        int count=0;
        while(i<s.size()){
            if(i==j && index[s[i]-'a']<=j){
                res.push_back(count+1);
                count=0;
                i++;
                j++;
                continue;
            }
            j=max(index[s[i]-'a'],j);
            count++;
            i++;
        }
        // if(count==1) res.push_back(1);
        return res;
    }
};