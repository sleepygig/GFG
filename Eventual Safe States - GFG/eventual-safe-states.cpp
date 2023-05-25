//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
 bool toposort(vector<int>adj[],int vis[],int &src,int path[])
    {
        vis[src]=1;
        path[src]=1;
        for(auto c:adj[src])
        {
            if(!vis[c])
            {
               if(toposort(adj,vis,c,path)) return true;
            }
            else if (path[c]) return true;   //cyle hai mil gya  // path abhi bhi set bit hai mtlb ghum 
                                            // ke aya wapas whi 
        }
        path[src]=0;
        return false;
    }
 	     vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
            int vis[V];
            memset(vis,0,sizeof(vis));
             int path[V];
            memset(path,0,sizeof(path));
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {toposort(adj,vis,i,path);}    
        }
        vector<int >v;
        for(int i=0;i<V;i++)
        {
            if(path[i]==0)
            {
                v.push_back(i);
            }
        }
        return v;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends