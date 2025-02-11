#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int k = 1;
    int max = nums[0];
    for (int i = 0; i < numsSize; i++) {
        for(int j = 0; j < numsSize; j++){
            if(max < nums[j]){
                nums[i+1]=nums[j];
                max = nums[j];
                k++;
                break;
            }
        }
    }

    return k;
}

int main(void) {
  int nums[10] = {0, 0, 0, 1, 1, 2, 2, 5, 5, 7};
  
  int size = removeDuplicates(nums, 10);

  for (int i = 0; i < size; i++) {
    printf("%d ", nums[i]);
  }

  return 0;
}