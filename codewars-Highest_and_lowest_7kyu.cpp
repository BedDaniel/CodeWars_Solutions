#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>


std::string highAndLow(const std::string& numbers){
    std::istringstream iss(numbers);
    std::vector<int> nums;

    int num;
    while (iss >> num) {
        nums.push_back(num);
    }

    auto minMax = std::minmax_element(nums.begin(), nums.end());

    return std::to_string(*minMax.second) + " " + std::to_string(*minMax.first);
}

int main(){
    std::cout << highAndLow("1 2 3 4 5") << '\n';// return "5 1"
    std::cout << highAndLow("1 2 -3 4 5") << '\n';// return "5 -3"
    std::cout << highAndLow("1 9 3 4 -5") << '\n';// return "9 -5"




}