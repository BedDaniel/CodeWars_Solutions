/*
Your job is to write a function which increments a string, to create a new string.
    If the string already ends with a number, the number should be incremented by 1.
    If the string does not end with a number. the number 1 should be appended to the new string.

Examples:
foo -> foo1
foobar23 -> foobar24
foo0042 -> foo0043
foo9 -> foo10
foo099 -> foo100

Attention: If the number has leading zeros the amount of digits should be considered.
*/

#include <string>
#include <vector>
#include <iostream>

std::string incrementString(const std::string& str) {
  
  std::string s = str;
  
  if (s.empty() || !isdigit(s.back()))
    return s + "1";
  
  for (int i = s.size() - 1; i >= 0; i--) {
    char& c = s[i];
    if (isdigit(c)) {
        if (c < '9') 
        {
            c++;
            return s;
        } 
        else 
        {
            c = '0';
            continue;
        }
    } 
    else 
    {
        s.insert(i+1, "1");
        return s;
    }
  }
      
  return s;
}

int main(){
    std::string str = "foobar9";
    std::string str1 = "foobar001";
    std::string str2 = "foobar1111111111";
    std::string str3 = "foobar099";
    std::cout << incrementString(str) << std::endl;
std::cout << std::endl;
    std::cout << incrementString(str1) << std::endl;
std::cout << std::endl;
    std::cout << incrementString(str3) << std::endl;
std::cout << std::endl;
    return 0;
}

/*
#include <string>

std::string incrementString(const std::string &str1)
{
    std::string str = str1;
    int n = str.size(), s = 1, i = 0;
    for(i = 0; i < n && ('0' <= str[n - 1 - i] && str[n - 1 - i] <= '9'); i++)
    {
        int x = str[n - 1 - i] - 48 + s;
        s = x / 10;
        str[n - 1 - i] = (char)(x % 10 + 48);
    }
    if(s > 0)
      str.insert(n - i, "1");
    return str;
}

*/