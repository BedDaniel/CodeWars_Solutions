#include <string>
#include <iostream>
#include <unordered_map>

std::string duplicate_encoder(const std::string& word){
    std::unordered_map<char, int> charCount;
    std::string copy = word;
    for(char & c : copy) { c = std::tolower(c); }

    for (char c : copy) { charCount[c]++; }

    for (char& c : copy) 
    {   
        if (charCount[c] >= 2) { c = ')'; }
        else (c = '('); 
    }
    return copy;
}


int main(){
    std::cout << '\n' << duplicate_encoder("abcdabceabcf");
    return 0;
}