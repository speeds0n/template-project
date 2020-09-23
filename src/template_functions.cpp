#include <iostream>/* std::cout std::cin */
#include <utility>/* std::pair */
#include "../include/template_functions.hpp"

template <typename Itr>
void print_vector(Itr first, Itr last){
	while(first < last){
		std::cout << *first << " ";
		first++;
	}
	std::cout << std::endl;
}

template <typename Itr, typename Compare>
std::pair<Itr, Itr> minmax(Itr first, Itr last, Compare cmp){
	Itr min{first};
	Itr max{first};
	if(first < last){
		std::cout << "teste" << std::endl;
		return std::make_pair(min,max);
	}
}
