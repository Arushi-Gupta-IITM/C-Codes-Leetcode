class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int i = 0;
        map<int, vector<int>, greater<int>> mp; // freq, curr


        while(i < n) {
            int curr = nums[i];
            int j = i;

            while(j < n && nums[j] == curr) j++;

            int freq = j-i+1;
            mp[freq].push_back(curr);
            i = j;
        }

        int count = 0;

        for(auto p : mp) {
            if(count == k) break;

            vector<int> l = p.second;
            for(int val : l) {
                if(count == k) break;

                ans.push_back(val);
                count++;
            }
        }

        return ans;
    }
};