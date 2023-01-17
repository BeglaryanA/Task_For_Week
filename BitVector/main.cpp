#include <iostream>
#include "bitvector.h"

int main() {
    BitVector bitvector;
    bitvector.set(3, 1);
    bitvector.set(2, 1);
    bitvector.set(8, 1);
    std::cout << bitvector << std::endl;


    BitVector bit2(32); // set size 
    std::cout << bit2[3] << std::endl;
    bit2.set(20, 1);
    std::cout << bit2.get(20);
    return 0;
}