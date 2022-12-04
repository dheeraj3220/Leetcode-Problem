class Solution {
public:
    bool isCircularSentence(string str) {
       int size=str.size() ;
        if(str[size-1]!=str[0]) return false;
        for(int i=0;i<size;i++){
            while(i<size && str[i]!=' ') i++;
            if(i<size && str[i-1]!=str[i+1]) return false;
        }
        return true;
    }
};