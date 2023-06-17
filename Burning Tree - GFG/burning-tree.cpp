//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
 void treetoGr(Node* root,map<int ,vector<int>>&adj)
{
  if(!root) return ;
  int par=root->data;
  if(root->left) {
    int l=root->left->data;
    adj[l].push_back(par);
    adj[par].push_back(l);
      treetoGr(root->left,adj);
  }
  
  if(root->right) {
    int r=root->right->data;
    adj[r].push_back(par);
    adj[par].push_back(r);
      treetoGr(root->right,adj);
  }
}
void bfs(map<int ,vector<int>>&adj,map<int,int>&vis,int src,int &ans)
{
    queue<pair<int,int>>q;   //node //lvl
    q.push({src,0});
    while(q.size())
    {
        int tp=q.front().first;
        int lv=q.front().second;
        vis[tp]=1;
        ans=max(ans,lv);
        q.pop();
        for(auto c:adj[tp])
        {if(!vis[c]) q.push({c,lv+1});}
    }
}
      int minTime(Node* root, int target) 
    {
        map<int,vector<int>>adj;
        treetoGr(root,adj);
        int y=0;
        map<int,int>vis;
        bfs(adj,vis,target,y);
        return y;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends