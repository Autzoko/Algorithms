#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

namespace trie
{
    int next[MAXN][26], cnt;
    bool vis[MAXN], exist[MAXN];

    void init()
    {
        memset(next, 0, sizeof(next));
        cnt = 1;
    }

    void insert(const string& s)
    {
        int cur = 1;
        for(auto c : s)
        {
            if(!next[cur][c - 'a'])
                next[cur][c - 'a'] = ++cnt;
            cur = next[cur][c - 'a'];
        }
        exist[cur] = true;
    }

    int find(const string& s)
    {
        int cur = 1, ans;
        for(auto c : s)
        {
            if(!next[cur][c - 'a'])
                return 0;
            cur = next[cur][c - 'a'];
        }
        if(!exist[cur])
            ans = 0;
        else if(!vis[cur])
            ans = 1;
        else
            ans = 2;
        vis[cur] = true;
        return ans;
    }
}

int main()
{
    int n;
    cout << "Input number of words: " << endl;
    cin >> n;
    trie::init();

    cout << "Input words: " << endl;
    while(n--)
    {
        string s;
        cin >> s;
        trie::insert(s);
    }

    int q;
    cout << "Input number of words to find: " << endl;
    cin >> q;
    cout << "Input words to find: " << endl;
    while(q--)
    {
        string s;
        cin >> s;
        switch (trie::find(s))
        {
        case 0:
            cout << "Not In Dictionary!" << endl;
            break;
        case 1:
            cout << "In Dictionary!" << endl;
            break;
        case 2:
            cout << "Not First Time Appeared!" << endl;
            break;
        }
    }
    return 0;
}