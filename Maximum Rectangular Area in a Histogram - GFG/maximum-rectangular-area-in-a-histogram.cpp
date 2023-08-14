//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        
        
        #define ll long long 
        vector<pair<ll,ll>>v(n,{0,0});
        stack<ll>st;  //ind
        for(int i=0;i<n;i++)
        {
            while(st.size() and arr[st.top()]>=arr[i]) st.pop();
            if(st.size()==0) v[i].first=-1;
            else if(arr[st.top()]<arr[i]) v[i].first=st.top();
            st.push(i);
        }
        while(st.size()) st.pop();
          for(int i=n-1;i!=-1;i--)
        {
            while(st.size() and arr[st.top()]>=arr[i]) st.pop();
            if(st.size()==0) v[i].second=n;
            else if(arr[st.top()]<arr[i]) v[i].second=st.top();
            st.push(i);
        }
        ll y=-4;
        for(int i=0;i<n;i++)
        {
            y=max(y,arr[i]*(v[i].second-v[i].first-1));
        }
        return y;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends