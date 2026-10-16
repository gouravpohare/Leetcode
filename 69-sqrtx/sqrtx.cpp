class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int mid;
        int ans = -1;
        while(left <= right){
            mid = left + (right - left)/2;
            if(1ll*mid*mid == x){
                return mid;
            }
            if(1ll*mid*mid < x){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return ans;
    }
};