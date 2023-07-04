#ifndef LCM_H
#define LCM_H

#include "gcd.h"
using namespace std;

namespace Algos
{
    template <typename T>
    T lcm(T a, T b)
    {
        return a * b / gcd(a, b);
    }

    template <typename T>
    T lcm(vector<T> v)
    {
        T ret = v[0];
        for (int i = 1; i < v.size(); ++i)
        {
            ret = lcm(ret, v[i]);
        }
        return ret;
    }
}

#endif // LCM_H