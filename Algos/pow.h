#ifndef POW_H
#define POW_H

using namespace std;

namespace Algos
{
    template <typename T>
    T pow(T a, T b, T mod = 0)
    {
        T ret = 1;
        while (b > 0)
        {
            if (b & 1) ret *= a;
            a *= a;
            if (mod > 0)
            {
                ret %= mod;
                a %= mod;
            }
            b >>= 1;
        }
        return ret;
    }
}

#endif // POW_H