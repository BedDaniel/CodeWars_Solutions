/*
You are given an array (which will have a length of at least 3, but could be very large) containing integers. 
The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer N. 
Write a method that takes the array as an argument and returns this "outlier" N.
*/

#include <vector>
#include <iostream>

int FindOutlier(std::vector<int> arr)
{   
    int evenCounter = 0;
    for(int i = 0; i < 3; ++i)
    {
        if(arr[i] % 2 == 0) { ++evenCounter;}
    }
    bool isEven = evenCounter > 1;
    for(auto el : arr)
    {
        if(( el % 2 == 0 and !isEven) or (el % 2 != 0 and isEven)) { return el; }
    }
    return 0;
}

/* The most clever solution:

int FindOutlier(std::vector<int> arr)
{
    int even;
  	int odd;
  
  	int evenCount = 0;
  	int oddCount = 0;
  
  	for (auto a : arr)
  	  	a % 2 == 0 ? (evenCount++, even = a) : (oddCount++, odd = a);
  
  	return evenCount < oddCount ? even : odd;
}
*/





int main(){
    std::vector<int> vec {2, -6, 8, -10, -3};
    std::vector<int> vec1 {4, 6, 5, 2, 4};
    std::vector<int> vec2 {9, 2, 3, 5, 7, 11, 3, 3};
    std::cout << '\n' << FindOutlier(vec) << '\n';
    std::cout << '\n' << FindOutlier(vec1) << '\n';
    std::cout << '\n' << FindOutlier(vec2) << '\n';
}