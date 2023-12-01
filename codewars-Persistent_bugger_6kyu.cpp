/*
Write a function, persistence, that takes in a positive parameter num and returns its multiplicative persistence, 
which is the number of times you must multiply the digits in num until you reach a single digit.
39 --> 3 (because 3*9 = 27, 2*7 = 14, 1*4 = 4 and 4 has only one digit)
999 --> 4 (because 9*9*9 = 729, 7*2*9 = 126, 1*2*6 = 12, and finally 1*2 = 2)
4 --> 0 (because 4 is already a one-digit number)
*/
#include <iostream>
#include <vector>

int persistence(long long n){
    std::vector<int> newNumb;
    int counterOfMultiplicative = 0;
    int num = n;

while(num >= 10)
{
    newNumb.clear();
    while(num != 0)
    {   
        newNumb.push_back(num % 10);
        num /= 10;
    }
    int b = 1;
    for(int i = 0; i < newNumb.size(); ++i)
    {
        b *= newNumb[i];
    }
    num = b;
    ++counterOfMultiplicative;
}
return counterOfMultiplicative;
}

/* The most clever solution:

int persistence(long long n) {
  long long p = 1;
  if (n < 10) { return 0; } 
  while (n > 0) { p = (n % 10) * p; n = n/10; }
  return persistence(p) + 1;
}
*/

int main(){
    std::cout << persistence(39) << std::endl;
    std::cout << persistence(999) << std::endl;
    std::cout << persistence(123) << std::endl;
    return 0;
}