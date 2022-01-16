#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXA = 26;
const int MAXN = 1e5+5;

struct trie {
    map<char,trie> edges;
    bool nd = 0;

    void insert (const string &s, int i = 0) {
        if (i == (int)s.size()) nd = true;
        else edges[s[i]].insert(s,i+1);
    }
};

trie T;

bool dfs (trie &mT) {
    for (auto &i : mT.edges)
        if (!dfs(i.snd)) return true;
    return false;
}

bool dfs2 (trie &mT) {
    if (mT.edges.empty()) return true;
    for (auto &i : mT.edges)
        if (!dfs2(i.snd)) return true;
    return false;
}

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;
    forn(i,n) {
        string s; cin >> s;
        T.insert(s);
    }

    int can_win = dfs(T);
    int can_lose = dfs2(T);
    if (can_win) {
        if (can_lose) printf("First");
        else printf("%s",k&1 ? "First" : "Second");
    }
    else printf("Second"); // empiezo perdiendo, entonces no puedo revertirs

    return 0;
}