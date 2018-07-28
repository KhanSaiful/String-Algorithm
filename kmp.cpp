#include<bits/stdc++.h>

using namespace std;


int match[100010];
void compute_match_array(string pattern,string text)
{
    pattern+="#"+text;
    int m = pattern.size(), len = 0, i;
    match[0] = 0, i = 1;
// calculate match[i] for i = 1 to m - 1
    while(i < m)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            match[i] = len;
            i++;
        }
        else
        {
            if(len != 0) len = match[len - 1];
            else
            {
                match[i] = 0;
                i++;
            }
        }
    }
}
