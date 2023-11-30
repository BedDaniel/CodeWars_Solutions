#include <string>
#include <algorithm>
#include <iostream>

std::size_t duplicateCount(const std::string& in)
{   
    std::size_t counter = 0;
    std::string copy = {in};
    //std::cout << '\n' << copy << '\n';
    for(int i = 0; i < copy.size(); ++i)
    {
        copy[i] = std::tolower(copy[i]);
    }
    //std::cout << '\n' << copy << '\n';
    std::sort(copy.begin(), copy.end());
    //std::cout << "Before unique: " << copy;
    //std::unique(copy.begin(), copy.end());
    //std::cout << "\nAfter unique: "<< copy;
    std::cout << '\n' << copy << '\n';

    for(int i = 0; i < copy.size(); ++i)
    {
        if(copy[i] == copy[i+1] and copy[i] != copy[i+2])
        {
            counter += 1;
        }
    }
    //std::cout << '\n' << "Counter: "<< counter;

    return counter;
}



int main(){
    std::cout << duplicateCount("LubiePlacki");
    std::cout << std::endl;
    std::cout << duplicateCount("abcdabcdabcd");
    std::cout << std::endl;

    return 0;
}