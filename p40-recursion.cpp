class Solution {
public:
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ret;
        vector<bool> flags(candidates.size(),true);
        vector<int> tmp;
        int sum=target;
        function<void(int)> func=[&](int i){
            if(sum<0){}//return
            else if(sum==0) ret.push_back(tmp);
            else{
                int val=0;
                for(;i<candidates.size();i++){
                    if(val==candidates[i]) continue;
                    val=candidates[i];
                    if(flags[i]){
                        tmp.push_back(val);
                        flags[i]=false;
                        sum-=val;
                        func(i+1);
                        sum+=val;
                        flags[i]=true;
                        tmp.pop_back();
                    }
                }
            }
        };
        func(0);
        return ret;
    }
};