class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // find next greater element for nums2
        int n = nums2.size();
        stack<int> st;
        vector<int> nge(n);

        for(int i=n-1; i>=0; i--) {
            while(st.empty() == false && st.top() <= nums2[i]) {
                st.pop();
            }

            if(st.empty()) {
                nge[i] = -1;
            } else {
                nge[i] = st.top();
            }

            st.push(nums2[i]);
        }
        // store nums2 element and its nge in a hashmap
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[nums2[i]] = nge[i];
        }
        // find ans
        n = nums1.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            ans[i] = mp[nums1[i]];
        }

        return ans;
    }
};