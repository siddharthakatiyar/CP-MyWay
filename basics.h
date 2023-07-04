#ifndef BASICS_H
#define BASICS_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

namespace Basics
{
    template <typename T>
    class ReadWrite
    {
    public:
        static vector<T> readVector()
        {
            int n;
            cin >> n;
            vector<T> v(n);
            for (int i = 0; i < n; ++i)
                cin >> v[i];
            return v;
        }

        static vector<vector<T>> readMatrix()
        {
            int n, m;
            cin >> n >> m;
            vector<vector<T>> v(n, vector<T>(m));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    cin >> v[i][j];
            return v;
        }

        static void writeVector(vector<T>& v)
        {
            for (int i = 0; i < v.size(); ++i)
                cout << v[i] << " ";
            cout << endl;
        }

        static void writeMatrix(vector<vector<T>>& v)
        {
            for (int i = 0; i < v.size(); ++i)
            {
                for (int j = 0; j < v[i].size(); ++j)
                    cout << v[i][j] << " ";
                cout << endl;
            }
        }
    };

    class String
    {
    public:
        static vector<string> split(string& s, char delim)
        {
            vector<string> ret;
            int i = 0, j = 0;
            while (j < s.size())
            {
                if (s[j] == delim)
                {
                    ret.push_back(s.substr(i, j - i));
                    i = j + 1;
                }
                ++j;
            }
            ret.push_back(s.substr(i, j - i));
            return ret;
        }
    };

    template <typename T>
    bool comp(T& a, T& b)
    {
        return a < b;
    }

    template <typename T>
    bool comp(vector<T>& a, vector<T>& b)
    {
        if (a.size() != b.size())
            return a.size() < b.size();
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] != b[i])
                return a[i] < b[i];
        }
        return false;
    }

    template <typename T>
    bool comp(pair<T, T>& a, pair<T, T>& b)
    {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    }

    template <typename T>
    bool compr(T& a, T& b)
    {
        return a > b;
    }

    template <typename T>
    bool compr(vector<T>& a, vector<T>& b)
    {
        if (a.size() != b.size())
            return a.size() > b.size();
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] != b[i])
                return a[i] > b[i];
        }
        return false;
    }

    template <typename T>
    bool compr(pair<T, T>& a, pair<T, T>& b)
    {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second > b.second;
    }

    template <typename T>
    void swap(T& a, T& b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    template <typename T>
    void reverse(vector<T>& v)
    {
        int i = 0, j = v.size() - 1;
        while (i < j)
        {
            swap(v[i], v[j]);
            ++i;
            --j;
        }
    }
}

#endif // !BASICS_H