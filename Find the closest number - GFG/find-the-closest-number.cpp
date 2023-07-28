//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
   int findClosest(int arr[], int n, int target) 
    { 
        if(n==1)return arr[0];
        int x=lower_bound(arr,arr+n,target)-arr;
        if(x==n-1)
        {
            int a= (abs(arr[x]-target)>abs(arr[x-1]-target))? arr[x-1]:arr[x];
            return a;
        }
        else if(x==0)
        {
              int a= (abs(arr[x]-target)>abs(arr[x+1]-target))? arr[x+1]:arr[x];
              return a;
        }
        else 
        {
            int an=INT16_MAX;
            for(int i=x-1;i<=x+1;i++)
            {
               int a=abs(arr[i]-target);
               an=min(a,an);
            }
             for(int i=x+1;i>=x-1;i--)
            {
               int a=abs(arr[i]-target);
               if(a==an)
               {
                return arr[i];
               }
            }
        }
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,target;
        cin>>n>>target;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(arr,n,target)<<endl;
    }
}

// } Driver Code Ends