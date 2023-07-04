#ifndef RANGE_MINIMUM_QUERY_H
#define RANGE_MINIMUM_QUERY_H

#include <vector>
#include <algorithm>
using namespace std;

namespace Algos
{
    template <typename T>
    class RangeMinimumQuery
    {
    public:
        RangeMinimumQuery(vector<T>& v)
        {
            _n = v.size();
            _log = log2(_n) + 1;
            _st.assign(_n, vector<T>(_log));
            for (int i = 0; i < _n; ++i)
                _st[i][0] = v[i];
            for (int j = 1; j < _log; ++j)
            {
                for (int i = 0; i + (1 << j) <= _n; ++i)
                {
                    _st[i][j] = min(_st[i][j - 1], _st[i + (1 << (j - 1))][j - 1]);
                }
            }
        }

        T query(int l, int r)
        {
            int j = log2(r - l + 1);
            return min(_st[l][j], _st[r - (1 << j) + 1][j]);
        }

    private:
        int _n, _log;
        vector<vector<T>> _st;
    };
}

#endif // RANGE_MINIMUM_QUERY_H