//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
 int dr[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dc[8] = {0, 1, 0, -1, -1, 1, -1, 1};

   int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {
          int n=grid.size();
          int m=grid[0].size();
          queue<pair<pair<int,int>,int>>q;   //{ { i,j} dis}
          q.push({source,0});
          int vis[n][m];
          int y=INT16_MAX;
          vis[source.first][source.second]=1;
          memset(vis,0,sizeof(vis));
          while(q.size())
          {
            // cout<<"g"<<endl;
            int tr=q.front().first.first;
            int tc=q.front().first.second;
            int dis=q.front().second;
            
           if (tr == destination.first && tc == destination.second) {
            y = min(y, dis);
            return y;
        }
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=tr+dr[i];
                int nc=tc+dc[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m)
                {
                  if(grid[nr][nc]==1 and vis[nr][nc]==0)
                  {
                      vis[nr][nc]=1;
                    q.push({{nr,nc},dis+1});
                  }
                }
            }
          }
          if(y==INT16_MAX) return -1;
          // deb(y);
return y;        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends