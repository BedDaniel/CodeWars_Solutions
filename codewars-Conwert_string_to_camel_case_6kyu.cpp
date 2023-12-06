/*
Complete the method/function so that it converts dash/underscore delimited words into camel casing. 
The first word within the output should be capitalized only if the original word was capitalized 
(known as Upper Camel Case, also often referred to as Pascal case). The next words should be always capitalized.

Examples
"the-stealth-warrior" gets converted to "theStealthWarrior"
"The_Stealth_Warrior" gets converted to "TheStealthWarrior"
"The_Stealth-Warrior" gets converted to "TheStealthWarrior"
*/

#include <string>
#include <cctype>
#include <iostream>

std::string to_camel_case(std::string text) {
    std::string camelCase = "";
    camelCase.push_back(text[0]);
    for (size_t i = 1; i < text.size(); ++i) {
        if (std::isalpha(text[i])) {
            if (i == 0 || !std::isalpha(text[i - 1])) {
                camelCase.push_back(std::toupper(text[i]));
            } else {
                camelCase.push_back(std::tolower(text[i]));
            }
        }
    }
    return camelCase;
}

int main(){
    std::cout << '\n' << to_camel_case("the_stealth_-warrior-") << std::endl;
    std::cout << '\n' << to_camel_case("The_stealth_warrior") << std::endl;
    std::cout << '\n' << to_camel_case("A-B-C") << std::endl;

    return 0;
}

/* My solution works very well, but there were some issues with tests to this exercise 
The most clever solution, but not so fast as mine (this is O^2 complexity :/ )

#include <string>

std::string to_camel_case(std::string text)
{
  for(int i = 0; i < text.size(); ++i)
  {
    if(text[i] == '-' || text[i] == '_')
    {
      text.erase(i,1);
      text[i] = toupper(text[i]);
    }
  }
  return text;
}
*/