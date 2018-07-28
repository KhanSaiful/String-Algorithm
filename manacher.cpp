#include<bits/stdc++.h>

using namespace std;
#define SZ(a) (int)a.size()
string s, t;
void prepare_string()
{
    int i;
    t = "^#";
    for(i = 0; i < SZ(s); i++)
        t += s[i], t += "#";
    t += "$";
}
int manacher()
{
    prepare_string();
    int P[SZ(t)], c = 0, r = 0, i, i_mirror, n = SZ(t) - 1;
    for(i = 1; i < n; i++)
    {
        i_mirror = (2 * c) - i;
        P[i] = r > i? min(r - i, P[i_mirror]) : 0;
        while(t[i + 1 + P[i]] == t[i - 1 - P[i]])
            P[i]++;
        if(i + P[i] > r)
        {
            c = i;
            r = i + P[i];
        }
    }
    return *max_element(P + 1, P + n); /// longest palindrome substrings informations can be found from array P
}
int main()
{
    cin>>s;
    manacher();
    return 0;
}



