class Solution {
public:
    typedef pair<int,int> Pair;
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<Pair> q;
        const Pair null(-1,-1);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                auto& v=grid[i][j];
                if(v==2){
                    q.push({i,j});
                    v=0;//remove rotted oranges;
                }
            }
        }
        q.push(null);
        Pair tmp(0,0);
        int rounds=0;
        while (true){
            while(q.front()!=null){
                tmp=q.front();
                if(tmp.first<rows-1  && grid[tmp.first+1][tmp.second]==1) {
                    q.push({tmp.first+1,tmp.second});
                    grid[tmp.first+1][tmp.second]=2;
                }
                if(tmp.first>0       && grid[tmp.first-1][tmp.second]==1) {
                    q.push({tmp.first-1,tmp.second});
                    grid[tmp.first-1][tmp.second]=2;
                }
                if(tmp.second<cols-1 && grid[tmp.first][tmp.second+1]==1) {
                    q.push({tmp.first,tmp.second+1});
                    grid[tmp.first][tmp.second+1]=2;
                }
                if(tmp.second>0      && grid[tmp.first][tmp.second-1]==1) {
                    q.push({tmp.first,tmp.second-1});
                    grid[tmp.first][tmp.second-1]=2;
                }
                grid[tmp.first][tmp.second]=0;
                q.pop();
            }
            q.pop();
            ++rounds;
            if(q.empty()) break;
            q.push(null);
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                auto& v=grid[i][j];
                if(v!=0) return -1;
            }
        }

        return rounds-1;
    }
};