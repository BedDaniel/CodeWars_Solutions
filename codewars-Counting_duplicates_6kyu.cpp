/*
Count the number of Duplicates

Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits 
that occur more than once in the input string. The input string can be assumed to contain only alphabets 
(both uppercase and lowercase) and numeric digits.
Example

"abcde" -> 0 # no characters repeats more than once
"aabbcde" -> 2 # 'a' and 'b'
"aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
"indivisibility" -> 1 # 'i' occurs six times
"Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
"aA11" -> 2 # 'a' and '1'
"ABBA" -> 2 # 'A' and 'B' each occur twice
*/

#include <string>
#include <algorithm>
#include <iostream>

std::size_t duplicateCount(const std::string& in)
{   
    std::size_t counter = 0;
    std::string copy = {in};
    for(int i = 0; i < copy.size(); ++i)
    {
        copy[i] = std::tolower(copy[i]);
    }
    std::sort(copy.begin(), copy.end());

    for(int i = 0; i < copy.size(); ++i)
    {
        if(copy[i] == copy[i+1] and copy[i] != copy[i+2])
        {
            counter += 1;
        }
    }
    return counter;
}



int main(){
    std::cout << duplicateCount("LubiePlacki");
    std::cout << std::endl;
    std::cout << duplicateCount("abcdabcdabcd");
    std::cout << std::endl;

    return 0;
}

/* Most clever solution:

#include <string>
#include <unordered_map>
#include <algorithm>

#include <cctype>

std::size_t duplicateCount(const char* in) {
  std::unordered_map<char, unsigned> counts;
  for (const char* c = in; *c != '\0'; ++c) {
    ++counts[tolower(*c)];
  }
  return std::count_if(cbegin(counts), cend(counts), [](const auto& count) {
      return count.second > 1;
    });
}
*/