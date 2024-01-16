#include <string>
#include <algorithm>
#include <iostream>

std::string spinWords(const std::string &str)
{
    std::string result = "";
    for(int i = 0; i <= str.size(); ++i){
        std::string someStr = str;
        std::string chunk = "";
        if(someStr[i] == ' ')
        {
            if(someStr[i] > 4)
            {
                
                chunk += someStr.substr(0, i);
                std::cout << "Chunk: " << chunk << '\n';
                std::reverse(chunk.begin(), chunk.end());
                result += chunk;
                result += " ";
                chunk.clear();
                someStr.erase(0, i);
            }
            else if(someStr[i] < 5)
            {
                chunk += someStr.substr(0, i);
                result += chunk;
                result += " ";
                chunk.clear();
                someStr.erase(0, i);
            }
        //if(i = str.size()-1) { break; }
        }
    }
    result.pop_back();
    return result;
}

void loopIterator(std::string s){
    for(int i = 0; i < s.size(); ++i){
        std::cout << "Iterator i: " << i << " | Char: " << s[i] << '\n';
    }

}


int main(){
    std::cout << '\n' << spinWords("Hello to my application which could not work properly") << std::endl;
    // loopIterator("Hello to my application which could not work properly");
    return 0;
}