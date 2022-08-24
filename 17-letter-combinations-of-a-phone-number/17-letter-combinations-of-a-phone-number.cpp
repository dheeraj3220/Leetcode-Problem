class Solution {
public:
    vector<string> s={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void helper(string digits,vector<string> &res,int index,string temp){
        if(index>=digits.size()){
            res.push_back(temp);
            return ;
        }
        int keynum=digits[index]-'0';
        for(int i=0;i<s[keynum].size();i++){
            temp.push_back(s[keynum][i]);
            helper(digits,res,index+1,temp);
            temp.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits=="") return res;
        string temp;
        helper(digits,res,0,temp);
        return res;
    }
};