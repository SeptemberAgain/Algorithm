#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
//Median of Two Sorted Arrays
using namespace std;


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
        int n = nums1.size();
        int m = nums2.size();
        if (n<m) return findMedianSortedArrays(nums2,nums1);
        if (m == 0) return (nums1[n/2]+nums1[(n-1)/2])/2.0;
        int i = n/2;
        int j = (n+m+1)/2-i;
        while(1)
        {
            if (((j ==0||i == n)||nums1[i]>=nums2[j-1]) && ((i ==0||j == m)||nums1[i-1]<=nums2[j])) break;
            else if (nums1[i]<nums2[j-1]) i++;
            else if (nums1[i-1]>nums2[j]) i--;
            j = (n+m+1)/2-i;
        }
        if ((n + m)%2 == 0)
        {
            int temp_left,temp_right;
            if (i==0) temp_left = nums2[j-1];
            else if (j==0) temp_left = nums1[i-1];
            else temp_left =max(nums2[j-1],nums1[i-1]);
            if (i==n) temp_right = nums2[j];
            else if (j==m) temp_right = nums1[i];
            else temp_right = min(nums1[i],nums2[j]);
            return (temp_left+temp_right)/2.0;
        }
        else
        {
            if (j==0) return nums1[i-1];
            else return max(nums1[i-1],nums2[j-1]);
        }
	}
};