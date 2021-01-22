class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return vector<int>(2,-1);
        vector<int> ret;
        int left=-1;
        int right=nums.size();
        while(right-left!=1){
            int mid=(left+right)/2;
            if(nums[mid]<target){
                left=mid;
            }else{
                right=mid;
            }
        }
        if(right!=nums.size() && nums[right]==target){
            ret.push_back(right);
        }else ret.push_back(-1);
        left=-1;
        right=nums.size();
        while(right-left!=1){
            int mid=(left+right)/2;
            if(nums[mid]<=target){
                left=mid;
            }else{
                right=mid;
            }
        }
        if(left!=-1 && nums[left]==target){
            ret.push_back(left);
        }else ret.push_back(-1);
        return ret;
    }
};