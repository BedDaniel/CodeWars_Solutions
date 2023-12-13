/*
The rgb function is incomplete. Complete it so that passing in RGB decimal values will result in a hexadecimal 
representation being returned. Valid decimal values for RGB are 0 - 255. 
Any values that fall out of that range must be rounded to the closest valid value.

Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.
Examples (input --> output):
255, 255, 255 --> "FFFFFF"
255, 255, 300 --> "FFFFFF"
0, 0, 0       --> "000000"
148, 0, 211   --> "9400D3"

*/

#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>

std::string rgb_to_hex(int r, int g, int b) {
    auto clamp = [](int value) -> int {
        return std::min(255, std::max(0, value));};
    r = clamp(r);
    g = clamp(g);
    b = clamp(b);
    std::stringstream stream;
    stream << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << r
           << std::setw(2) << g << std::setw(2) << b;

    return stream.str();
}

int main(){
    std::cout << rgb_to_hex(256, 256, 256) << std::endl;
    std::cout << rgb_to_hex(0, 256, 99) << std::endl;
    std::cout << rgb_to_hex(100, 200, 300) << std::endl;

    return 0;
}

/* One of the most clever solution:

#include <string>
using namespace std;

std::string rgb_to_hex(int r, int g, int b)
{
    stringstream s;
    char c[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    if(r<0) r=0;
    if(g<0) g=0;
    if(b<0) b=0;
    if(r>255) r=255;
    if(g>255) g=255;
    if(b>255) b=255;
    s<<c[(int)r/16]<<c[r%16]<<c[(int)g/16]<<c[g%16]<<c[(int)b/16]<<c[b%16];
    return s.str();
}

*/