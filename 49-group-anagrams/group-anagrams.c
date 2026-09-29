/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    
    char*** ans = malloc(strsSize * sizeof(char**));
    *returnColumnSizes = malloc(strsSize * sizeof(int));
    *returnSize = 0;

    char** sorted = malloc(strsSize * sizeof(char*));

    for (int i = 0; i < strsSize; i++) {
        sorted[i] = malloc(strlen(strs[i]) + 1);
        strcpy(sorted[i], strs[i]);
        qsort(sorted[i], strlen(sorted[i]), sizeof(char), cmp);
    }

    int *used = calloc(strsSize, sizeof(int));

    for (int i = 0; i < strsSize; i++) {
        if (used[i]) continue;

        ans[*returnSize] = malloc(strsSize * sizeof(char*));
        int count = 0;

        for (int j = i; j < strsSize; j++) {
            if (!used[j] && strcmp(sorted[i], sorted[j]) == 0) {
                ans[*returnSize][count++] = strs[j];
                used[j] = 1;
            }
        }

        (*returnColumnSizes)[*returnSize] = count;
        (*returnSize)++;
    }

    for (int i = 0; i < strsSize; i++)
        free(sorted[i]);

    free(sorted);
    free(used);

    return ans;
}