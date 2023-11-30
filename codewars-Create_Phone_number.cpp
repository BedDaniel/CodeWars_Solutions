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