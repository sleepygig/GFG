//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int dr[8] = {+2, +2, -2,-2, -1,-1, +1,+1};
    int dc[8] = {-1, +1, -1,+1, -2,+2,-2,+2};
  	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
        #define pi pair<int,int>
	  vector<vector<int>>dis (N,vector<int>(N,1e9));
      queue<pair<int,pi>>q;
      int a=KnightPos[0];
      int b=KnightPos[1];
      a--;
      b--;
      dis[a][b]=0;
      q.push({dis[a][b],{a,b}});
      while(q.size())
      {
        int tr=q.front().second.first;
        int tc= q.front().second.second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            int nr=tr+dr[i];
            int nc=tc+dc[i];
            if(nr>=0 and nr<N and nc>=0 and nc<N)
            {
                if(dis[nr][nc]>dis[tr][tc]+1)
                {
                    dis[nr][nc]=dis[tr][tc]+1;
                    q.push({dis[nr][nc],{nr,nc}});
                }
            }
        }
      }
      a=TargetPos[0];
      b=TargetPos[1];
      a--;
      b--;
      if(dis[a][b])
      if(dis[a][b]==1e9) return -1;
      return dis[a][b];



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