/*
Complete the function scramble(str1, str2) that returns true if a portion of 
str1 characters can be rearranged to match str2, otherwise returns false.

Notes:
    Only lower case letters will be used (a-z). No punctuation or digits will be included.
    Performance needs to be considered.
*/

#include <string>
#include <iostream>
#include <algorithm>

// This wortks, but is very very slow for longer strins
// bool scramble(const std::string& s1, const std::string& s2){
//     std::string mixed = s1;
//     std::sort(mixed.begin(), mixed.end());
//     std::string match = s2;
//     std::sort(match.begin(), match.end());
//     std::string result = "";
//     for(size_t i = 0; i < s2.size(); ++i)
//     {
//         for (size_t j = 0; j < mixed.size(); ++j)
//         {
//             if(match[i] == mixed[j])
//             {
//                 result.push_back(mixed[j]);
//                 mixed.erase(j, 1);
//                 break;
//             }
//         }
//     }
//     return s2.size() == result.size();
// }

bool scramble(const std::string& s1, const std::string& s2) {
    std::unordered_map<char, int> charCount;

    for (char c : s1) {
        charCount[c]++;
    }
    for (char c : s2) {
        if (charCount.find(c) != charCount.end() && charCount[c] > 0) {
            charCount[c]--;
        } else {
            return false;
        }
    }
    return true;
}

int main(){
    std::cout << scramble("rkqodlw", "world") << '\n';
    std::cout << scramble("cedewaraaossoqqyt", "codewars") << '\n';
    std::cout << scramble("katas", "steak") << '\n';
    std::cout << scramble("scriptingjava", "javascript") << '\n';

    return 0;
}

/* The most clever solution and very easy to read, but not the fastest -  O(nlogn) complexity!
#include <algorithm>
#include <string>

bool scramble(std::string s1, std::string s2) {
  std::sort(begin(s1), end(s1));
  std::sort(begin(s2), end(s2));
  return std::includes(begin(s1), end(s1), begin(s2), end(s2));
}

Using unordered map is much faster O(n) complexity

*/