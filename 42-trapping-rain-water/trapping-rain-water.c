int trap(int* height, int heightSize) {
    // Two pointers at both ends
    int left = 0;
    int right = heightSize - 1;

    // Maximum height seen so far from left and right
    int leftMax = 0;
    int rightMax = 0;

    // Stores total trapped water
    int water = 0;

    while (left < right) {

        // Work on the side with smaller height
        if (height[left] < height[right]) {

            // Update left maximum boundary
            if (height[left] >= leftMax) {
                leftMax = height[left];
            }
            else {
                // Water trapped at current left position
                water += leftMax - height[left];
            }

            left++;
        }
        else {

            // Update right maximum boundary
            if (height[right] >= rightMax) {
                rightMax = height[right];
            }
            else {
                // Water trapped at current right position
                water += rightMax - height[right];
            }

            right--;
        }
    }

    return water;
}