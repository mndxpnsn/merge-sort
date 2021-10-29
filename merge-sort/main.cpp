//
//  main.cpp
//  merge-sort
//
//  Created by mndx on 28/10/2021.
//

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>

#include "merge_sort.hpp"
#include "merge_sort_ref.hpp"

int main(int argc, const char * argv[]) {

    //Input size array
    int n = 9;
    
    //Allocate space for input
    std::vector<int> input;
    
    //Initialize input array with random data
    for(int i = 0; i < n; ++i) {
        int val = rand() % n + 1;
        input.push_back(val);
    }
    
    //Perform merge sort using method 1
    std::vector<int> result = merge_sort_wrap_ref(input);

    //Perform merge sort using method 2
    merge_sort_wrap(input);
    
    //Check if array using method 1 is sorted
    bool arr_is_sorted = true;
    int size_res = (int) result.size();
    for(int i = 0; i < size_res - 1; ++i) {
        if(result[i] > result[i + 1]) {
            arr_is_sorted = false;
        }
    }
    
    //Check if array using method 2 is sorted
    bool arr_inp_is_sorted = true;
    int size_res_inp = (int) input.size();
    for(int i = 0; i < size_res_inp - 1; ++i) {
        if(input[i] > input[i + 1]) {
            arr_inp_is_sorted = false;
        }
    }
    
    //Print results
    int size = (int) result.size();
    for(int i = 0; i < size; ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    int size_inp = (int) input.size();
    for(int i = 0; i < size_inp; ++i) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "array is sorted: " << arr_is_sorted << std::endl;
    std::cout << "input is sorted: " << arr_inp_is_sorted << std::endl;
    std::cout << "done" << std::endl;
    
    return 0;
}
