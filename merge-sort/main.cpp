//
//  main.cpp
//  merge-sort
//
//  Created by mndx on 28/10/2021.
//

#include <cstdlib>
#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int>& arr1, std::vector<int>& arr2) {

    std::vector<int> result;
    int n1 = (int) arr1.size();
    int n2 = (int) arr2.size();
    arr1.push_back(3e+8);
    arr2.push_back(3e+8);
    int arr1_index = 0;
    int arr2_index = 0;
    for(int index = 0; index < n1 + n2; ++index) {
        if(arr1[arr1_index] >= arr2[arr2_index]) {
            result.push_back(arr2[arr2_index]);
            arr2_index++;
        }
        else {
            result.push_back(arr1[arr1_index]);
            arr1_index++;
        }
    }
    
    return result;
}

std::vector<int> merge_sort(std::vector<int>& arr, int i, int j) {
    std::vector<int> results;
    
    if(i == j) {
        results.push_back(arr[i]);
        return results;
    }
    
    if(j - i == 1) {
        if(arr[i] > arr[j]) {
            results.push_back(arr[j]);
            results.push_back(arr[i]);
        }
        else {
            results.push_back(arr[i]);
            results.push_back(arr[j]);
        }

        return results;
    }
    
    int k = (i + j) / 2;
    std::vector<int> sorted1 = merge_sort(arr, i, k);
    std::vector<int> sorted2 = merge_sort(arr, k + 1, j);
    results = merge(sorted1, sorted2);
    
    return results;
}

std::vector<int> merge_sort_wrap(std::vector<int>& input_arr) {
    std::vector<int> result;
    
    int n = (int) input_arr.size();
    result = merge_sort(input_arr, 0, n - 1);
    
    return result;
}

int main(int argc, const char * argv[]) {

    //Input size arrays
    int n = 9;
    
    //Allocate space for input
    std::vector<int> input;
    
    //Initialize input array
    for(int i = 0; i < n; ++i) {
        int val = rand() % n + 1;
        input.push_back(val);
    }
    
    //Perform merge sort
    std::vector<int> result = merge_sort_wrap(input);
    
    //Check if array is sorted
    bool arr_is_sorted = true;
    int size_res = (int) result.size();
    for(int i = 0; i < size_res - 1; ++i) {
        if(result[i] > result[i + 1]) {
            arr_is_sorted = false;
        }
    }
    
    //Print results
    int size = (int) result.size();
    for(int i = 0; i < size; ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "array is sorted: " << arr_is_sorted << std::endl;
    std::cout << "done" << std::endl;
    
    return 0;
}
