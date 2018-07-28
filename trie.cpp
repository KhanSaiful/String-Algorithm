#include<bits/stdc++.h>

using namespace std;


#define MAX 1000010
#define SZ(a) (int)a.size()
int trie[MAX][52], cnt[MAX], last;
string text;
void add() /// adding a string in trie tree
{
    int i, id, cur = 0;
    for(i = 0; i<text.size(); i++)
    {
        if(islower(text[i]))
            id = text[i] - 'a' + 26;
        else
            id = text[i] - 'A';
        if(trie[cur][id] == -1)
        {
            trie[cur][id] = ++last;
            memset(trie[last],-1,sizeof (trie[last]));
            cnt[last] = 0;
        }
        cur = trie[cur][id];
    }
    cnt[cur]++;
}
/// do clr(trie[0], -1) and last = 0 for every case
int get() /// get function is editable problem-wise and used for get data from trie tree
{
    int id, i, cur = 0;
    for(i = 0; i<text.size(); i++)
    {
        if(islower(text[i]))
            id = text[i] - 'a' + 26;
        else
            id = text[i] - 'A';
        if(trie[cur][id] == -1)return 0;
        cur = trie[cur][id];
    }
    return cnt[cur];
}
int main ()
{
    memset(trie[0],-1,sizeof (trie[0]));
    cin>>text;
    add();

    return 0;
}

