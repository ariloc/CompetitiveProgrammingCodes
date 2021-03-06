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

const int MAXK = 30;
const int MAXN = 2e5+5;

void fastscan(int &x) {
    int c = 0; x = 0;
    c=getchar_unlocked();
    if (c<'0' || c>'9') c=getchar_unlocked();
    for(; c>='0' && c<='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

void fastprint(int x) {
    char num[12];
    sprintf(num,"%d",x);
    for(int i = 0; num[i]; i++) putchar_unlocked(num[i]);
}

int S[MAXK][MAXN];

int main() {
    int n,q; fastscan(n); fastscan(q);

    forn(i,n) fastscan(S[0][i+1]);
    forsn(i,1,MAXK) forsn(j,1,n+1) S[i][j] = S[i-1][S[i-1][j]];

    forn(i,q) {
        int x,k; fastscan(x); fastscan(k);
        forn(i,MAXK)
            if(k&(1<<i)) x = S[i][x];
        fastprint(x); putchar_unlocked('\n');
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
