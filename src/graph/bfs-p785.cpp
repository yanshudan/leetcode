class Solution {
public:
    int n;
    vector<int> flags;
    queue<int> q;
    int flag=0;
    bool visit(int i){
        if(flags[i]==-1){
            q.push(i);
            flags[i]=flag;
            return true;
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n=graph.size();
        flags=vector<int>(n,-1);
        int val=0,visited=0;

        visit(0);
        q.push(-1);
        flag=1-flag;
        
        while(visited<n){
            while(!q.empty() && q.front()!=-1){
                val=q.front();
                q.pop();
                ++visited;
                for(auto& idx:graph[val]){
                    if(!visit(idx) && flags[idx]!=flag) return false;
                }
            }
            q.pop();
            if(q.empty() && visited<n) {
                for(int i=0;i<n;i++){
                    if(visit(i)) break;
                }
            }
            q.push(-1);
            flag=1-flag;
        }
        return true;
    }
};