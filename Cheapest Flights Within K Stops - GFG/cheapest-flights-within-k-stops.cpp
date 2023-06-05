//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
         vector<pair<int,int>>adj[n];
           for(int i=0;i<flights.size();i++)
           {
              int u=flights[i][0];
              int v=flights[i][1];
              int wght=flights[i][2];
              adj[u].push_back({v,wght});   //adj[u]=  {v, wght};
           }
           #define pi pair<int,int>
           vector<int> dis(n,1e8);   //dist array;
            queue<pair<int,pi>>pq;
            
            int a=0;
            pq.push({a,{src,0}});
            dis[src]=0;
            while(pq.size())
            {   
              int node=pq.front().second.first;
              int chn=pq.front().first;
              int cst=pq.front().second.second;
              pq.pop();
              if(chn>k)continue;;
              for(auto &c:adj[node])
              {
                int child =c.first;
                int wght=c.second;
                if(dis[child]>cst+wght )
                {
                   
                  dis[child]=cst+wght;
                  pq.push({chn+1,{child,dis[child]}});
                }
              }
            } 
          // for(auto c:dis)
          // {cout<<c<<" ";}
            if(dis[dst]==1e8) return -1;
            return dis[dst];  

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends