#include <iostream>
#include <utility>
//#include <vector>
#include <algorithm>
#include "src/template_functions.cpp"

bool cmp_int(const int& a, const int& b){
	return a < b;
}
bool p_int(const int& a){
    return a < 0;
}
bool eq_int(const int& a, const int& b){
    return a == b;
}
bool p_int_2(const int& a){
    return a < 0;
}
int main(){

	int V[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1};

	auto temp_1 = cmp_int(V[0], V[1]);
	std::cout << temp_1 << std::endl;

	graal::print_vector(std::begin(V), std::end(V));
	auto temp_2 = graal::minmax(std::begin(V), std::end(V), cmp_int);
    std::cout << "min: " << *(temp_2.first) << " max: " << *(temp_2.second) << std::endl << std::endl;

    int V_2[]{1, 2, 3, 4, 5, 6};
    graal::print_vector(std::begin(V_2), std::end(V_2));
    /* Eu preciso passar o end-1 para que a funcao funciona ou tem outra forma de fazer?*/
    //graal::reverse(std::begin(V_2), std::end(V_2)-1);
    graal::reverse(std::begin(V_2), std::end(V_2));
    graal::print_vector(std::begin(V_2), std::end(V_2));
    std::cout << std::endl;

    /* Eu posso alocar memoria com o cliente?*/
    int V_3[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *copy_first = new int(50);
    graal::print_vector(std::begin(V_3), std::end(V_3));
    auto copy_last = graal::copy(std::begin(V_3), std::end(V_3), copy_first);
    graal::print_vector(copy_first, copy_last);

    /*O que é (unary preticate), pelo que eu entendi é uma condicao na qual o valor é verdade para uma
    expressao, por exemplo: predicado i < 10, predicado i == 5, predicado i > 0, eu so preciso apontar para
    a primeira ocorrencia do predicado? independentemente de haver outras no intervalo?
    retorno caso noa tenha predicado dve ser para o last*/
    int V_4[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -2};
    auto temp_v4 = graal::find_if(std::begin(V_4), std::end(V_4), p_int);
    std::cout << *temp_v4 << std::endl << std::endl;

    int V_5[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int value_5{6};
    auto temp_v5 = graal::find(std::begin(V_5), std::end(V_5), &value_5, eq_int);
    std::cout << *temp_v5 << std::endl << std::endl;

    /*Como receber um array vazio com begin end
    esse erro do begin end passando um array vazio é problema do cliente?*/
    int V_6[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //int V_6[]{};
    //int temp_6{sizeof(V_6)/sizeof(V_6[0])};
    auto allof = graal::all_of(std::begin(V_6), std::end(V_6), p_int_2);
    //auto allof = graal::all_of(&V_6[0], &temp_6, p_int_2);
    std::cout << allof << std::endl << std::endl;

    auto anyof = graal::any_of(std::begin(V_6), std::end(V_6), p_int_2);
    //auto anyof = graal::any_of(&V_6[0], &temp_6, p_int_2);
    std::cout << anyof << std::endl << std::endl;
    
    auto noneof = graal::none_of(std::begin(V_6), std::end(V_6), p_int_2);
    //auto noneof = graal::none_of(&V_6[0], &temp_6, p_int_2);
    std::cout << noneof << std::endl << std::endl;

    /*é um unico array? se sim o first2 aponta alguma parte do array, se nao o tamanho maximo do array2
    tem que ser igual ao tamanho do array1?*/
    
    /*TODO questão 7equal_a*/

    /*A comparação é sequencial ou o algoritmo deve comparar se o elemento existe no vetor*/
    int V_6_1[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int V_6_2[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto equal_2 = graal::equal(std::begin(V_6_1), std::end(V_6_1),
                                std::begin(V_6_2), std::end(V_6_2), eq_int);
    std::cout << equal_2 << std::endl << std::endl;

    /*Os elementos do vetor so precisam ser reordenados por unicos ou
    tenho que ordenar de forma crescente?*/
    //int V_7[]{1,2,3,4,5,5,4,4,4,3,2,3,2,1};
    int V_7[]{1,1,2,2,3,4,4,5,6,1,2};
    graal::print_vector(std::begin(V_7), std::end(V_7));
    auto last7 = graal::unique(std::begin(V_7), std::end(V_7), eq_int);
    graal::print_vector(std::begin(V_7), last7);
    
	return 0;
}
