class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
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