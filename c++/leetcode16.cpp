class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int running_closest = 32767;
        int running_target = 0;
        for (int i=0;i<nums.size()-2;i++){
            unordered_map<int, int> storage;
            for (int j = i+1; j<nums.size()-1;j++){       
                int search = target - nums[i] - nums[j];
                if (storage.find(search)!=storage.end()){
                    //cout<<nums[i]<<" "<<nums[j]<<" "<<search<<endl;
                    return target;
                }
                else{
                    for (int k = j+1; k<nums.size(); k++){
                         //cout<<"hello "<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                        if (abs(search-nums[k])<abs(running_closest)){
                            //cout<<"enter "<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                            running_target = nums[i]+nums[j]+nums[k];
                            running_closest = abs(target-running_target);
                        }
                    }
                }
                storage[nums[j]] = 0;
            }
        }
        return running_target;
    }
};
