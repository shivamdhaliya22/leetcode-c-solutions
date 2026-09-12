/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void mergeSort(int* nums, int* index, int* count,
               int low, int high) {

    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(nums, index, count, low, mid);
    mergeSort(nums, index, count, mid + 1, high);

    int temp[high - low + 1];

    int i = low;
    int j = mid + 1;
    int k = 0;
    int rightSmaller = 0;

    while (i <= mid && j <= high) {

        if (nums[index[j]] < nums[index[i]]) {

            temp[k++] = index[j++];
            rightSmaller++;
        }
        else {

            count[index[i]] += rightSmaller;
            temp[k++] = index[i++];
        }
    }

    // Remaining left elements
    while (i <= mid) {

        count[index[i]] += rightSmaller;
        temp[k++] = index[i++];
    }

    // Remaining right elements
    while (j <= high) {
        temp[k++] = index[j++];
    }

    // Copy back
    for (i = low; i <= high; i++) {
        index[i] = temp[i - low];
    }
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {

    int* count = calloc(numsSize, sizeof(int));
    int* index = malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        index[i] = i;
    }

    mergeSort(nums, index, count, 0, numsSize - 1);

    *returnSize = numsSize;

    free(index);

    return count;
}