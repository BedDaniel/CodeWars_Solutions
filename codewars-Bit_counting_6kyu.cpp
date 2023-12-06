/*
Write a function that takes an integer as input, and returns the number of bits that are equal to one in the binary 
representation of that number. You can guarantee that input is non-negative.

Example: The binary representation of 1234 is 10011010010, so the function should return 5 in this case
*/

#include <string>

unsigned int countBits(unsigned long long n){
    std::string binary = "";
    unsigned int num = 0;

    while(n != 0)
    {
        int bit = n % 2;
        if(bit == 1) { binary.insert(0, 1, '1'); ++num; }
        else{ binary.insert(0, 1, '0'); }
        n /= 2;
    }
    return num;
}

int main(){
    //std::cout << "\nResult: " << countBits(858104266499) << '\n';

}

/*
The most clever solution:

unsigned int countBits(unsigned long long n){
  int count = 0;
  while (n) {
    n &= (n-1);
    ++count;
  }
  return count;
}

*/