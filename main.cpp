#include <iostream>
#include <utility>

#include "include/template_functions.hpp"

template <typename Type>
bool cmp(const Type *a, const Type *b){

	return *a < *b;
}

int main(){

	int V[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	auto temp_1 = cmp(&V[0], &V[1]);
	std::cout << temp_1 << std::endl;

//	print_vector(std::begin(V), std::end(V));
	auto temp_2 = minmax(std::begin(V), std::end(V), cmp);

	return 0;
}
