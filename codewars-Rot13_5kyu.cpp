/*
ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet. 
ROT13 is an example of the Caesar cipher.
Create a function that takes a string and returns the string ciphered with Rot13. 
If there are numbers or special characters included in the string, they should be returned as they are. 
Only letters from the latin/english alphabet should be shifted, like in the original Rot13 "implementation".
*/

#include <string>
#include <iostream>

std::string rot13(std::string msg)
{
    std::string result = "";
    for(char el : msg)
    {
        std::cout << el << ' ';
        if(el >= 65 and el <= 77)
        {
            result.push_back(el+13);
        }
        else if(el >= 78 and el <= 90)
        {
            result.push_back(65 - (90 - el) + 12);
        }
        else if (el >= 97 and el <= 109)
        {
            result.push_back(el + 13);
        }
        else if (el >= 110 and el <= 122)
        {
            result.push_back(97 - (122 - el) + 12);
        }
        else 
        {
            result.push_back(el);
        }
    }
    return result;
}


int main(){
    std::string t1 = "tttt";
    // std::string t2 = "zzzz";
    std::string t2 = "TEST";
    std::string t3 = "Test";
    std::string t4 = "AbCd";
    std::cout << "Result: " << rot13(t1) << std::endl;
    std::cout << "Result: " << rot13(t2) << std::endl;
    std::cout << "Result: " << rot13(t3) << std::endl;
    std::cout << "Result: " << rot13(t4) << std::endl;


    return 0;
}

/* The most clever solutions:

std::string rot13(std::string msg)
{
  for(auto& x : msg) 
    if (islower(x)) x = 'a'+(x-'a'+13)%26; 
    else if(isupper(x)) x = 'A'+(x-'A'+13)%26;
  return msg;
}


std::string rot13(std::string msg) {
  for (char& c : msg) {
    switch (c) {
      case 'A'...'M': case 'a'...'m': c += 13; break;
      case 'N'...'Z': case 'n'...'z': c -= 13; break;
    }
  }
  return msg;
}

std::string rot13(std::string msg)
{
    for (char &c : msg)
        if (::isalpha(c))
            c += 13 * ((::tolower(c) < 'n') * 2 - 1);
    return msg;
}

*/