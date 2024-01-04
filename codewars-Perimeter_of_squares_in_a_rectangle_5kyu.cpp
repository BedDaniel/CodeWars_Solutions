/*
The drawing shows 6 squares the sides of which have a length of 1, 1, 2, 3, 5, 8. 
It's easy to see that the sum of the perimeters of these squares is : 4 * (1 + 1 + 2 + 3 + 5 + 8) = 4 * 20 = 80 

Could you give the sum of the perimeters of all the squares in a rectangle when there are n + 1 squares 
disposed in the same manner as in the drawing?

The function perimeter has for parameter n where n + 1 is the number of squares 
(they are numbered from 0 to n) and returns the total perimeter of all the squares.

perimeter(5)  should return 80
perimeter(7)  should return 216
*/

#include <iostream>

typedef unsigned long long ull;
class SumFct
{
    public:
    static ull perimeter(int n){
        if(n == 1) { return 4; }
        if(n == 2) { return 8; }
        ull sum = 8;            // 
        ull a = 1;
        ull b = 1;
        for(size_t i = 2; i <= n; ++i)
        {
            b+=a;               
            a=b-a;              
            sum += 4*b;
        }
        return sum;
    }
};


int main(){
    std::cout << '\n';
    SumFct obj;
    std::cout << obj.perimeter(2) << '\n';
    std::cout << obj.perimeter(3) << '\n';
    std::cout << obj.perimeter(4) << '\n';
    std::cout << obj.perimeter(5) << '\n';
    std::cout << obj.perimeter(20) << '\n';
    std::cout << obj.perimeter(30) << '\n';

    return 0;
}


/* The most clever solution
    It is solved by using golden ratio (phi)
#include <cmath>
typedef unsigned long long ull;
class SumFct
{
  public:
  static ull perimeter(int n) {
    return (4 * round((((std::pow(1.6180339887498948482045868343656381177203091798058L, n + 3) - std::pow(-0.6180339887498948482045868343656381177203091798058L, (n + 3))) / sqrt(5))) - 1));
  }
};

*/