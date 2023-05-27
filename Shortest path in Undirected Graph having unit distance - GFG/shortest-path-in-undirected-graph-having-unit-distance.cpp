//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>dis(N,1e9);
        dis[src]=0;
        vector<int> adj[N];
        queue<pair<int,int>>q;
        int vis[N];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<M;i++)
        {
            for(auto c:adj)
            {
                adj[edges[i][0]].push_back(edges[i][1]);
                 adj[edges[i][1]].push_back(edges[i][0]);
            }
        }

        // for(int i=0;i<N;i++)
        // {
        //      if(!vis[i])
        //      {
        //         q.push({i,0});
        //      }   
        // }


        q.push({src,0});
        while(q.size()>0)
        {
            int node=q.front().first;   //node 
            int wght=q.front().second;   //wght
            q.pop();
            for(auto c:adj[node])
            {
                if(dis[c]>dis[node]+1)
                {
                    dis[c]=dis[node]+1;
                    q.push({c,dis[c]});
                }
            }
        }
        for(int i=0;i<N;i++) if(dis[i]==1e9) dis[i]=-1;
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends