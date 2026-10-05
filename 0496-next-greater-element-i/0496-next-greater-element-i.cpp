class Solution {
public:

    vector<int> findNGE(vector<int>& arr) {

        int n = arr.size();
        vector<int> nge(n);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            nge[i] = st.empty() ? -1 : st.top();

            st.push(arr[i]);
        }

        return nge;
    }

    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {

        vector<int> nge = findNGE(nums2);

        unordered_map<int,int> mp;

        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = nge[i];
        }

        vector<int> ans;

        for (int num : nums1) {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};