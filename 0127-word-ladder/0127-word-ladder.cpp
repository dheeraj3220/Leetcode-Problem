class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for(auto word : wordList) words.insert(word);   //store the words to check wheather word exists or not 
        if(words.count(endWord)==0) return 0;
        queue<pair<string,int>> que;
        que.push({beginWord,1});                //push the begin word and start traversing through all possible words
        while(!que.empty()){
            string curWord=que.front().first; // taking the front word from que 
            int level=que.front().second;
            que.pop();
            for(int i=0;i<curWord.size();i++){       //channge the ith index of word with a-z and check wheather word exist or not
                for(int j='a';j<='z';j++){
                    string word=curWord;
                    word[i]=j;
                    if(word==endWord) return level+1; //increase the level as soon as u insert the word in queue
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