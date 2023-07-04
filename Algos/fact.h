#ifndef FACT_H
#define FACT_H

using namespace std;

namespace Algos
{
    template <typename T>
    T fact(T n, T mod = 0)
    {
        T ret = 1;
        for (T i = 2; i <= n; ++i)
        {
            ret *= i;
            if (mod > 0) ret %= mod;
        }
        return ret;
    }
}

#endif // FACT_H