//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Code here
        set<string> words;
        for(auto word : wordList) words.insert(word);
        if(words.count(endWord)==0) return 0;
        queue<pair<string,int>> que;
        que.push({beginWord,1});
        while(!que.empty()){
            string curWord=que.front().first; // taking the front word from que 
            int level=que.front().second;
            que.pop();
            for(int i=0;i<curWord.size();i++){
                for(int j='a';j<='z';j++){
                    string word=curWord;
                    word[i]=j;
                    if(word==endWord) return level+1;
                    if(words.count(word)){
                      que.push({word,level+1});
                      words.erase(word);  
                    } 
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends