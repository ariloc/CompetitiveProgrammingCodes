#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 205;
const int MPOW = 10;

const int INF = 1e9+5;

/*
struct trie {
    map<char,trie> edges;
    int cnt = 0, numMe;

    void insert(const string &s, const int &me, int i = 0) {
        if (i == (int)s.size()) {cnt++; numMe = me;}
        else edges[s[i]].insert(s,me,i+1);
    }

    int find(const string &s, const int &me, int i = 0) {
        if (cnt) return (me&numMe);
        if (edges.count(s[i]))
            return edges[s[i]].find(s,me,i+1);
        else if (s[i] == '0') return edges['1'].find(s,me,i+1);
        else return edges['0'].find(s,me,i+1);
    }
};*/

int arr[MAXN],arr2[MAXN];
bool dp[MAXN][(1<<9)+5]; int val[MAXN][MAXN];
//trie T;

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    forn (i,n) cin >> arr[i];
    /*forn (i,m) {
        int x; cin >> x;
        bitset<MPOW> tmp(x);
        T.insert(tmp.to_string(),x);
    }

    ll rta = 0;
    forn (i,n) {
        bitset<MPOW> tmp(arr[i]);
        rta |= T.find(tmp.to_string(),arr[i]);
    }*/

    int mini = INF;
    forn (i,m) cin >> arr2[i];
    forn (i,n) {
        forn(j,m) val[i][j] = (arr[i]&arr2[j]);
    }
    forn(i,m) dp[0][val[0][i]] = true;

    forsn (i,1,n) forn (j,m)
        forn(k,(1<<9)+2)
            if (dp[i-1][k])
                dp[i][k | val[i][j]] = true;

    forn(j,(1<<9)+2) if (dp[n-1][j]) {cout << j << '\n'; break;}

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!