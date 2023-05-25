//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
   bool dfs(vector<int> adj[],int &src ,int path[],int vis[],stack<int>&s)
    {
        vis[src]=1;
        path[src]=1;
        for(auto c:adj[src])
        {
            if (!vis[c])
            {
            if(dfs(adj,c,path,vis,s)==true) return true;   // cycle mil gya
            
             if (path[c]) return true; 
            }
        }
        s.push(src);
        path[src]=0; // unsetting the path kyuki is call is exit le rha
        return false;
    }
   string findOrder(string dict[], int N, int K) {
    vector<int> adj[K];
    for(int i=0;i<N-1;i++)
    {
        string s1=dict[i];
        string s2=dict[i+1];
        for(int j=0;j<min(s1.size(),s2.size());j++)
        {
            if(s1[j]!=s2[j])
            {
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }

        int vis [K];
        int path[K];
        memset(vis,0,sizeof(vis));
        memset(path,0,sizeof(path));
        stack<int>s;
        for(int i=0;i<K;i++)
        {
                if(vis[i]==0)
                {
                    if(dfs(adj,i,path,vis,s)) return "0" ;
                }    
        }
        string s3;
     while(s.size()>0)
     {
        s3.push_back((char)(s.top()+97));
        s.pop();
     }
        return s3;
            
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends