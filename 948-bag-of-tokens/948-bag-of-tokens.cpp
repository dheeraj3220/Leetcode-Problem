class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1,score=0;
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i];
                score++;
                i++;
            }
            else {
                if(power+tokens[j]>=tokens[i] && score!=0 && i!=j){
                    power+=tokens[j];
                    j--;
                    score--;
                }
                 else break;
            }
        }
        return score;
        
    }
};