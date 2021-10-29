//
//  merge_sort_ref.cpp
//  merge-sort
//
//  Created by mndx on 29/10/2021.
//

#include <vector>

#include "merge_sort.hpp"
#include "merge_sort_ref.hpp"

std::vector<int> merge_ref(std::vector<int>& arr1, std::vector<int>& arr2) {

    std::vector<int> result;
    int n1 = (int) arr1.size();
    int n2 = (int) arr2.size();
    arr1.push_back(inf);
    arr2.push_back(inf);
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

std::vector<int> merge_sort_ref(std::vector<int>& arr, int i, int j) {
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
    std::vector<int> sorted1 = merge_sort_ref(arr, i, k);
    std::vector<int> sorted2 = merge_sort_ref(arr, k + 1, j);
    results = merge_ref(sorted1, sorted2);
    
    return results;
}

std::vector<int> merge_sort_wrap_ref(std::vector<int>& input_arr) {
    std::vector<int> result;
    
    //Perform sort
    int n = (int) input_arr.size();
    result = merge_sort_ref(input_arr, 0, n - 1);
    
    return result;
}
