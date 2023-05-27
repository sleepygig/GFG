//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
      void dfs(int &src,vector<pair<int ,int>> adj[],stack<int>&s,
    int vis[])
    {
        vis[src]=1;
        for(auto &c: adj[src])
        {
            if(!vis[c.first])
            {
                dfs(c.first,adj,s,vis);
            }
        }
        s.push(src);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int ,int>>adj[N];
        stack<int>s;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wght=edges[i][2];
          
                    adj[u].push_back({v,wght});   ///u-->{v,wght};
                    
            
        }    
            int vis[N];
            memset(vis,0,sizeof(vis));
           vector<int> dis(N,1e9);
            // memsetdis,INT32_MAX,sizeof(dis));
            for(int i=0;i<N;i++)
            {
                if(vis[i]==0)
                {
                    dfs(i,adj,s,vis);
                }    
            }
            dis[0]=0;   //jiise start kr rhe uska 0
            while(s.size()>0)
            {
                int node=s.top();
                s.pop();
                for(auto c :adj[node])
                {
                    int v=c.first;
                    int wght=c.second;
                    if(wght+dis[node]<dis[v])
                    {
                        dis[v]=wght+dis[node];
                    }
                }
            }
             for (int i = 0;i < N;i++)
             if (dis[i] == 1e9) dis[i] = -1;
       
 
            

            //  for(auto s:dis)
            // {cout<<s<<" ";}
            return dis;
       }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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