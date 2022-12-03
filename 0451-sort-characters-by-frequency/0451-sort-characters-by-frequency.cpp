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
                auto it=pq.top();
                while(it.first--) res+=it.second;
                pq.pop();
        }
        return res;
    }
};