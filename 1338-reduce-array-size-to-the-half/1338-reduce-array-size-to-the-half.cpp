class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int count=0;
        unordered_map<int,int> mapp;
        for(auto iter : arr)  mapp[iter]++;
        priority_queue<int> pq;
        for(auto i=mapp.begin();i!=mapp.end();i++) pq.push(i->second);
        while(!pq.empty()){
            count+=pq.top();
            pq.pop();
            if(count>=arr.size()/2) break;
        }
        return mapp.size()-pq.size();
    }
};