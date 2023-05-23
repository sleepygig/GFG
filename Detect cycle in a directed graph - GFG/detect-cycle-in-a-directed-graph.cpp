//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
	vector<int> topoSort(int &V, vector<int> adj[]) 
	{
        queue<int>q;
	   int inde[V]={0};
       for(int i=0;i<V;i++)
       {
            for(auto c:adj[i])
            {inde[c]++;}        //indrgee array bn gya
       }
       for(int i=0;i<V;i++)
       {
            if(inde[i]==0)
            {
                q.push(i);
            }
       }
       vector<int>v;
       while(q.size()>0)
       {
        int tp=q.front();
        v.push_back(tp);
        q.pop();
        for(auto c:adj[tp])
        {
            inde[c]--;
            if(inde[c]==0)
            {q.push(c);}
        }
       }
      return v;
	}
  bool isCyclic(int V, vector<int> adj[]) {
      vector<int>a=topoSort(V,adj);
      if(a.size()!=V) return true ;
      return false;
   
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