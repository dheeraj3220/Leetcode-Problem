class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0,j=0;
        for(auto move : moves){
            if(move=='R') j++;
            else if(move=='L') j--;
            else if(move=='U') i--;
            else i++;
        }
        return i==0 && j==0;
    }
};