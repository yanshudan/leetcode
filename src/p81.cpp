class Solution {
public:
    bool linearsearch(vector<int>& nums, int target) {
        for(auto& v:nums){
            if(v==target) return true;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        if(nums[left]==target|| nums[right]==target) return true;
        int mid=(left+right)/2;
        while(left<right-1){
            int &l=nums[left],&r=nums[right],&m=nums[mid];
            cout<<left<<" "<<mid<<" "<<right<<endl;
            if(m>l){
                if(l<target && target<m) right=mid;
                else left=mid;
            }else if(m<r){
                if(m<target && target<r) left=mid;
                else right=mid;
            }
            //when nums contains duplicated elements...
            else if(l==m && m==r) {
                return linearsearch(nums,target);
            }
            else if(l==m) left=mid;
            else if(r==m) right=mid;
            else cout<<"????";
            if(m==target) return true;
            mid=(left+right)/2;
        }
        return false;
    }
};