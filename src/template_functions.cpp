#include <iostream>/* std::cout std::cin */
#include <utility>/* std::pair */
#include <vector>
//#include "../include/template_functions.hpp"

namespace graal{
    template <typename Itr>
    void print_vector(Itr first, Itr last){
    	while(first < last){
		    std::cout << *first << " ";
	    	first++;
    	}
	    std::cout << std::endl;
    }
    /*QUESTÃO 1*/
    template <typename Itr, typename Compare>
    std::pair<Itr, Itr> minmax(Itr first, Itr last, Compare cmp){
    	Itr min{first};
	    Itr max{first};
        while(first < last){
            if(cmp(*first, *min)){
                min = first;
            }
            if(not(cmp(*first , *max))){
                max = first;
            }
            first++;
        }
        return std::make_pair(min, max);
    }

    /*QUESTÃO 2*/
    template <typename Itr>
    void reverse(Itr first, Itr last){
        auto aux{*first};
        auto temp_last{last-1};
        auto middle{std::distance(first, last)};
        while(middle > 0){
            middle = std::distance(first, temp_last)/2;
            aux = *first;
            *first = *temp_last;
            *temp_last = aux;
            first++;
            temp_last--;
        }
    }

    /*QUESTÃO 3*/
    template <typename Itr>
    Itr copy(Itr first, Itr last, Itr d_first){
        while(first < last){
            *d_first = *first;
            d_first++;
            first++;
        }
        return d_first;
    }

    /*QUESTÃO 4*/
    template <typename Itr, typename Predicate>
    Itr find_if(Itr first, Itr last, Predicate p){
        while(first < last){
            if(p(*first)){
                return first;
            }
            first++;
        }
        return last;
    }

    /*QUESTÃO 5*/
    template <typename Itr, typename T, typename Equal>
    Itr find(Itr first, Itr last, const T& value, Equal eq){
        while(first < last){
            if(eq(*first, *value)){
                return first;
            }
            first++;
        }
        return last;
    }

    /*QUESTÃO 6 ALL_OF*/
    template <typename Itr, typename Predicate>
    bool all_of(Itr first, Itr last, Predicate p){
        while(first < last){
            if(not(p(*first))){
                return false;
            }
            first++;
        }
        return true;
    }

    /*QUESTÃO 6 ANY_OF*/
    template <typename Itr, typename Predicate>
    bool any_of(Itr first, Itr last, Predicate p){

        if(first >= last){
            return true;
        }
        while(first < last){
            if(p(*first)){
                return true;
            }
            first++;
        }
        return false;
    }

    /*QUESTÃO 6 NONE_OF*/
    template <typename Itr, typename Predicate>
    bool none_of(Itr first, Itr last, Predicate p){
        while(first < last){
            if(p(*first)){
                return false;
            }
            first++;
        }
        return true;
    }

    /*QUESTÃO 7 EQUAL_A*/
    template <typename Itr, typename Equal>
    bool equal(Itr first, Itr last, Itr first2, Equal eq){
    	while(first < last){
	    if(not(eq(*first, *first2))){
		return false;
	    }
	}

    }

    /*QUESTÃO 7 EQUAL_B*/
    template <typename Itr, typename Equal>
    bool equal(Itr first, Itr last, Itr first2, Itr last2, Equal eq){
        while(first < last){
            if(not(eq(*first, *first2))){
                return false;
            }
            first2++;
            first++;
        }
        return true;
    }

    /*QUESTÃO 8*/
    template <typename Itr, typename Equal>
    Itr unique(Itr first, Itr last, Equal eq){
    	auto result = first;
	auto temp{first};
	bool find{false};
	while(first < last){
	    if(!eq(*result, *first)){
	    	while(temp <= result){
	            if(eq(*temp,*result)){
		    	find = true;
		    }
	    	    //*(++result) = *first;
		}
		if(!find){
	    	    *(++result) = *first;
		    find = false;
		}
	    }
	    first++;
	}
	return ++result;
    }
}/*end namespace graal*/
