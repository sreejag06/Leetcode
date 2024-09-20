class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        unordered_map<int,int> mpp;
        int k,l;
        k= l = -1;

        for(int i = 0;i<n;i++){
            int req = target - nums[i];
            if(mpp.find(req) != mpp.end()){
                return {i,mpp[req]};
            }
            mpp[nums[i]] = i;
        }
        return {k,l};
    }
};