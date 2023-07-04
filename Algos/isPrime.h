#ifndef IS_PRIME_H
#define IS_PRIME_H

#include <vector>
using namespace std;

namespace Algos
{
    template <typename T>
    bool isPrime(T n)
    {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        for (T i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0) return false;
        }

        return true;
    }
}

#endif // IS_PRIME_H