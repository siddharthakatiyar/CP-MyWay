#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H

#include <vector>
using namespace std;

// 1 based indexing
namespace Algos
{
    template <typename T>
    class FenwickTree
    {
    public:
        FenwickTree(int n) : _tree(n + 1, 0) {}

        void update(int i, T delta)
        {
            for (; i < _tree.size(); i += i & -i)
                _tree[i] += delta;
        }

        T query(int i)
        {
            T ret = 0;
            for (; i > 0; i -= i & -i)
                ret += _tree[i];
            return ret;
        }

        void add(T pos, T val)
        {
            for (; pos < _tree.size(); pos += pos & -pos)
                _tree[pos] += val;
        }

        T sum(T pos)
        {
            T ret = 0;
            for (; pos > 0; pos -= pos & -pos)
                ret += _tree[pos];
            return ret;
        }

        T sum(T l, T r)
        {
            return sum(r) - sum(l - 1);
        }

        T kth(T k)
        {
            T ret = 0;
            for (int i = _tree.size() - 1; i >= 0; i--)
            {
                ret += 1 << i;
                if (ret <= _tree.size() && _tree[ret] < k)
                    k -= _tree[ret];
                else
                    ret -= 1 << i;
            }
            return ret + 1;
        }

    private:
        vector<T> _tree;
    };
}

#endif // FENWICK_TREE_H