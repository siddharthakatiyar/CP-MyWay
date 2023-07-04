#ifndef STRING_ALGOS_H
#define STRING_ALGOS_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

namespace Algos
{
    vector<int> zFunction(string s)
    {
        int n = s.size();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; ++i)
        {
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
            {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

    vector<int> prefixFunction(string s)
    {
        int n = s.size();
        vector<int> pi(n);
        for (int i = 1; i < n; ++i)
        {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j])
                ++j;
            pi[i] = j;
        }
        return pi;
    }

    vector<int> manacher(string s)
    {
        int n = s.size();
        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; ++i)
        {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
                ++k;
            d1[i] = k--;
            if (i + k > r)
            {
                l = i - k;
                r = i + k;
            }
        }
        vector<int> d2(n);
        for (int i = 0, l = 0, r = -1; i < n; ++i)
        {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
                ++k;
            d2[i] = k--;
            if (i + k > r)
            {
                l = i - k - 1;
                r = i + k;
            }
        }
        vector<int> ret(n);
        for (int i = 0; i < n; ++i)
            ret[i] = 2 * d1[i] - 1;
        for (int i = 0; i < n - 1; ++i)
            ret[i + 1] = max(ret[i + 1], 2 * d2[i + 1]);
        return ret;
    }

    vector<int> suffixArray(string s)
    {
        int n = s.size();
        vector<int> p(n), c(n);
        {
            vector<pair<char, int>> a(n);
            for (int i = 0; i < n; ++i)
                a[i] = { s[i], i };
            sort(a.begin(), a.end());
            for (int i = 0; i < n; ++i)
                p[i] = a[i].second;
            c[p[0]] = 0;
            for (int i = 1; i < n; ++i)
            {
                if (a[i].first == a[i - 1].first)
                    c[p[i]] = c[p[i - 1]];
                else
                    c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        int k = 0;
        while ((1 << k) < n)
        {
            vector<pair<pair<int, int>, int>> a(n);
            for (int i = 0; i < n; ++i)
                a[i] = { { c[i], c[(i + (1 << k)) % n] }, i };
            sort(a.begin(), a.end());
            for (int i = 0; i < n; ++i)
                p[i] = a[i].second;
            c[p[0]] = 0;
            for (int i = 1; i < n; ++i)
            {
                if (a[i].first == a[i - 1].first)
                    c[p[i]] = c[p[i - 1]];
                else
                    c[p[i]] = c[p[i - 1]] + 1;
            }
            ++k;
        }
        return p;
    }

    vector<int> lcp(string s, vector<int> p)
    {
        int n = s.size();
        vector<int> rank(n);
        for (int i = 0; i < n; ++i)
            rank[p[i]] = i;
        int k = 0;
        vector<int> lcp(n - 1);
        for (int i = 0; i < n; ++i)
        {
            if (rank[i] == n - 1)
            {
                k = 0;
                continue;
            }
            int j = p[rank[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k])
                ++k;
            lcp[rank[i]] = k;
            if (k > 0)
                --k;
        }
        return lcp;
    }

    vector<int> zFunction(string s, string t)
    {
        string st = s + "#" + t;
        vector<int> z = zFunction(st);
        vector<int> ret;
        for (int i = s.size() + 1; i < st.size(); ++i)
            ret.push_back(z[i]);
        return ret;
    }

    vector<int> prefixFunction(string s, string t)
    {
        string st = s + "#" + t;
        vector<int> pi = prefixFunction(st);
        vector<int> ret;
        for (int i = s.size() + 1; i < st.size(); ++i)
            ret.push_back(pi[i]);
        return ret;
    }

    bool isPalindrome(string s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; ++i)
            if (s[i] != s[n - i - 1])
                return false;
        return true;
    }
};

#endif // STRING_ALGORITHMS_H