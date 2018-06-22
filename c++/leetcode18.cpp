class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size()<4) return result;
        sort(nums.begin(),nums.end());
        for (int i=0; i<nums.size()-3;i++){
            if (i>0 && nums[i]==nums[i-1]) continue;
            for (int j=i+1;j<nums.size()-2;j++){
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                int left = j+1;
                int right = nums.size()-1;
                while (left < right){
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    if (left>j+1 && nums[left]==nums[left-1]) {
                        left++;
                        continue;
                    }
                    if (sum==target){
                        vector<int> sub;
                        sub.push_back(nums[i]);
                        sub.push_back(nums[j]);
                        sub.push_back(nums[left]);
                        sub.push_back(nums[right]);
                        result.push_back(sub);
                        left++;
                    }
                    else if (sum<target){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
        return result;
    }
};
