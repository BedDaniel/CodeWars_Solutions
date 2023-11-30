#include <vector>
#include <algorithm>
#include <iostream>


int findOdd(const std::vector<int>& numbers){
    if(numbers.size() == 1) { return numbers[0];}
    std::vector<int> newNumb(numbers);
    std::sort(newNumb.begin(), newNumb.end());
    int counter = 1;
    for(int i = 0; i < newNumb.size(); ++i)
    {
        //std::cout << std::endl << "i: " << i << " | Number: " << newNumb[i] << '\n';
        if(newNumb[i] == newNumb[i+1]) { counter +=1;}
        //std::cout << "Counter: " << counter << '\n';
        //if(newNumb[i] != newNumb[i+1])
        else
        {
            if(counter % 2 != 0) 
            {
                return newNumb[i];
            }
            counter =1;
        }
    }
    return 0;
}

int main(){
    std::cout << '\n';
    std::vector<int> vec {20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5};
    std::cout << findOdd(vec);
    std::cout << '\n';

}