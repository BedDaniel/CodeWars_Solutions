/*
Move the first letter of each word to the end of it, then add "ay" to the end of the word. 
Leave punctuation marks untouched.

Examples

pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
pigIt('Hello world !');     // elloHay orldway !

*/

#include <string>
#include <iostream>
#include <cctype>

std::string pig_it(std::string str)
{   
    std::string newString = "";
    std::string word = "";

    for (char el : str)
    {
        if(std::isalpha(el))
        {
            word += el;
        }
        else
        {
            if(!word.empty())
            {
                newString += word.substr(1) + word[0] + "ay" + el;
                word.clear();
            }
            else
            {
                newString += el;
            }
        }
    }

    if(!word.empty())
    {
        newString += word.substr(1) + word[0] + "ay";
    }

    return newString;
}

int main(){
    std::cout << pig_it("Pig latin is cool") << std::endl;
    std::cout << pig_it("Hello world !") << std::endl;
    return 0;
}

/* The most clever solution:

#include <string>
#include <regex>
using namespace std;
string pig_it(string Z) {
    regex reg(("(\\w)(\\w*)(\\s|$)"));
    return regex_replace(Z, reg, "$2$1ay$3");
}

*/