/*
The maximum sum subarray problem consists in finding the maximum sum of a contiguous subsequence in an array or list of integers:

maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4});
//should be 6: {4, -1, 2, 1}

Easy case is when the list is made up of only positive numbers and the maximum sum is the sum of the whole array. 
If the list is made up of only negative numbers, return 0 instead.

Empty list is considered to have zero greatest sum. Note that the empty list or array is also a valid sublist/subarray.
*/

#include <vector>
#include <iostream>

int maxSequence(const std::vector<int>& arr){
    if(arr.empty() == true) { return 0; }
    int negativesNumbers = 0;
    for (auto el : arr) { if (el < 0) { ++negativesNumbers; }}
    if(negativesNumbers == arr.size()) { return 0; }

    int sum = 0;
    int maxSum = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        
        for (int j = i; j < arr.size(); ++j)
        {
            sum+= arr[j];
            if(sum >= maxSum) { maxSum = sum;}
        }
        sum = 0;

    }
        // {-2, 1, -3, 4, -1, 2, 1, -5, 4}

    return maxSum;
}


int main(){
std::vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << maxSequence(vec) << std::endl;

}

/*  Most clever solution:
#include <vector>

using namespace std;

int maxSequence(const vector<int>& arr) {
	int localmax=0;
	int globalmax=0;
	for (int i = 0;i<arr.size();i++)
	{
		localmax = localmax + arr[i];
		if (localmax > globalmax)
			globalmax = localmax;
		if (localmax < 0)
			localmax = 0;
	}
	return globalmax;
}

*/