#include <iostream>


int get_sum(int a, int b)
{
    if(a == b){return a;}
    else if(a > b)
    {
        int sum = 0;
        for(int i = b; b <= a; ++b)
        {
            sum +=b;
        }
        return sum;
    }
    else
    {
        int sum = 0;
        for(int i = a; a <= b; ++a)
        {
            sum +=a;
        }
        return sum;
    }
}

