/*
The Fibonacci numbers are the numbers in the following integer sequence (Fn):
    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...
such as
    F(n) = F(n-1) + F(n-2) with F(0) = 0 and F(1) = 1.

Given a number, say prod (for product), we search two Fibonacci numbers F(n) and F(n+1) verifying
    F(n) * F(n+1) = prod.

Your function productFib takes an integer (prod) and returns an array:
[F(n), F(n+1), true] or {F(n), F(n+1), 1} or (F(n), F(n+1), True)
depending on the language if F(n) * F(n+1) = prod.

If you don't find two consecutive F(n) verifying F(n) * F(n+1) = prodyou will return
[F(n), F(n+1), false] or {F(n), F(n+1), 0} or (F(n), F(n+1), False)
F(n) being the smallest one such as F(n) * F(n+1) > prod.
*/

#include <vector>
#include <iostream>

typedef unsigned long long ull;
class ProdFib
{
public:
    static std::vector<ull> productFib(ull prod){
    std::vector<ull> result;
    int prev = 0;
    int next = 1;
    int sum = 0;

    for (int i = 0; sum <= prod; ++i)
    {
        if(sum == prod)
        {
            result.push_back(prev);
            result.push_back(next);
            result.push_back(1);
            return result;
        }
        sum = 0;
        next += prev;
        prev = next-prev;
        sum += (prev*next);
        std::cout << "Sum: " << sum << " | ";

    }
    result.push_back(prev);
    result.push_back(next);
    result.push_back(0);
    return result;
    }
};

int main(){
    ProdFib obj;
    std::vector<ull> result = obj.productFib(800);
    for (auto el : result) { std::cout << el << " | ";}
    std::cout << '\n';

    std::vector<ull> result2 = obj.productFib(40);
    for (auto el : result2) { std::cout << el << " | ";}
    std::cout << '\n';

    return 0;
}

/* The most clever solution:

#include <vector>
typedef unsigned long long ull;
class ProdFib
{
public:
  static std::vector<ull> productFib(ull prod)
  {
  		ull a = 0, b = 1;
      while (a * b < prod) {
      		std::swap(a, b);
          b += a;
      }
      return {a, b, a * b == prod};
  }
};

*/