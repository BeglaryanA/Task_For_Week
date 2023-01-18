#include <iostream>
#include "bitvector.h"

int main() {
    BitVector bitvector;
    bitvector.set(28, 1);
    std::cout << "ARAJIN " << bitvector.get(28) << std::endl;
  	bitvector.set(29, 1);
	bitvector.set(28, 0);
	std::cout << "29 -> " << bitvector.get(29) << std::endl;
	std::cout << "2rd " << bitvector.get(28) << std::endl;
	bitvector.set(44, 0);
    std::cout << bitvector.get(44);


}
