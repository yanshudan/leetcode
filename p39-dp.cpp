class Solution {
public:
    typedef vector<vector<int>> Combs;
    vector<vector<int>> to_vectors(Combs& comb,vector<int>& candidates){
        int len=candidates.size();
        vector<vector<int>> ret;
        vector<int> tmp;
        for(auto& m:comb){
            for(int i=0;i<len;i++) tmp.insert(tmp.end(),m[i],candidates[i]);
            ret.push_back(tmp);
            tmp.clear();
        }
        return ret;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len=candidates.size();
        vector<vector<Combs>> dp(len,vector<Combs>(target+1));
        for(int i=0;i<len;i++){//candidate
            auto val=candidates[i];
            for(int j=0;j<=target;j++){//add target
                auto& combx=dp[i][j];
                if(j==0) {
                    combx=Combs(1,vector<int>(len,0));
                    continue;
                }
                if(i>0){
                    int k=0,sum=j;
                    while(sum>=0){
                        auto& tmp=dp[i-1][sum];
                        //set value
                        for(auto& v:tmp) v[i]=k;
                        //add to combx
                        combx.insert(combx.end(),tmp.begin(),tmp.end());
                        //restore value
                        for(auto& v:tmp) v[i]=0;

                        sum-=val;++k;
                    }
                }
                else{
                    if(j%val==0){
                        combx=Combs(1,vector<int>(len,0));
                        combx[0][i]=j/val;
                    }
                }
            }
        }
        return to_vectors(dp[len-1][target],candidates);
    }
};