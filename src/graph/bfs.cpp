class Solution {
public:
    int rows;
    int cols;
    queue<int> q;
    void visit(vector<vector<int>>& grid, int i,int j){
        if(i<0 || i>=rows || j<0 || j>=cols) return;
        auto& v=grid[i][j];
        if (v==1){
            q.push(i*cols+j);
            v=2;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        rows=grid.size();
        cols=grid[0].size();
        int tmp=0;
        for(auto& vec:grid){
            for(auto& v:vec){
                if(v==2){
                    q.push(tmp);
                    v=0;//remove rotted oranges;
                }
                ++tmp;
            }
        }
        q.push(-1);
        int i=0,j=0;
        tmp=0;
        int rounds=0;
        while (true){
            while(q.front()!=-1){
                tmp=q.front();
                i=tmp/cols;
                j=tmp%cols;
                visit(grid,i+1,j);
                visit(grid,i-1,j);
                visit(grid,i,j+1);
                visit(grid,i,j-1);
                grid[i][j]=0;
                q.pop();
            }
            q.pop();
            ++rounds;
            if(q.empty()) break;
            q.push(-1);
        }
        for(auto& vec:grid){
            for(auto& v:vec){
                if(v!=0) return -1;
            }
        }
        return rounds-1;
    }
};