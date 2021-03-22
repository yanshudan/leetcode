class Solution {
public:
    int strStr(string haystack, string needle) {
        int len=needle.size();
        vector<int> next(len+1,0);
        //next
        int k=-1,j=0,i=0;
        next[j]=k;
        while(j<len){
            if(k==-1 || needle[k]==needle[j]){
                ++k;
                ++j;
                next[j]=k;
            }else k=next[k];
        }
        // for(auto& v:next) cout<<v<<" ";cout<<endl;

        //search
        j=0;
        while(i<haystack.size() && j<len){
            if(j==-1 || needle[j]==haystack[i]){
                ++j;
                ++i;
            }else{
                j=next[j];
            }
        }
        if(j==len) return i-len;
        else return -1;
    }
};