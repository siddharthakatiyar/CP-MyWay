#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>
using namespace std;

namespace Algos
{
    template <typename T>
    int binarySearch(vector<T>& v, const T& key)
    {
        int low = 0;
        int high = v.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (key < v[mid])
            {
                high = mid - 1;
            }
            else if (key > v[mid])
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        return -1;
    }
}

#endif // BINARY_SEARCH_H