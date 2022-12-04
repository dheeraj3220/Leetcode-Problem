class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> que;
        que.push(start);
        vector<int> vis(arr.size(),0);
        vis[start]=1;
        while(!que.empty()){
            int curIndex=que.front();
            int i=curIndex;
            que.pop();
            if(arr[curIndex]==0) return true;
            if(i-arr[curIndex]>=0 && !vis[i-arr[curIndex]]){
                que.push(i-arr[curIndex]);
                vis[i-arr[curIndex]]=1;
            }
            if(i+arr[curIndex]<arr.size() && !vis[i+arr[curIndex]]){
                vis[i+arr[curIndex]]=1;
                que.push(i+arr[curIndex]);
            }
            
        }
        return false;
    }
};