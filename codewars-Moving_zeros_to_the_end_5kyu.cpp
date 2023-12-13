/*
Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

move_zeros({1, 0, 1, 2, 0, 1, 3}) // returns {1, 1, 2, 1, 3, 0, 0}
*/

#include <vector>
#include <iostream>

std::vector<int> move_zeroes(const std::vector<int>& input) {
    std::vector<int> output;
    output.reserve(input.size());
    auto it = output.begin();
    for (auto el : input)
    {
        if(el != 0) { output.insert(it, el); ++it;}
        else{output.push_back(el);};
    }
    return output;
}

int main(){
    std::vector<int> test = {1, 0, 2, 0, 3, 0, 4, 0, 5, 0};
    std::vector<int> newTest = move_zeroes(test);
    for (auto el : newTest)
    {
        std::cout << el << " | ";
    }
    std::cout << '\n';
    return 0;
}

/* The most clever solution:

auto move_zeroes(std::vector<int> v) {
  stable_partition(begin(v), end(v), std::negate());
  return v;
}


and also a bit simpler solution than mine:

std::vector<int> move_zeroes(const std::vector<int>& input) {
  std::vector<int> v(input.size(),0);
  int a = 0;
  for (auto c : input){
  	if(c != 0){
  		v[a] = c;
  		++a;
  	}
  }
  return v;
}
*/