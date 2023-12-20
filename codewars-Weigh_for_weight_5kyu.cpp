/*
My friend John and I are members of the "Fat to Fit Club (FFC)". John is worried because each month a list with 
the weights of members is published and each month he is the last on the list which means he is the heaviest.

I am the one who establishes the list so I told him: "Don't worry any more, I will modify the order of the list". 
It was decided to attribute a "weight" to numbers. The weight of a number will be from now on the sum of its digits.

For example 99 will have "weight" 18, 100 will have "weight" 1 so in the list 100 will come before 99.
Given a string with the weights of FFC members in normal order can you give this string ordered by "weights" of these numbers?
*/

#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <utility>  

class WeightSort
{
public:
    static std::string orderWeight(const std::string &strng){
        if (strng.size() == 0) { return strng; }
        std::string result = "";
        int weight = 0;
        std::vector<std::pair<int, std::string>> vec;
        for (size_t i = 0; i <= strng.size(); ++i)
        {
                if(i == strng.size() or !std::isdigit(strng[i]))
                {
                    if(!result.empty()) 
                    {
                        vec.push_back({weight, result});
                        weight = 0;
                        result.clear();
                    }
                }
                else
                {   
                    weight += (strng[i] - '0');
                    result.push_back(strng[i]);
                }
        }            
        auto sorting = [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b)
        {
            if(a.first == b.first) { return a.second < b.second; }
            else { return a.first < b.first;}
        };
        std::sort(vec.begin(), vec.end(), sorting);
        for (size_t i = 0; i < vec.size(); ++i)
        {
            if (i > 0) { result += ' '; }
            result += vec[i].second;
        }
    // std::cout << "RESULT: " << result << '\n';
    return result;
    }
};

int main(){
    WeightSort obj;
    obj.orderWeight("103 123 4444 99 2000");
    obj.orderWeight("2000 10003 1234000 44444444 9999 11 11 22 123");

    return 0;
}

/* Most clever solutions:

#include <numeric>
#include <string>
#include <iterator>
#include <algorithm>
#include <sstream>

class WeightSort
{
public:
    static std::string orderWeight(const std::string &strng) {
      std::vector<std::string> inputs;
      std::istringstream iss(strng);
      std::copy(std::istream_iterator<std::string>(iss), 
                std::istream_iterator<std::string>(),
                std::back_inserter(inputs));
      std::sort(inputs.begin(), inputs.end(),
                [](const std::string& s1, const std::string& s2) {
                  auto sum_func = [](const char c, int acc) { return acc + static_cast<int>(c-'0'); };
                  int s1sum = std::accumulate(s1.begin(), s1.end(), 0, sum_func);
                  int s2sum = std::accumulate(s2.begin(), s2.end(), 0, sum_func);
                  if (s1sum == s2sum)
                    return s1 < s2;
                  else
                    return s1sum < s2sum;
                });
      std::ostringstream oss;
      std::copy(inputs.begin(), inputs.end(), std::ostream_iterator<std::string>(oss, " "));
      std::string s = oss.str();
      return s.substr(0, s.size()-1);
    }
};

*/