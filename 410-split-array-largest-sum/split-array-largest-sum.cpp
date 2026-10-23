// Solving it like an Book allocation Problem
class Solution {
private: 
    bool isPossible(vector<int>& nums, int barrier, int k){
       int allocatedstu = 1;
       int pages = 0;
       for(int i=0; i<nums.size(); i++){
          if(nums[i] > barrier){
             return false;
          }
          if(pages + nums[i] > barrier){
            allocatedstu += 1;
            pages = 0;
            pages += nums[i];
          }
          else{
            pages += nums[i];
          }
       }

       if(allocatedstu > k){
          return false;
       }
       else{
           return true;
       }
    }
    
public:
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        int mini = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(nums[i] < mini){
                mini = nums[i];
            }
        }
        int low = mini;
        int high = sum;
        int mid;
        int res = 0;
        while(low <= high){
            mid = low + (high - low)/2;
            if(isPossible(nums, mid, k)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return res;
    }
};