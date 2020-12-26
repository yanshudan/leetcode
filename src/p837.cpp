class Solution {
public:
    double new21Game(int N, int K, int W) {
        vector<unsigned long long int> dp(K+W,0);
        dp[0]=1;
        for(int i=0;i<K;i++){
            for(int j=K;j<K+W;j++){
                if(dp[j]==0) continue;
                dp[j]*=W;
            }
            for(int j=K-1;j>=0;j--){
                if(dp[j]==0) continue;
                for(int t=1;t<=W;t++){
                    dp[j+t]+=dp[j];
                }
                dp[j]=0;
            }
        }
        for(auto & v:dp) cout<<v<<" ";
        cout<<endl;
        unsigned long long int count1=0;
        for(int i=K;i<=min(N,K+W-1);i++) count1+=dp[i];
        unsigned long long int count2=0;
        for(int i=N+1;i<K+W;i++) count2+=dp[i];
        return double(count1)/double(count1+count2);
    }
};