//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S){
       std::stack<int> st;
    int max_length = 0;
    int start_index = -1;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '(') {
            st.push(i);
        } else if (S[i] == ')') {
            if (st.empty()) {
                start_index = i;
            } else {
                st.pop();
                if (st.empty()) {
                    max_length = std::max(max_length, i - start_index);
                } else {
                    max_length = std::max(max_length, i - st.top());
                }
            }
        }
    }

    if (st.empty()) {
        max_length = std::max(max_length, static_cast<int>(S.length()) - start_index - 1);
    }

    return max_length;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends