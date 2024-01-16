/*
Some numbers have funny properties. For example:

    89 --> 8¹ + 9² = 89 * 1
    695 --> 6² + 9³ + 5⁴= 1390 = 695 * 2
    46288 --> 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51

Given two positive integers n and p, we want to find a positive integer k, if it exists, 
such that the sum of the digits of n raised to consecutive powers starting from p is equal to k * n.

In other words, writing the consecutive digits of n as a, b, c, d ..., is there an integer k such that :
(ap+bp+1+cp+2+dp+3+...)=n∗k(a^p + b^{p + 1} + c^{p + 2} + d^{p + 3} + ...) = n * k(ap+bp+1+cp+2+dp+3+...)=n∗k

If it is the case we will return k, if not return -1.

Note: n and p will always be strictly positive integers.
*/

#include <iostream>
#include <cmath>

class DigPow
{
public:
    static int digPow(int n, int p){
        int new_n = n;
        int digits_num = log10(n) + 1;
        int num_to_pow = p + digits_num -1;
        int sum_of_pow = 0;
        int power;

        while(n != 0){
            power = n%10;
            //std::cout << '\n' << "n = " << n;
            sum_of_pow += pow(power, num_to_pow);
            n /= 10;
            --num_to_pow;
        }
        if(sum_of_pow % new_n== 0) { return sum_of_pow/new_n; }
        else { return -1;} 
        //std::cout << std::endl;
    }
};

int main(){
    DigPow number;
    std::cout << number.digPow(89, 2) << std::endl;
    return 0;
}

/* Most clever solution:

using namespace std;
class DigPow
{
public:
  static int digPow(int n, int p){
   long long sum=0;
   for(char digit : to_string(n)){
     sum+=pow(digit-'0',p++);
   }
   return (sum/n)*n==sum ? sum/n : -1;
  }
};

*/