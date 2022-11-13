//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,start});
        vector<int> mul(99999,1e9);
        while(!pq.empty()){
            auto it=pq.top();
            int steps=it.first;
            int curNum=it.second;
            if(curNum==end) return steps;
            pq.pop();
            for(auto num : arr){
                int digit=(curNum*num)%100000;
                if(mul[digit]>steps+1){
                    mul[digit]=steps+1;
                    pq.push({steps+1,digit});
                }
            }
        }
        return mul[end]==1e9?-1:mul[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends