#include "UnionFind.h"
void init(vector<vector<int>>& input){
    srand(7);
    for(auto& vec:input){
        for(auto& val:vec){
            val=rand()%2;
        }
    }
}
int main(int argc,char** argv){
    // int cols=atoi(argv[1]);
    // int rows=atoi(argv[2]);
    int rows=grid.size();
    int cols=grid[0].size();
    vector<vector<int>> input(rows,vector<int>(cols,0));
    init(input);
    // string fname(argv[3]);
    // char* tmp=new char[rows*cols];
    // char** input=new char*[rows];
    // auto* fd=fopen(fname.c_str(),"rb");
    // fread(tmp,sizeof(char),1075,fd);
    // fread(tmp,sizeof(char),rows*cols,fd);
    // fclose(fd);
    // for(int i=0;i<rows;i++){
    //     input[i]=tmp;
    //     tmp+=cols;
    // }
    cout<<grid<<endl;
    UnionFind uf(grid);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(grid[i][j]=='1'){
                if(i<rows-1 && grid[i+1][j]=='1')  uf.merge(i*cols+j,(i+1)*cols+j);
                if(i>0      && grid[i-1][j]=='1')  uf.merge(i*cols+j,(i-1)*cols+j);
                if(j<cols-1 && grid[i][j+1]=='1')  uf.merge(i*cols+j,(i)*cols+j+1);
                if(j>0      && grid[i][j-1]=='1')  uf.merge(i*cols+j,(i)*cols+j-1);
            }
        }
    }
    return uf.total;
}