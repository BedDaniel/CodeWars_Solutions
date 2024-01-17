/*
You like building blocks. You especially like building blocks that are squares. And what you even like more, is to arrange them into a square of square building blocks!
However, sometimes, you can't arrange them into a square. Instead, you end up with an ordinary rectangle! Those blasted things! If you just had a way to know, whether you're currently working in vain… Wait! That's it! You just have to check if your number of building blocks is a perfect square.

Task
Given an integral number, determine if it's a square number:
	In mathematics, a square number or perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself.
*/

#include <cmath>
#include <iostream>

bool is_square(int n)
{
	int num = std::sqrt(n);
	if (num * num == n) { return true; }
	else { return false; }
}

int main() {
	std::cout << is_square(9) << '\n';
	std::cout << is_square(4) << '\n';
	std::cout << is_square(5) << '\n';
	return 0;
}

/* The most clever solutions:

#include <cmath>

bool is_square(int n)
{
  return fmod(sqrt(n), 1) == 0;
}

#include <cmath>

bool is_square(int n)
{
  return fmod(sqrt(n), 1) == 0;
}


*/