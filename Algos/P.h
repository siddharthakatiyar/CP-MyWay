#ifndef P_H
#define P_H

using namespace std;

namespace Algos
{
    template <typename T>
    T P(T n, T r)
    {
        if (r > n - r) r = n - r;
        T ret = 1;
        for (T i = 0; i < r; ++i)
        {
            ret *= (n - i);
        }
        return ret;
    }
}

#endif // P_H