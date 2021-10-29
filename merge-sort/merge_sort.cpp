//
//  merge_sort.cpp
//  merge-sort
//
//  Created by mndx on 29/10/2021.
//

#include <vector>

#include "merge_sort.hpp"

void merge(std::vector<int>& arr, int i, int k, int j) {

    int n1 = k - i + 1;
    int n2 = j - k;
    int* arr1 = new int[n1 + 1];
    int* arr2 = new int[n2 + 1];
    int arr_index = i;
    for(int arr1_index = 0; arr1_index < n1; ++arr1_index) {
        arr1[arr1_index] = arr[arr_index];
        arr_index++;
    }
    
    for(int arr2_index = 0; arr2_index < n2; ++arr2_index) {
        arr2[arr2_index] = arr[arr_index];
        arr_index++;
    }
    
    arr1[n1] = inf;
    arr2[n2] = inf;
    
    int arr1_index = 0;
    int arr2_index = 0;
    for(int arr_index = i; arr_index <= j; ++arr_index) {
        if(arr1[arr1_index] >= arr2[arr2_index]) {
            arr[arr_index] = arr2[arr2_index];
            arr2_index++;
        }
        else {
            arr[arr_index] = arr1[arr1_index];
            arr1_index++;
        }
    }
    
    //Free data
    delete [] arr1;
    delete [] arr2;
}

void merge_sort(std::vector<int>& arr, int i, int j) {

    //Case single element
    if(i == j) { return; }
    
    //Case two elements
    if(j - i == 1) {
        if(arr[i] > arr[j]) {
            int dum = arr[i];
            arr[i] = arr[j];
            arr[j] = dum;
        }
        return;
    }
    
    //Case more than two elements being sorted
    int k = (i + j) / 2;
    merge_sort(arr, i, k);
    merge_sort(arr, k + 1, j);
    merge(arr, i, k, j);
}

void merge_sort_wrap(std::vector<int>& input_arr) {
    
    int n = (int) input_arr.size();
    
    //Perform sort
    merge_sort(input_arr, 0, n - 1);
}
