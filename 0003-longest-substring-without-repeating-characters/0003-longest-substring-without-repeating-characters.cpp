class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> lastIndex(256, -1);

        int left = 0;
        int maxi = 0;

        for (int right = 0; right < s.size(); right++) {

            if (lastIndex[s[right]] != -1) {

                left = max(left, lastIndex[s[right]] + 1);
            }

            lastIndex[s[right]] = right;

            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};