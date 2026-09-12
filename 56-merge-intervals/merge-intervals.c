/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {

    if (intervals == 0) {
        *returnSize = 0;
        return NULL;
    }   

    //Sort by starting point
    int compare(const  void* a, const void* b) {
        int** x = (int**)a;
        int** y = (int**)b;
        return x[0][0] -y[0][0];
    }

     qsort(intervals, intervalsSize, sizeof(int*), compare);

     int** result = malloc(intervalsSize * sizeof(int*));
     *returnColumnSizes = malloc(intervalsSize * sizeof(int));

     int count = 0;

     result[0] = malloc(2 * sizeof(int));
     result[0][0] = intervals[0][0];
     result[0][1] = intervals[0][1];
     (*returnColumnSizes) [0] = 2;
     count = 1;

     for (int i = 1; i < intervalsSize; i++) {

        //Overlapping
        if (intervals[i][0] <= result[count - 1][1]) {
            if (intervals[i][1] > result[count - 1][1]) {
                result[count - 1][1] = intervals[i][1];
            }
        }

        //Non - Overlapping
        else {
            result[count] = malloc(2 * sizeof(int));
            result[count][0] = intervals[i][0];
            result[count][1] = intervals[i][1];
            (*returnColumnSizes)[count] = 2;
            count++;
        }
     }

     *returnSize = count;
     return result;
}