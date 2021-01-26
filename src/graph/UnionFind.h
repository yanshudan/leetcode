#include <vector>
#include <iostream>


class UnionFind{
public:
    UnionFind(vector<vector<char>>& input){
        int rows=input.size();
        int cols=input[0].size();
        int size=cols*rows;
        int idx=0;
        total=0;
        roots=vector<int> (size,0);
        ranks=vector<int>(size,0);
        count=vector<int>(size,0);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(input[i][j]=='1'){
                    idx=i*cols+j;
                    roots[idx]=idx;
                    ranks[idx]=1;
                    count[idx]=1;
                    total++;
                }
            }
        }
    };
    UnionFind(char** input,int rows,int cols){
        int size=cols*rows;
        int idx=0;
        total=0;
        roots=vector<int> (size,0);
        ranks=vector<int>(size,0);
        count=vector<int>(size,0);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(input[i][j]==1){
                    idx=i*cols+j;
                    roots[idx]=idx;
                    ranks[idx]=1;
                    count[idx]=1;
                    total++;
                }
            }
        }
    };
    int const root(int idx){
        while(roots[idx]!=idx) idx=roots[idx];
        return idx;
    }
    bool merge(const int& idx1,const int& idx2){
        int root1=root(idx1);
        int root2=root(idx2);
        int &root=ranks[root1]>ranks[root2]?root1:root2;
        int &child=root==root1?root2:root1;
        if(root1==root2) return false;
        --total;
        roots[child]=root;
        count[root]+=count[child];
        count[child]=0;
        if(ranks[root]==ranks[child]) ranks[root]++;
        return true;
    };
private:
    vector<int> roots;
    vector<int> ranks;
    vector<int> count;
    int total;
}
ostream& operator<<(ostream& os,const vector<int>& v){
    for(auto& e:v) os<<e<<" ";
    cout<<endl;
    return os;
}
ostream& operator<<(ostream& os,const vector<vector<int>>& v){
    for(auto& e:v) os<<e;
    return os;
}