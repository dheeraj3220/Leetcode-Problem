class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustTo(n+1,0);
        vector<int> trustedBy(n+1,0);
        for(auto it : trust){
            trustTo[it[0]]++;
            trustedBy[it[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(trustTo[i]==0 && trustedBy[i]==n-1) return i;
        }
        return -1;
    }
};