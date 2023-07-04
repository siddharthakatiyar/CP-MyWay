#ifndef GCD_H
#define GCD_H

#include <vector>
using namespace std;

namespace Algos
{
    template <typename T>
    T gcd(T a, T b)
    {
        if (a < b) swap(a, b);
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    template <typename T>
    T gcd(vector<T> v)
    {
        T ret = v[0];
        for (int i = 1; i < v.size(); ++i)
        {
            ret = gcd(ret, v[i]);
        }
        return ret;
    }
}

#endif // GCD_H