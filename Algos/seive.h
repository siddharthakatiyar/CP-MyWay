#ifndef SEIVE_H
#define SEIVE_H

#include <vector>
using namespace std;

namespace Algos
{
    template <typename T>
    vector<T> seive(T n)
    {
        vector<T> ret;
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (T i = 2; i <= n; ++i)
        {
            if (isPrime[i])
            {
                ret.push_back(i);
                for (T j = i * i; j <= n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        return ret;
    }
}

#endif // SEIVE_H