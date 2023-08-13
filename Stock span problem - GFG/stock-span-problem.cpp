//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
  vector<int> calculateSpan(int price[], int n) {
        stack<pair<int, int>> st;
        vector<int> ans(n, 1);
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first <= price[i]) st.pop();
            if (!st.empty() and st.top().first>price[i]) ans[i] = i - st.top().second;
            else if(st.size()==0) ans[i]=i+1;
            st.push({price[i], i});
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends