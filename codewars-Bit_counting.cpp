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