//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
      vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
      #define lli long long
      #define pi pair<int,int>
      vector<int>dis(V,1e9);
      priority_queue<pi, vector<pi>, greater<pi>>pq;
      dis[S]=0;
      pq.push({S,dis[S]});
      while(pq.size()>0)
      {
        int node=pq.top().first;
        int wght=pq.top().second;
        pq.pop();
        for(auto c:adj[node])
        { int adNode=c[0];
          int edwght=c[1]; 

          if(dis[adNode]>dis[node] +edwght)
          {
            dis[adNode]=dis[node] +edwght;
            pq.push({adNode,dis[adNode]});
          }
        }
      }
      for(auto c:dis)
   return dis;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends