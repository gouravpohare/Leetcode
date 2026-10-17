class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[n-1] != nums[n-2]){
            return nums[n-1];
        }  

        int s = 1;
        int e = n - 2;
        int mid = s + (e-s)/2;
        while(s <= e){
           
           if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
              return nums[mid];
           }

           // left subpart of our taget element that we need to eliminate
           if((mid % 2 == 1 && nums[mid] == nums[mid-1]) 
                 || (mid % 2 == 0 && nums[mid] == nums[mid + 1])){
              s = mid + 1;
           }
           else{
              e = mid - 1; // removing right subpart element is on left
           }
           mid = s + (e-s)/2;
        }
        return -1;
    }
};