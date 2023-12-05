/*
A Narcissistic Number (or Armstrong Number) is a positive number which is the sum of its own digits, 
each raised to the power of the number of digits in a given base. 
In this Kata, we will restrict ourselves to decimal (base 10).

For example, take 153 (3 digits), which is narcissistic:
    1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153

and 1652 (4 digits), which isn't:
    1^4 + 6^4 + 5^4 + 2^4 = 1 + 1296 + 625 + 16 = 1938

The Challenge:
Your code must return true or false (not 'true' and 'false') depending upon whether the given number is 
a Narcissistic number in base 10. 
*/

#include <iostream>
#include <cmath>


bool narcissistic(int value) {
    int temp = value;
    int numDigits = log10(temp) + 1;
    int sum = 0;

    while (temp != 0) {
        sum += pow(temp % 10, numDigits);
        temp /= 10;
    }
    return value == sum;
}

int main(){
    std::cout << '\n' << narcissistic(153) << std::endl;
    std::cout << '\n' << narcissistic(7) << std::endl;
    std::cout << '\n' << narcissistic(371) << std::endl;
    std::cout << '\n' << narcissistic(1000) << std::endl;
    std::cout << '\n' << narcissistic(122) << std::endl;
    return 0;
}

/* The most clever solution this time is up here ^ :)
But it is not the fastest! This one is:

bool narcissistic( int value ){
  int sum = 0, size = 0, value_copy = value;
  while (value_copy)
  {
    size++;
    value_copy /= 10;
  }
  value_copy = value;
  while (value_copy)
  {
    int intermediate_sum = 1;
    for (int i = 1; i <= size; i++)
      intermediate_sum *= (value_copy % 10);
    sum += intermediate_sum;
    value_copy /= 10;
  }
  return sum == value;
}
*/