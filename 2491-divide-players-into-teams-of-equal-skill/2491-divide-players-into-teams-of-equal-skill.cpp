class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i=0,j=skill.size()-1;
        long long res=0;
        int Sum=skill[i]+skill[j];
        while(i<j){
            if(Sum!=skill[i]+skill[j]) return -1;
            res+=(skill[i]*skill[j]);
            i++;
            j--;
        }
        return res;
    }
};