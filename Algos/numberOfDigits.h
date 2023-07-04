#ifndef NUMBER_OF_DIGITS_H
#define NUMBER_OF_DIGITS_H

using namespace std;

namespace Algos 
{
    template <typename T>
    T numberOfDigits(T n)
    {
        return (n == 0) ? 1 : (int)log10(n) + 1;
    }
}

#endif // NUMBER_OF_DIGITS_H