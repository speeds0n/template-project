/*!
 * \file template_functions.hpp
 * \author Edson Cassiano
 * \date September, 19th
 */

#ifndef TEMPLATE_FUNCTIONS_HPP
#define TEMPLATE_FUNCTIONS_HPP

template <typename Itr>
void print_vector(Itr first, Itr last);

template <typename Itr, typename Compare>
std::pair<Itr, Itr> minmax(Itr first, Itr last, Compare cmp);

#endif
