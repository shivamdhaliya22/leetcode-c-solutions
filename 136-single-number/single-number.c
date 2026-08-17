int singleNumber(int* nums, int numsSize) {

    int ans = 0;

    for (int i = 0; i <numsSize; i++) {
        ans ^= nums[i];   // x^x = 0 , x^0 = x
    }
    return ans;
}