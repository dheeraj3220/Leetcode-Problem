class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,long> mapp;
        for(auto it : s) mapp[it]++;
        priority_queue<pair<long,char>> pq;
        for(auto it=mapp.begin();it!=mapp.end();it++){
            pq.push(make_pair(it->second,it->first));
        }
        string res;
        while(!pq.empty()){
            // map<long,char> mappi;
            auto it=pq.top();
            // while(pq.size() && t==pq.top().first){
            //     char cur=pq.top().second;
                // pq.pop();
            //     mappi[cur]=t;
            // }
            // while(mappi.size()){
                // auto it=mappi.begin();
                while(it.first--) res.push_back(it.second);
            pq.pop();
                // mappi.erase(mappi.begin());
            // }
        }
        return res;
    }
};