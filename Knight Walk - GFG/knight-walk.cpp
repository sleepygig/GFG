//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int dr[8] = {-2, -2, 1, -1, +2, +2, 1, -1};
int dc[8] = {-1, +1, -2, -2, -1, 1, +2, +2};
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    #define pi pair<int,int>
	    vector<vector<int>>dis(N+1,vector<int>(N+1,1e9));
	    queue<pair<int,pi>>q;
        int i=KnightPos[0];
        int j=KnightPos[1];
        dis [i][j]=0;
        q.push({dis[i][j],{i,j}});
        while(q.size())
        {
            int cst=q.front().first;

            int sr=q.front().second.first;
            int sc=q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++)
            {
                int nr=sr+dr[i];
                int nc=sc+dc[i];
                if(nr>=1 and nr<=N and nc>=1 and nc<=N)
                {
                    if(dis[nr][nc]>dis[sr][sc]+1)
                    {
                        
                       dis[nr][nc]=dis[sr][sc]+1;
                       q.push({dis[nr][nc],{nr,nc}}); 
                    }
                }
            } 
            
        }
   
      int a=(dis[TargetPos[0]][TargetPos[1]]==1e9)? -1:(dis[TargetPos[0]][TargetPos[1]]);
     return a;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends