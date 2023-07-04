#ifndef KMP_H
#define KMP_H

#include <vector>
#include <string>
using namespace std;

namespace Algos
{
    class KMP
    {
    public:
        KMP(const string& pattern) : _pattern(pattern)
        {
            _lps.resize(pattern.size());
            _lps[0] = 0;
            int len = 0;
            int i = 1;
            while (i < pattern.size())
            {
                if (pattern[i] == pattern[len])
                {
                    len++;
                    _lps[i] = len;
                    i++;
                }
                else
                {
                    if (len != 0)
                        len = _lps[len - 1];
                    else
                    {
                        _lps[i] = 0;
                        i++;
                    }
                }
            }
        }

        vector<int> search(const string& text)
        {
            vector<int> ret;
            int i = 0;
            int j = 0;
            while (i < text.size())
            {
                if (_pattern[j] == text[i])
                {
                    i++;
                    j++;
                }
                if (j == _pattern.size())
                {
                    ret.push_back(i - j);
                    j = _lps[j - 1];
                }
                else if (i < text.size() && _pattern[j] != text[i])
                {
                    if (j != 0)
                        j = _lps[j - 1];
                    else
                        i++;
                }
            }
            return ret;
        }

    private:
        string _pattern;
        vector<int> _lps;
    };
}

#endif // !KMP_H