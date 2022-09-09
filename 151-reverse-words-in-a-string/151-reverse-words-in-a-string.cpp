class Solution {
public:
    string reverseWords(string s) {
        int j=s.size()-1;
        while(s[j]==' ')j--;
        string res="";
        int i=0,charCount=0;
        while(i<=j){
            if(s[i]==' ' && charCount==0) i++;
            else if(s[i]==' ' && charCount==1) {
                res+=s[i++];
                charCount=0;
            }
            else{
                res+=s[i++];
                charCount=1;
            }
        }
        reverse(res.begin(),res.end());
        int start=0;
        for(int i=0;i<=res.size();i++){
            int j;
            if(res[i]==' '|| res[i]=='\0'){
                j=i-1;
                while(start<j) swap(res[start++],res[j--]);
                while(res[i]==' ') i++;
                start=i;
            }
        }
        return res;
    }
};