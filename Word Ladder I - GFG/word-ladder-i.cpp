//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        string beginWord=startWord;
        string endWord=targetWord;
        set<string> s(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        s.erase(beginWord);
        while(q.size()>0)
        {
          auto str=q.front().first;
          int lvl =q.front().second;
          q.pop();
          if(str==endWord) return lvl;
          for(int i=0;i<str.size();i++)
          { char org=str[i];   // hat -> aat ->bat jb tk match nahi krta 
              for(int ch='a';ch<='z';ch++)
              {
                  str[i]=ch;
                  if(s.find(str)!=s.end())
                  {
                    s.erase(str);
                    q.push({str,lvl+1});
                  }
              }
              str[i]=org;
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