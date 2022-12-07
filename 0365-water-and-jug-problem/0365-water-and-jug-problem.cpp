class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int x=jug1Capacity,y=jug2Capacity,z=x+y;
        int steps[]={x,y,-x,-y};
        queue<int> que;
        que.push(0);
        vector<int> vis(z+1,0);
        vis[0]=1;
        while(!que.empty()){
            int node=que.front();
            que.pop();
            if(node==targetCapacity) return true;
            for(int i=0;i<4;i++){
                int newNode=node+steps[i];
                if(newNode>=0 && newNode<=z && !vis[newNode]) {
                    que.push(newNode);
                    vis[newNode]=1;
                }
            }
        }
        return false;
    }
};