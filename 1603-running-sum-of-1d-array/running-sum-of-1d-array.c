/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {

    // set the size of the returned array
    *returnSize = numsSize;

    // Allocate space for the result array
    int* result = (int*)malloc(numsSize * sizeof(int));
    if (numsSize == 0) return result;

    // Copy the first element
    result[0] = nums[0];

    // calculate running sum
    for (int i = 1; i < numsSize; i++) {
        result[i] = result[i-1] + nums[i];
    }

    return result;
    
}