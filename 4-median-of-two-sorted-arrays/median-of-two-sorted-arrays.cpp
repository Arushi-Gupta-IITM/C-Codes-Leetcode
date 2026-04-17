class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> merArr;
        int i=0, j=0;

        while(i<n && j<m) {
            if(nums1[i] < nums2[j]) {
                merArr.push_back(nums1[i]);
                i++;
            } else {
                merArr.push_back(nums2[j]);
                j++;
            }
        }

        while(i<n) {
            merArr.push_back(nums1[i]);
            i++;
        }

        while(j<m) {
            merArr.push_back(nums2[j]);
            j++;
        }

        int size = merArr.size();
        double median;
        if(size%2 == 0) {
            median = (merArr[size/2] + merArr[(size-1)/2])/2.0 ;
        } else {
            median =  merArr[(size-1)/2];
        }

        return median;
    }
};