//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countMinOperations(int arr[], int n) {
     int value=0;
      int i=0;
      int steps=0;
        while(value!=n){
          value=0;
           for(i=0;i<n;i++){
               
               if(arr[i]%2!=0){
                steps+=1;
                arr[i]-=1;
              }
               if(arr[i]==0){
                  value++;
              }
            }
            for(i=0;i<n;i++){
                arr[i]=arr[i]/2;
            }
             steps++;
        }
        return steps-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countMinOperations(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends