#include <string>
#include <iostream>
#include <cmath>

int square_digits(int num) {
    std::string numbers = std::to_string(num);
    std::string sum = "";
    for(auto num : numbers){
        int pow = num - '0';
        int power = std::pow(pow, 2);
        sum.append(std::to_string(power));
    }
    return std::stoi(sum);
}



int main(){
    //square_digits(333);
    std::cout << std::endl;
    std::cout << square_digits(12345);
    std::cout << std::endl;

    return 0;
}