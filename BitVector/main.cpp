#include <iostream>
#include "bitvector.h"

int main() {
    BitVector bitvector;
    bitvector.set(4, 1);
    std::cout << bitvector.get(4);
    bitvector.set(44);
    std::cout << bitvector.get(44);


}