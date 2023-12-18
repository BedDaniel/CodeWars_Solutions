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