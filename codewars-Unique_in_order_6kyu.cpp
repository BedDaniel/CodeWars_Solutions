/*
Implement the function unique_in_order which takes as argument a sequence and returns a list of items 
without any elements with the same value next to each other and preserving the original order of elements.

For example:
uniqueInOrder("AAAABBBCCDAABBB") == {'A', 'B', 'C', 'D', 'A', 'B'}
uniqueInOrder("ABBCcAD")         == {'A', 'B', 'C', 'c', 'A', 'D'}
uniqueInOrder([1,2,2,3,3])       == {1,2,3}
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_set>

using namespace std;
template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
    vector<T> res;

    unique_copy (iterable.begin(), iterable.end(), std :: back_inserter(res));
    return res;
}
std::vector<char> uniqueInOrder(const std::string& iterable){
    vector<char> res;

    unique_copy (iterable.begin(), iterable.end(), std :: back_inserter(res));
    return res;
}

int main(){
    std::string v = "1231231234512";
    std::vector<int> vec {1, 2, 6, 7, 8, 3, 4, 5, 1, 2, 1, 2, 3, 4, 5};
    std::vector<char> vec2 {'1', '2', '3', '1', '2', '3', '4', '5', '1', '2'};
    uniqueInOrder(v);
    std::cout << std::endl;
    uniqueInOrder(vec);
    std::cout << std::endl;
    uniqueInOrder(vec2);
    return 0;
}