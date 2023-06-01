//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
      vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        #define pi pair<int,int>
        vector< pair <int,int> > adj[n+1];   //{[ u, v, wght] , [ u , v, wght2  ] } 
        for(int i=0;i<m;i++)
        {
          int u=edges[i][0];    //u
          int v=edges[i][1];
          int wght=edges[i][2];
          adj[u].push_back({v,wght});
          adj[v].push_back({u,wght});
        }
       vector<int>dis(n+1,1e8);
        dis[1]=0;
        int part[n+1];
        for(int i=0;i<=n;i++)part[i]=i;
        priority_queue<pi, vector<pi>, greater<pi>>q;
        q.push({dis[1],1});
        while (q.size()>0)
        {
        
          int node =q.top().second;
          q.pop();
          for(auto c:adj[node])
          {
            int wght=c.second;
            int child=c.first;
            if(dis[child]>dis[node]+wght)
            {
                
              dis[child]=dis[node]+wght;    //relaxing
              q.push({dis[child],child});
              part[child]=node;
            }
          }
        }
              if(dis[n]==1e8) return {-1}; 
        vector<int>v;
        int x=n;
        v.push_back(x);
        while(part[x]!=x)
        {
          v.push_back(part[x]);
          x=part[x];
        }
        reverse(v.begin(),v.end());
        
    // for(auto c:v)
    // {cout<<c<<" ";}


        return v;  
       
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends