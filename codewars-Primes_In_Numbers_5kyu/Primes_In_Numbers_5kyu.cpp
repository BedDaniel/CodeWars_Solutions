#include <iostream>
#include <string>

class PrimeDecomp
{
public:
	static std::string factors(int lst) {

		std::ostringstream
			std::string result = "";
		for (int i = 2; i < lst; ++i)
		{
			int nTimes = 0; // 100 -- > (2**2)(5**2)

			while (lst % i == 0)
			{
				lst /= i;
				nTimes += 1;
			}
			if (nTimes > 1)
			{
				result += '('; result += (i + '0'); result += "**"; result += (nTimes + '0'); result += ')';
			}
			if (nTimes == 1)
			{
				result += '('; result += i; result += ')';
			}
		}
		return result;
	}
};


int main() {
	PrimeDecomp obj;
	std::cout << obj.factors(100) << '\n';

	return 0;
}