class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;

        int i=0, j=0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                v.push_back(nums2[j++]);
            } else {
                v.push_back(nums1[i++]);
            }
        }

        while (i < nums1.size()) {
            v.push_back(nums1[i++]);
        }

        while (j < nums2.size()) {
            v.push_back(nums2[j++]);
        }

        return (v.size() & 1) ? v[v.size() / 2] : ((double)v[v.size() / 2] + (double) v[v.size() / 2 - 1]) / 2.0;
    }
};
