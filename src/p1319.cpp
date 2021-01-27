class UnionFind{
public:
    UnionFind(int n,vector<vector<int>>& edges){
        total=n;
        roots=vector<int> (n,-1);
        for(int i=0;i<n;i++)   roots[i]=i;
    }
    int root(int idx){
        int raw=idx;
        while(roots[idx]!=idx) idx=roots[idx];
        roots[raw]=idx;//compressing path
        return idx;
    }
    void merge(int idx1,int idx2){
        int root1=root(idx1);
        int root2=root(idx2);
        if(root1==root2) return;
        roots[root2]=root1;
        --total;
    }
// private:
    int total;
    vector<int> roots;
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        UnionFind uf(n,connections);
        for(auto& edge:connections){
            uf.merge(edge[0],edge[1]);
        }
        return uf.total-1;
    }
};