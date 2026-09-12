double findMedianSortedArrays(int* nums1, int n1, int* nums2, int n2) {

    //Always binary search on the smaller array
    if (n1 > n2) {
        return findMedianSortedArrays(nums2, n2, nums1, n1);
    }

        int low = 0;
        int high = n1;

        while (low <= high) {

            int cut1 = (low + high) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];

            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if (left1 <= right2 && left2 <= right1) {

                //Odd total length
                if ((n1 + n2) % 2 == 1) 

                    return (double) ((left1 > left2) ? left1 : left2);
                
                //Even total length
                int leftMax = (left1 > left2) ? left1 : left2;
                int rightMin = (right1 < right2) ? right1 : right2;

                return (leftMax + rightMin) / 2.0;

            } else if(left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
    
