class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> map;

        for(int a : nums1) {
            for(int b : nums2) {
                map[a+b]++;
            }
        }

        int count = 0;
        for(int c : nums3) {
            for(int d : nums4) {
                int tar = -(c+d);
                if(map.find(tar) != map.end()) {
                    count = count + map[tar];
                }
            }
        }
        return count;
    }
};