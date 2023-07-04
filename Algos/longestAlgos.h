#ifndef LONGEST_ALGOS_H
#define LONGEST_ALGOS_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

namespace Algos
{
    template <typename T>
    class LongestCommonSubsequence
    {
    public:
        LongestCommonSubsequence(vector<T>& v1, vector<T>& v2)
        {
            _n = v1.size();
            _m = v2.size();
            _dp.assign(_n + 1, vector<int>(_m + 1));
            for (int i = 1; i <= _n; ++i)
            {
                for (int j = 1; j <= _m; ++j)
                {
                    if (v1[i - 1] == v2[j - 1])
                        _dp[i][j] = _dp[i - 1][j - 1] + 1;
                    else
                        _dp[i][j] = max(_dp[i - 1][j], _dp[i][j - 1]);
                }
            }
        }

        int length()
        {
            return _dp[_n][_m];
        }

        vector<T> sequence()
        {
            vector<T> ret;
            int i = _n, j = _m;
            while (i > 0 && j > 0)
            {
                if (_dp[i][j] == _dp[i - 1][j])
                    --i;
                else if (_dp[i][j] == _dp[i][j - 1])
                    --j;
                else
                {
                    ret.push_back(_dp[i][j]);
                    --i;
                    --j;
                }
            }
            reverse(ret.begin(), ret.end());
            return ret;
        }

    private:
        int _n, _m;
        vector<vector<int>> _dp;
    };

    template <typename T>
    class LongestIncreasingSubsequence
    {
    public:
        LongestIncreasingSubsequence(vector<T>& v)
        {
            _n = v.size();
            _dp.assign(_n, 1);
            _prev.assign(_n, -1);
            for (int i = 1; i < _n; ++i)
            {
                for (int j = 0; j < i; ++j)
                {
                    if (v[j] < v[i] && _dp[j] + 1 > _dp[i])
                    {
                        _dp[i] = _dp[j] + 1;
                        _prev[i] = j;
                    }
                }
            }
        }

        int length()
        {
            return *max_element(_dp.begin(), _dp.end());
        }

        vector<T> sequence()
        {
            int idx = max_element(_dp.begin(), _dp.end()) - _dp.begin();
            vector<T> ret;
            while (idx != -1)
            {
                ret.push_back(idx);
                idx = _prev[idx];
            }
            reverse(ret.begin(), ret.end());
            return ret;
        }

    private:
        int _n;
        vector<int> _dp, _prev;
    };

    template <typename T>
    class LongestPalindromicSubsequence
    {
    public:
        LongestPalindromicSubsequence(vector<T>& v)
        {
            _n = v.size();
            _dp.assign(_n, vector<int>(_n));
            for (int i = 0; i < _n; ++i)
                _dp[i][i] = 1;
            for (int i = 0; i < _n - 1; ++i)
            {
                if (v[i] == v[i + 1])
                    _dp[i][i + 1] = 2;
                else
                    _dp[i][i + 1] = 1;
            }
            for (int len = 3; len <= _n; ++len)
            {
                for (int i = 0; i + len - 1 < _n; ++i)
                {
                    int j = i + len - 1;
                    if (v[i] == v[j])
                        _dp[i][j] = _dp[i + 1][j - 1] + 2;
                    else
                        _dp[i][j] = max(_dp[i + 1][j], _dp[i][j - 1]);
                }
            }
        }

        int length()
        {
            return _dp[0][_n - 1];
        }

        vector<T> sequence()
        {
            vector<T> ret;
            int i = 0, j = _n - 1;
            while (i <= j)
            {
                if (_dp[i][j] == _dp[i + 1][j])
                    ++i;
                else if (_dp[i][j] == _dp[i][j - 1])
                    --j;
                else
                {
                    ret.push_back(_dp[i][j]);
                    ++i;
                    --j;
                }
            }
            return ret;
        }

    private:
        int _n;
        vector<vector<int>> _dp;
    };

    template <typename T>
    class LongestCommonSubarray
    {
    public:
        LongestCommonSubstring(vector<T>& v1, vector<T>& v2)
        {
            _n = v1.size();
            _m = v2.size();
            _dp.assign(_n + 1, vector<int>(_m + 1));
            for (int i = 1; i <= _n; ++i)
            {
                for (int j = 1; j <= _m; ++j)
                {
                    if (v1[i - 1] == v2[j - 1])
                        _dp[i][j] = _dp[i - 1][j - 1] + 1;
                    else
                        _dp[i][j] = 0;
                }
            }
        }

        int length()
        {
            return *max_element(_dp[0].begin(), _dp[0].end());
        }

        vector<T> sequence()
        {
            int idx = max_element(_dp[0].begin(), _dp[0].end()) - _dp[0].begin();
            vector<T> ret;
            while (idx != 0)
            {
                ret.push_back(idx);
                idx = _prev[idx];
            }
            reverse(ret.begin(), ret.end());
            return ret;
        }

    private:
        int _n, _m;
        vector<vector<int>> _dp;
    };

    template <typename T>
    class LongestIncreasingSubarray
    {
    public:
        LongestIncreasingSubarray(vector<T>& v)
        {
            _n = v.size();
            _dp.assign(_n, 1);
            _prev.assign(_n, -1);
            for (int i = 1; i < _n; ++i)
            {
                if (v[i] > v[i - 1])
                {
                    _dp[i] = _dp[i - 1] + 1;
                    _prev[i] = i - 1;
                }
            }
        }

        int length()
        {
            return *max_element(_dp.begin(), _dp.end());
        }

        vector<T> sequence()
        {
            int idx = max_element(_dp.begin(), _dp.end()) - _dp.begin();
            vector<T> ret;
            while (idx != -1)
            {
                ret.push_back(idx);
                idx = _prev[idx];
            }
            reverse(ret.begin(), ret.end());
            return ret;
        }

    private:
        int _n;
        vector<int> _dp, _prev;
    };

    template <typename T>
    class LongestPalindromicSubarray
    {
    public:
        LongestPalindromicSubarray(vector<T>& v)
        {
            _n = v.size();
            _dp.assign(_n, vector<int>(_n));
            for (int i = 0; i < _n; ++i)
                _dp[i][i] = 1;
            for (int i = 0; i < _n - 1; ++i)
            {
                if (v[i] == v[i + 1])
                    _dp[i][i + 1] = 2;
                else
                    _dp[i][i + 1] = 1;
            }
            for (int len = 3; len <= _n; ++len)
            {
                for (int i = 0; i + len - 1 < _n; ++i)
                {
                    int j = i + len - 1;
                    if (v[i] == v[j])
                        _dp[i][j] = _dp[i + 1][j - 1] + 2;
                    else
                        _dp[i][j] = max(_dp[i + 1][j], _dp[i][j - 1]);
                }
            }
        }

        int length()
        {
            return _dp[0][_n - 1];
        }

        vector<T> sequence()
        {
            vector<T> ret;
            int i = 0, j = _n - 1;
            while (i <= j)
            {
                if (_dp[i][j] == _dp[i + 1][j])
                    ++i;
                else if (_dp[i][j] == _dp[i][j - 1])
                    --j;
                else
                {
                    ret.push_back(_dp[i][j]);
                    ++i;
                    --j;
                }
            }
            return ret;
        }

    private:
        int _n;
        vector<vector<int>> _dp;
    };
}

#endif //ALGORITHM_DP_H