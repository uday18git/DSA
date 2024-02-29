class DisjointSet{
    public:
        vector<int> rank,parent;
        DisjointSet(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
            }

        }
        int findUPar(int u)
        {
            if(parent[u]==u)
            {
                return u;
            }
            return parent[u] = findUPar(parent[u]);
        }
        void unionByRank(int u,int v)
        {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v)return;
            if(rank[ulp_v] > rank[ulp_u])
            {
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u]>rank[ulp_v])
            {
                parent[ulp_v] = ulp_u;
            }
            else
            {
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++ ;
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = n - connections.size() + 1 ;
        for(int i=0;i<connections.size();i++)
        {
            auto x = connections[i];
            ds.unionByRank(x[0],x[1]);
        }
        int lonely=0;
        for(int i=0;i<n;i++)
        {
            if(ds.findUPar(i)==i)lonely++;
        }
        lonely--;
        if(connections.size()>=(n-1))return lonely;
        else return -1;
    }
};