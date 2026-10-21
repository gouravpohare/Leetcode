class Solution {
private:
   int binarysearch(vector<int>& nums, int target, int s, int e){
      int mid = s + (e-s)/2;

      while(s <= e){

        if(nums[mid] == target){
            return mid;
        }
        else if(target > nums[mid]){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }

        mid = s + (e-s)/2;

      }
      return -1;
   }
public:
    int search(vector<int>& nums, int target) {

        int breakpoint = 0;
         
         for(int i=1; i<nums.size(); i++){
            if(nums[i] < nums[i-1]){
                breakpoint = i;
            }
         }

         if(breakpoint == 0){
            return binarysearch(nums, target, 0, nums.size() - 1);
         }
        
        if(target >= nums[0] && target <= nums[breakpoint - 1]){
          return binarysearch(nums, target, 0, breakpoint - 1);
        }
        else{
            return binarysearch(nums, target, breakpoint, nums.size() - 1);
        }
        
       
    }
};