#ifndef C_H
#define C_H

using namespace std;

namespace Algos
{
    template <typename T>
    T C(T n, T r)
    {
        if (r > n - r) r = n - r;
        T ret = 1;
        for (T i = 0; i < r; ++i)
        {
            ret *= (n - i);
            ret /= (i + 1);
        }
        return ret;
    }
}

#endif // C_H