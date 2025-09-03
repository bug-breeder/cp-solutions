// beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog","hit","cog"] 

class Solution {
public:
    vector<vector<int>> adj;

    void buildAdjList(vector<string>& wordList) {
        adj.resize(wordList.size());

        auto dist = [&](string& s, string& t) {
            int result = 0;
            for(int i = 0; i < s.size(); i++) {
                if (s[i] != t[i]) {
                    result++;
                }
            }
            return result;
        };

        for(int i = 0; i < wordList.size(); i++) {
            for(int j = i+1; j < wordList.size(); j++) {
                if (dist(wordList[i],wordList[j]) == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }

    int BFSDist(vector<string>& wordList, int source, int dest) {
        queue<int> qu;
        vector<int> dist(wordList.size(), wordList.size() + 1);
        dist[source] = 1;
        qu.push(source);

        while (qu.size()) {
            int curNode = qu.front();
            qu.pop();

            for(auto &adjNode: adj[curNode]) {
                if (dist[adjNode] != wordList.size() + 1) continue;

                dist[adjNode] = dist[curNode] + 1;
                qu.push(adjNode);
                if (adjNode == dest) break;
            }
        }

        return dist[dest] < wordList.size() + 1?  dist[dest] : 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        
        buildAdjList(wordList);
        
        int dest = -1;
        for(int i = 0 ; i < wordList.size() - 1; i++) {
            if (wordList[i] == endWord) {
                dest = i;
                break;
            }
        }

        if (dest == -1) return 0;
        return BFSDist(wordList, wordList.size() - 1, dest);
    }
};