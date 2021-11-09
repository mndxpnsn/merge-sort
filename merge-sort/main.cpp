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

    //Perform merge sort
    merge_sort_wrap(input);
    
    //Print results
    int size_inp = (int) input.size();
    for(int i = 0; i < size_inp; ++i) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "done" << std::endl;
    
    return 0;
}
