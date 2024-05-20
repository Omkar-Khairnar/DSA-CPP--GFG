#include <bits/stdc++.h>

using namespace std;

void fillLPS(vector<int> &lps, string &pat)
{
    lps[0] = 0;
    int i = 1, len = 0;
    int n = pat.size();

    while (i < n)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

vector<int> search(string pat, string txt)
{
    vector<int> lps(pat.size(), 0);
    // Filling LPS array using the function
    fillLPS(lps, pat);

    vector<int> ans;
    int n = txt.size();

    int i = 0, j = 0;
    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == pat.size())
        {
            ans.push_back(i - j + 1);
            j = lps[j - 1];
        }
        else if (i < n && txt[i] != pat[j])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{

    return 0;
}