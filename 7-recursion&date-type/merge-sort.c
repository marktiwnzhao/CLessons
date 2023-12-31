//
// Created by 赵政杰 on 2021/11/22.
//
#include <stdio.h>
#define LEN 10
int numbers[LEN] = {4, 2, 8, 6, 0, 5, 1, 7, 3, 9};

void MergeSort(int nums[], int left, int right);
//Merge two subarrays nums[left .. mid] and nums[mid + 1 .. right]
void Merge(int nums[], int left, int mid, int right);
int main() {
    MergeSort(numbers, 0, LEN - 1);

    for (int i = 0; i < LEN; i++) {
        printf("%d ", numbers[i]);
    }
    return 0;
}

void MergeSort(int nums[], int left, int right) {
    if (left == right) {
        return;
    }

    int mid = (left + right) / 2;
//recursively mergesort numbers[left .. mid]
    MergeSort(numbers, left, mid);
//recursively mergesort numbers[mid + 1 .. right]
    MergeSort(numbers, mid + 1, right);
    Merge(numbers, left, mid, right);
}

void Merge(int nums[], int left, int mid, int right) {
    /**
     * Create two temporary arrays
     * Using VLA (variable-length arrays)
     */
    int left_size = mid - left + 1;
    int nums_left[left_size];
    for (int i = 0; i < left_size; i++) {
        nums_left[i] = nums[left + i];
    }

    int right_size = right - mid;
    int nums_right[right_size];
    for (int i = 0; i < right_size; i++) {
        nums_right[i] = nums[mid + 1 + i];
    }

    int left_index = 0;
    int right_index = 0;
    int current_index = left;

    while (left_index < left_size && right_index < right_size) {
        if (nums_left[left_index] <= nums_right[right_index]) {
            nums[current_index] = nums_left[left_index];
            left_index++;
        } else {
            nums[current_index] = nums_right[right_index];
            right_index++;
        }

        current_index++;
    }

    while (left_index < left_size) {
        nums[current_index] = nums_left[left_index];
        left_index++;
        current_index++;
    }

    while (right_index < right_size) {
        nums[current_index] = nums_right[right_index];
        right_index++;
        current_index++;
    }
}
