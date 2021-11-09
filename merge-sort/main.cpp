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
    
    //Initialize array of size n with random data
    std::vector<int> array;
    for(int i = 0; i < n; ++i) {
        int val = rand() % n + 1;
        array.push_back(val);
    }

    //Perform merge sort
    merge_sort_wrap(array);
    
    //Print results
    for(int i : array) { std::cout << i << " "; }
    std::cout << std::endl;
    std::cout << "done" << std::endl;
    
    return 0;
}
