Given a list of integers, output the indices that add up the elements to the target

```
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* result = malloc(2*sizeof(int));

    for(int i = 0;i<numsSize;i++){
        for(int j = i+1;j<numsSize;j++){
            if((nums[i]+nums[j])==target){
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL;
}
```

This problem is of the time complexity O(n^2).
The outer loop runs n times and inner loop runs n-1 times for every outer loop.

```
#include <stdlib.h>
typedef struct Entry {
    int key;
    int value;
    int used;
} Entry;

#define TABLE_SIZE 20011  // prime, large enough

int hash(int key) {
    return (abs(key) % TABLE_SIZE);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = malloc(2 * sizeof(int));

    Entry* table = calloc(TABLE_SIZE, sizeof(Entry));  // zero-initialized

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        // Probe for complement in table
        int h = (hash(complement) % TABLE_SIZE);
        while (table[h].used) {
            if (table[h].key == complement) {
                result[0] = table[h].value;  // index of complement
                result[1] = i;
                free(table);
                return result;
            }
            h = (h + 1) % TABLE_SIZE;       // linear probing
        }

        // Insert nums[i] → i into table
        h = hash(nums[i]) % TABLE_SIZE;
        while (table[h].used && table[h].key != nums[i])
            h = (h + 1) % TABLE_SIZE;
        table[h].key   = nums[i];
        table[h].value = i;
        table[h].used  = 1;
    }

    free(table);
    free(result);
    *returnSize = 0;
    return NULL;
}
```