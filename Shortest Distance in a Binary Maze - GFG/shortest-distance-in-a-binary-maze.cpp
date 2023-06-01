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
       #define pi pair<int,int>
      //  int dis[n][m];
      //  memset(dis,INT16_MAX,sizeof(dis));
       vector<vector<int>>dis(n,vector<int>(m,1e8));
       dis[source.first][source.second]=0;
      //  cout<<dis[destination.first][destination.second];
       priority_queue<pair<int,pi>, vector<pair<int,pi>>, greater<pair<int,pi>>>q;
       q.push({dis[source.first][source.second],source});
       while ((q.size()))
       {
        int tr=q.top().second.first;
        int tc=q.top().second.second;
        q.pop();
          for(int i=0;i<4;i++)
          {
              int nr=tr+dr[i];
              int nc=tc+dc[i];
              if(nc>=0 and nc<m and nr>=0 and nr<n)
              {

                if(grid[nr][nc]==1 and dis[nr][nc]>dis[tr][tc]+1)
                {
                  dis[nr][nc]=dis[tr][tc]+1;   //relaxing of edge 
                  q.push({dis[nr][nc],{nr,nc}});
                }
              }
          }
       }
       if(dis[destination.first][destination.second]==1e8)
       {
       return -1;
       }
       else
       {
        return dis[destination.first][destination.second];
       }
      
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