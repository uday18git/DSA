// disjoint set data structure 
// single graph with 2 components
// 1 2 3 4
// 5 6 7
// we have to check whether 1 and 5 belong to the same component
// in brute force we can use dfs / bfs  O(V+E)
// but disjoint set data structure can do it in constant time (yes or no it will give)

// find parent 
// union -> rank , size
// 1 2 , union
// 2 3 , union
// 4 5 , union
// in between some question if it comes , you have to answer in constant time
// 6 7 , union
// 5 6 , union
// 3 7 , union

// union(u,v)
// 1. find the ultimate parent of u & v , pv and pu
// 2. Find the rank of pu and pv
// 3. Connect smaller rank to larger rank always , if both ranks are equal connect any to any


// if there parent is same , then same component
// it takes log(N) 

// but it takes constant time O(4 alpha)

class DisjointSet{
    vector<int> rank,parent;
public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findPar(int node)
    {
        if(node == parent[node])
        {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_v == ulp_v)return;
        if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else // if it is equal
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};



#include <bits/stdc++.h> 
using namespace std;
int main(){

return 0;
}
// why connect smaller to larger
// because if you connect larger to smaller 
// faltu me the size increases
// and time taken to find parent also decreases if u attach smaller to larger

// union by size 
// size array will be
// size =>  {1,1,1,1,1,1,1}
// parent => {1,2,3,4,5,6,7}


// BY SIZE

#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}