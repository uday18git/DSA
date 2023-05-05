
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {   int n;
//     cin>>n;
//     vector<vector<string>> arr(n,vector<string>(n,"."));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// your code goes here
// int T,N,X;
// while(T--)
// {
//     cin>>N>>X;
//     int Y = (N*X)/4;

//     cout<<Y<<endl;
// }
// return 0;
// int dec=0, bin;
// cin>>bin;
// int count=0;
// while (S!=0)
// {
//     int rem = S%10;
//     X += rem*pow(2,count);
//     S /= 10;
//     count++;
// }
// cout<<dec<<endl;
//     int m=2,n=3,sum=0;
//     for(int i =1;i<=m;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             cout<<i<<j<<" ";
//             cout<<(i&j)<<endl;
//             sum+=i&j;

//         }
//     }
// cout<<sum<<endl;
// int a,b,p,q;
// cin>>a>>b>>p>>q;

// 	    if ((a=p) && (q==b))
// 	    {
// 	        cout<<0<<endl;
// 	    }
// 	    else if(~((a+b)%2)==0 ^ ((p+q)%2)==0)
// 	    {
// 	        cout<<2<<endl;
// 	    }
// 	    else
// 	    {
// 	        cout<<1<<endl;
// 	    }
//  int n=4;

//  for(int i = 0 ; i < n;i++)
//     {
//         for(int j =0;j<n; j++)
//         {
// 			if(i==j){
// 				continue;
// 			}
// 			cout<<j<<" ";

//         }cout<<endl;
//     }

//  }
// vector<int> twoSum(vector<int>& nums, int target) {
//         int high=nums.size(),low=0;
//         vector<int> ans;
//         while(high>=low)
//         {

//             if(nums[high]+nums[low] == target)
//             {
//                 ans.push_back(high);
//                 ans.push_back(low);
//                 return ans;
//             }
//             else if(nums[high]+nums[low] > target)
//             {
//                 high-- ;
//             }
//             else if(nums[high]+nums[low]< target)
//             {
//                 low++ ;
//             }
//         }
//         return ans;
//     }
// int main()
// {
//     vector<int> inp;
//     vector<int> ans;

//     inp.push_back(1);
//     inp.push_back(2);
//     inp.push_back(3);
//     inp.push_back(4);
//     int target = 5;
//     ans = twoSum(inp,target);
//     cout<<ans[0]<<ans[1];

// int main() {
//      long long l,n,m;
//         cin>>l;
//         long long a[l];
//         for(long long i=0;i<l;i++)
//         {
//             cin>>a[i];
//         }
//         cin>>n>>m;
//         long long count = 0;
//         for(long long i=0;i<l;i++)
//         {
//             if(a[i+1]>a[i])
//             {
//                 if((a[i+1]-a[i])<=n)
//                 {
//                     n-= (a[i+1]-a[i]);
//                     count++;
//                 }
//                 else
//                 {
//                     if(m>0)
//                     {
//                         m--;
//                         count++;
//                     }
//                     else{
//                         break;
//                     }
//                 }
//             }
//             else
//             {
//                 count++;
//             }
//         }cout<<count<<endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> nextSmaller(vector<int> v)
// {
//     vector<int> ans;

//     stack<int> s1;
//     s1.push(v.back());
//     for (int i = v.size() - 1; i >= 0; i--)
//     {

//         while (!(s1.empty()) && !(v[s1.top()] < v[i]))
//         {
//             s1.pop();
//         }
//         if (s1.empty())
//         {
//             ans.push_back(v.size());
//         }
//         else
//         {
//             ans.push_back(s1.top());
//         }
//         s1.push(i);
//     }
//     return ans;
// }
// vector<int> prevSmaller(vector<int> v)
// {
//     vector<int> ans;

//     stack<int> s1;
//     s1.push(v[0]);
//     for (int i = 0; i < v.size(); i++)
//     {

//         while (!(s1.empty()) && (v[s1.top()] >= v[i]))
//         {
//             s1.pop();
//         }
//         if (s1.empty())
//         {
//             ans.push_back(-1);
//         }
//         else
//         {
//             ans.push_back(s1.top());
//         }
//         s1.push(i);
//     }
//     return ans;
// }
// int largestRectangleArea(vector<int> &heights)
// {
//     vector<int> ns, ps;
//     int ans = 0;
//     ns = nextSmaller(heights);
//     ps = prevSmaller(heights);
//     // cout<<"ns"<< " ";
//     // for(int i=0;i<ns.size();i++)
//     // {

//         // cout<<ns[ns.size()-i-1]<<" ";
//     // }
//     // cout<<"ps"<< " ";
//     // for(int i=0;i<ps.size();i++)
//     // {

//         // cout<<ps[i]<<" ";
//     // }

//     for (int i = 0; i < heights.size(); i++)
//     {
//         ans = max(ans, (ns[ns.size()-i-1] - ps[i] - 1) * heights[i]);
//         // cout<<ans<<" ";
//     }
//     return ans;
// }
// int main()
// {
//     vector<int> height = {3,1,2,4};
//     int a = largestRectangleArea(height);
//     cout<<a;
//     return 0;
// }
// class Solution {
// public:

// bool issafe(int r,int c,vector<string> &s,int n){
//     int i=r;
//     int j=c;
//     //upperdiagonal
//     while(r>=0 && c>=0){
//         if(s[r][c]=='Q'){
//             return false;
//         }
//         r--;
//         c--;
//     }
//     //left
//     r=i;
//     c=j;
//     while(c>=0){
//         if(s[r][c]=='Q'){
//             return false;
//         }
//         c--;
//     }
//     //lowerdiagonal
//     r=i;
//     c=j;
//     while(r<n && c>=0){
//         if(s[r][c]=='Q'){
//             return false;
//         }
//         r++;
//         c--;
//     }
//     return true;

// }

// void helper(int c,vector<string> &s,vector<vector<string>> &v,int n){
//     if(c==n){
//         v.push_back(s);
//         return;
//     }
//     for(int r=0;r<n;++r){
//         if(issafe(r,c,s,n)){
//             s[r][c]='Q';
//             helper(c+1,s,v,n);
//             //backtracking step after that function returns
//             s[r][c]='.';
//         }
//     }
// }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> v;
//         vector<string> s(n);
//         string s1(n,'.');
//         for(int i=0;i<n;++i){
//             s[i]=s1;
//         }
//         helper(0,s,v,n);
//         return v;

//     }
// };
// to find distance at distance k from a specific node it can either be through subtree of the node or from the ancestor
// first case(subtree) we will take k=number then keep decrementing k till k is 0 in the subtree of the node
// second case(ancestor) 1.find the distance(d) of all ancestors from target node ... for all ancestors find the node using k-d ... if node is in the left subtree of ancestor we will search in right subtree
// so the second case is reduced into first case
// #include "bits/stdc++.h"
// using namespace std;
// struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;
//     Node(int val)
//     {
//         data = val;
//         right = NULL;
//         left = NULL;
//     }
// };
// void printSubtreeNodes(Node * root,int k,vector<int>&v)
// {
//     if(!root || k<0)return;
//     if(k==0){v.push_back(root->data);return;}
//     printSubtreeNodes(root->left,k-1,v);
//     printSubtreeNodes(root->right,k-1,v);
// }
// //case 2.. if we get the target node then we will return the distance from target to ancestor
// int printNodesAtk(Node* root,Node *target,int k,vector<int> &v)
// {
//     if(root==NULL)//if we do not get the target
//     {
//         return -1;
//     }
//     if(root==target)//if we get the
//     {
//         printSubtreeNodes(root,k,v);
//         return 0;
//     }//we did not get target yet, to find target so we'll first try to find in leftsubtree
//     int dl = printNodesAtk(root->left,target,k,v);//dl is the distance from root to target
//     if(dl!=-1){ //means that we have found our target in the left subtree
//         if(dl+1==k)//means ancestor is only k distance from target therefore we print the ancestor's data
//         {
//             v.push_back(root->data);
//         }else//in the else case we will try to find dist k nodes in the right subtree of the root
//         {
//             printSubtreeNodes(root->right,k-dl-2,v);// we are calling it on roots right so there 1 extra and
//         }
//         return 1+dl;
//     }
//     int dr = printNodesAtk(root->right,target,k,v);//dr is the
//     if(dr!=-1){ //means that we have found our target in the left subtree
//         if(dr+1==k)//means ancestor is only k distance from target therefore we print the ancestor's data
//         {
//             v.push_back(root->data);
//         }else//in the else case we will try to find dist k nodes in the right subtree of the root
//         {
//             printSubtreeNodes(root->left,k-dr-2,v);// we are calling it on roots right so there 1 extra and
//         }
//         return 1+dr;
//     }
//     return -1;
// }
// int main()
// {
// vector<int> v;
// struct Node* root = new Node(1);
//     root->left = new Node(2);
// root->right = new Node(3);
// root->left->left = new Node(4);
// root->left->right = new Node(5);
// root->right->left = new Node(6);
// root->right->right = new Node(7);
// printNodesAtk(root,root,2,v);
// for(auto element:v)
// {
// cout<<element<<" ";
// }
//     return 0;
// }
// #include "bits/stdc++.h"

// using namespace std;
// int staradd(int *a,int*b){*b=20;return *a+*b;}
// int andadd(int &a,int &b){b=30;return a+b;}

// int main(){
//     int b=10,c=100;
//     int d = andadd(b,c);
//     int a = staradd(&b,&c);
//     cout<<a<<c<<endl;

// return 0;
// }
// #include "bits/stdc++.h"
// using namespace std;
// struct TreeNode{
// //     int val;
//     TreeNode* right,*left;
//     TreeNode(int data)
//     {
//         val = data;
//         right = NULL;
//         left = NULL;
//     }
// };
// void level(vector<vector<int>> &v,TreeNode* root)
//     {
//         if(!root)return;
//         queue<TreeNode*> q;
//         q.push(root);
//         q.push(NULL);
//         vector<int> v1 ={};
//         while(!q.empty())
//         {
//             TreeNode* node =q.front();
//             q.pop();

//             if(node)
//             {
//                 v1.push_back(node->val);
//                 if(node->left)q.push(node->left);
//                 if(node->right)q.push(node->right);
//             }
//             else if(q.empty())
//             {
//                 q.push(NULL);
//                 v.push_back(v1);
//                 v1={};
//             }
//         }
//     }
// vector<vector<int>> levelOrder(TreeNode* root) {
//     vector<vector<int>> v;
//     level(v,root);
//     return v;
// }
// int main(){

//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
// char s='9';
// char a= '0';
// cout<<s-a;
// return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int count=0;
    for(int i=0;i<4096;i++)
    {
        if(i%128==0)
        {
            count++;
        }
    }
        cout<<count;
    return 0;
}