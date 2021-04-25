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

const int MAXN = 2e5+1;
const ll INF = 2e15;

ll arr[MAXN];
pair<ll,int> Q[MAXN];

void fastscan(ll &x) {
    register int c = 0;
    c = getchar(); bool neg = false;
    if (c == '-') {neg = true; c = getchar();}
    for(; c <= '9' && c >= '0'; c=getchar()) x = x*10 + c-'0';
    if (neg) x*=-1;
}

int main() {
    ll n=0,a=0,b=0; fastscan(n); fastscan(a); fastscan(b);
    forn(i,n) fastscan(arr[i+1]);
    forsn(i,1,n+1) arr[i] += arr[i-1];

    ll maxi = -INF;
    int st = 0, nd = 0;
    forsn(i,a,n+1) {
        while ((nd-st) > 0 and Q[st].snd < i-b) st++;
        if (arr[i-a] <= Q[st].fst) st = nd;
        while ((nd-st) > 0 and Q[nd-1].fst >= arr[i-a]) nd--;
        Q[nd++] = {arr[i-a],i-a};
        maxi = max(maxi,arr[i]-Q[st].fst);
    }

    printf("%lld",maxi);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
