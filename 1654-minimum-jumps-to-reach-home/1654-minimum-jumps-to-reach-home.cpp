// class Solution {
// public:
//     int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
//         queue<pair<int,pair<int,bool>>> que;
//         que.push({0,{0,true}}); //{steps, {postion,prevJump(true means backward false means forward)} 
//         vector<int>  vis(x+a+b,0);
//         vis[0]=1;
//         for(auto dug :  forbidden){
//             if(dug==x) return -1;
//             else vis[dug]=1;
//         }
//         while(!que.empty()){
//             auto it=que.front();
//             int steps=it.first;
//             int loc=it.second.first;
//             bool prevMove=it.second.second;
//             que.pop();
//             if(loc==x) return steps;
//             if(loc<=2000+a+b && !vis[loc+a]){
//                 que.push({steps+1,{loc+a,false}});
//                 vis[loc+a]=1;
//             }
//             if(!prevMove && loc-b>=0 && !vis[loc-b]){
//                 que.push({steps+1,{loc-b,true}});
//                 vis[loc-b]=1;
//             } 
//         }
//         return -1;        
//     }
// };



class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
      unordered_map<int, int> um;
      for(auto &pos: forbidden){  // Adding all the forbidden positions
        um[pos]++;
      }
      queue<pair<int, pair<int, bool>>> q;  
      q.push({0, {0, true}});
      while(!q.empty()){
        auto node = q.front();
        int currPos = node.first, ans = node.second.first;
        bool canGoBackwards = node.second.second;  
        q.pop();
        if(currPos == x) return ans;
        if(um.find(currPos) != um.end()) continue;  
        um[currPos]++;
        int forward = currPos + a, backward = currPos - b;
        if(canGoBackwards and backward >= 0){
          q.push({backward, {ans + 1, false}});
        }
        if(forward <= 2000 + a + b){    // 1 <= a, b, forbidden[i] <= 2000
          q.push({forward, {ans + 1, true}});
        }
      }
      return -1;
    }
};