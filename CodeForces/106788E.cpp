#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)c.size()
#define FAST_IO ios::sync_with_stdio(false);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

vector<string> const EMPT = {
    "....",
    "....",
    "....",
    "....",
    "....",
    "....",
    "...."
};

vector<string> const NUM[] = {
    {
        ".##.",
        "#..#",
        "#..#",
        "....",
        "#..#",
        "#..#",
        ".##."
    },
    {
        "....",
        "...#",
        "...#",
        "....",
        "...#",
        "...#",
        "...."
    },
    {
        ".##.",
        "...#",
        "...#",
        ".##.",
        "#...",
        "#...",
        ".##."
    },
    {
        ".##.",
        "...#",
        "...#",
        ".##.",
        "...#",
        "...#",
        ".##."
    },
    {
        "....",
        "#..#",
        "#..#",
        ".##.",
        "...#",
        "...#",
        "...."
    },
    {
        ".##.",
        "#...",
        "#...",
        ".##.",
        "...#",
        "...#",
        ".##."
    },
    {
        ".##.",
        "#...",
        "#...",
        ".##.",
        "#..#",
        "#..#",
        ".##."
    },
    {
        ".##.",
        "...#",
        "...#",
        "....",
        "...#",
        "...#",
        "...."
    },
    {
        ".##.",
        "#..#",
        "#..#",
        ".##.",
        "#..#",
        "#..#",
        ".##."
    },
    {
        ".##.",
        "#..#",
        "#..#",
        ".##.",
        "...#",
        "...#",
        ".##."
    },
};

void flip(vector<string> &a, vector<string> b) {
    forn(i,7) forn(j,5) {
        if (a[i][j] != b[i][j]) a[i][j] = '#';
        else a[i][j] = '.';
    }
}

void press(vector<string> &tab, int v) {
    flip(tab,NUM[v]);
}

map<vector<string>, vector<string>> stat;

int main() {
    FAST_IO;

    forn(i,10) {
        vector<string> ini = EMPT;
        press(ini,i);
        stat[ini].pb(string(1,i+'0'));
    }

    forsn(i,1,10) forn(j,10) {
        vector<string> ini = EMPT;
        press(ini,i);
        press(ini,j);
        stat[ini].pb(string(1,i+'0') + string(1,j+'0'));
    }

    vector<string> inp;
    forn(_,7) {
        string auxi; cin >> auxi;
        inp.pb(auxi);
    }

    auto it = stat.find(inp);
    if (it == stat.end())
        return cout << "impossible\n", 0;

    auto &vec = (*it).snd;
    for (auto &i : vec) cout << i << '\n';
   
    return 0;
}
