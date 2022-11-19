class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int i=nums2.size()-1;
        stack<int> stk;
        unordered_map<int,int> mapp;
        while(i>=0){
            if(stk.empty()){
                // res[i]=-1;
                stk.push(nums2[i]);
                mapp[nums2[i]]=-1;
                i--;
            }
            else if(!stk.empty() && stk.top()<nums2[i]) stk.pop();
            else{
                // res[i]=stk.top();
                mapp[nums2[i]]=stk.top();
                stk.push(nums2[i]);
                i--;
            }
        }
        vector<int> res;
        for(auto it : nums1){
            res.push_back(mapp[it]);
        }
        return res;
        
    }
};