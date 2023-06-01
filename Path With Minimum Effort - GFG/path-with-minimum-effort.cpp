//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int dr[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dc[8] = {0, 1, 0, -1, -1, 1, -1, 1};
    int MinimumEffort(vector<vector<int>>& heights) {
        #define pi pair<int,int>
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e8));
       dis[0][0]=0;
        priority_queue<pair<int,pi>, vector<pair<int,pi>>, greater<pair<int,pi>>>q;
        q.push({dis[0][0],{0,0}});
       while ((q.size()))
       {
        // deb(dis[2][2]);
        int tr=q.top().second.first;
        int tc=q.top().second.second;
        q.pop();
          for(int i=0;i<4;i++)
          {
              int nr=tr+dr[i];
              int nc=tc+dc[i];
              if(nc>=0 and nc<m and nr>=0 and nr<n)
              {//dis[i][j] curr particular path ka max diffko main kr rha hai  
                int mxeffort=max(dis[tr][tc],abs(heights[nr][nc]-heights[tr][tc])); 
                //via this path
                if(dis[nr][nc]>mxeffort)  //agr piche se km hai nya effort ko update !     
                {
                  dis[nr][nc]=mxeffort;
                  q.push({dis[nr][nc],{nr,nc}});
                }
              }
          }
       }    
      //  print2d(dis,n,m);  
  return dis[n-1][m-1];
       }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends