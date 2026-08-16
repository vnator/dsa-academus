#include <stdio.h>

int kadane(int* nums, int num_size) {
    if (num_size == 0 || nums == NULL) {
        return 0;
    }

    int curr_max = nums[0];
    int global_max = nums[0];

    for(int i = 1; i < num_size; i++) {
        curr_max = curr_max + nums[i] < nums[i] ? nums[i] : curr_max + nums[i];

        if (curr_max > global_max) {
            global_max = curr_max;
        }
    }

    return global_max;
}