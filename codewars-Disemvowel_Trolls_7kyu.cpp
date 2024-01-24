/*
Trolls are attacking your comment section!
A common way to deal with this situation is to remove all of the vowels from the trolls' comments, neutralizing the threat.
Your task is to write a function that takes a string and return a new string with all vowels removed.
For example, the string "This website is for losers LOL!" would become "Ths wbst s fr lsrs LL!".
Note: for this kata y isn't considered a vowel.

*/

#include <string>
#include <iostream>


std::string disemvowel2(const std::string& str) {
	std::string result = "";
	for (auto x : str)
	{
		if (x == 'a' or x == 'e' or x == 'o' or x == 'i' or x == 'u' or x == 'A' or x == 'E' or x == 'O' or x == 'I' or x == 'U')
		{
			continue;
		}
		else result.push_back(x);
	}
	return result;
}

int main() {
	std::string test = "Hello World!";
	std::cout << test << '\n';
	std::cout << disemvowel2(test) << '\n';
	std::cout << "Hello world";
	return 0;
}


/* Most clever solutions:
* simple, but VERY slow solution
*# include <string>
# include <regex>
std::string disemvowel(std::string str)
{
  std::regex vowels("[aeiouAEIOU]");
  return std::regex_replace(str, vowels, "");
}

This one is much faster:
# include <string>
std::string disemvowel(std::string str)
{
  std::string result;
  for(size_t i = 0; i < str.size(); ++i)
  {
	char c = str[i];
	switch(c)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		break;

		default:
		result += c;
	}
  }

  return result;
}

*

*/