#include <vector>
#include <iostream>

int stray(std::vector<int> numbers) {
    for(int i = 0; i < numbers.size(); ++i)
    {
        if(numbers[i]==numbers[i+1]){continue;}
        else if(numbers[i]!=numbers[i+1] and numbers[i+1]==numbers[i+2])
            {return numbers[i];}
        else
        {
            return numbers[i+1];
        }
    }

    return 0;
};

int main(){
    std::vector<int> vec {1, 4, 1, 1, 1};
    std::cout << stray(vec);



    return 0;
}