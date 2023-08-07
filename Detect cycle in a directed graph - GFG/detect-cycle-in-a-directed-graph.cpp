//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool  dfs(int sr,vector<int>adj[] ,vector<bool>&vis,vector<bool>&path)

{
    vis[sr]=1;
    path[sr]=1;
    for(auto c:adj[sr])
    {
        if(!vis[c])  //not visited
        {
            if(dfs(c,adj,vis,path)) return true;
        }
        else if(vis[c] and path[c])   //visted and path visted
        {
            return true;
        }
    }
    path[sr]=0;
    return false;
}
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool>vis(V,0);
        vector<bool>path(V,0);
        bool y=false;
                for(int i=0;i<V;i++)
                {
                    if(!vis[i])
                    {
                        y=y or dfs(i,adj,vis,path);
                    }
                }
                return y;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends