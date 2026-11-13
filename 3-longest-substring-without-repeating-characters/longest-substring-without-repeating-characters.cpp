class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int ans = 0, left = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            unsigned char c = s[right];
            if (last[c] >= left) left = last[c] + 1;
            last[c] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};