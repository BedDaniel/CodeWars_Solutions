/*
Write a function that accepts an array of 10 integers (between 0 and 9), 
that returns a string of those numbers in the form of a phone number.

Example
createPhoneNumber(int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}) // => returns "(123) 456-7890"

The returned format must be correct in order to complete this challenge.

Don't forget the space after the closing parentheses!
*/

#include <string>
#include <iostream>

std::string createPhoneNumber(const int arr [10]){
    std::string phoneNumber = "(";
    for(int i = 0; i < 10; ++i)
    {
        if(i==3){phoneNumber.append(") ");}
        if(i==6){phoneNumber.append("-");}

        phoneNumber += std::to_string(arr[i]);
    }
    return phoneNumber;
}

int main(){
    int tab[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::cout << createPhoneNumber(tab) << '\n';// => returns "(123) 456-7890"

    // std::string number = "";
    // int tab[3] = {1, 2, 3};
    
    // std::cout << tab[0] << '\n';
    // std::cout << number;
    return 0;
}

/* The most clever solution:

#include <string>

std::string createPhoneNumber(const int digits[10]) {
  std::string res = "(...) ...-....";
  for (unsigned is = 0, id = 0; is < res.length(); is++)
    if (res[is] == '.')
      res[is] = '0' + digits[id++];
  return res;
}

*/
