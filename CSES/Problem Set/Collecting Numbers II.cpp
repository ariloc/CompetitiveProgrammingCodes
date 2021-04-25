#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 2e5+2;

void fs (int &x) {
    int c; x = 0;
    c = getchar_unlocked();
    if (c < '0' || c > '9') c = getchar_unlocked();
    for (; c>='0' && c<='9'; c = getchar_unlocked())
        x = 10*x + c-'0';
}

int pos[MAXN],arr[MAXN];

int main() {
    int n,m; fs(n); fs(m);
    int cnt = 1; pos[0] = -1, pos[n+1] = MAXN;
    forn(j,n) fs(arr[j]), pos[arr[j]] = j;
    forsn(j,1,n+1) if (pos[j-1] > pos[j]) cnt++;
    forn(j,m) {
        int a,b; fs(a), fs(b), a--, b--;

        int am_pos = pos[arr[a]-1], bm_pos = pos[arr[b]-1], am_pos2 = pos[arr[a]+1], bm_pos2 = pos[arr[b]+1];
        pos[arr[b]] = a; pos[arr[a]] = b; swap(arr[a],arr[b]);

        cnt += (am_pos < a && pos[arr[b]-1] > b) + (bm_pos < b && pos[arr[a]-1] > a) -
               (bm_pos > b && pos[arr[a]-1] < a) - (am_pos > a && pos[arr[b]-1] < b) +
               (arr[b]+1 != arr[a] ? (am_pos2 > a && pos[arr[b]+1] < b) - (am_pos2 < a && pos[arr[b]+1] > b) : 0) +
               (arr[a]+1 != arr[b] ? (bm_pos2 > b && pos[arr[a]+1] < a) - (bm_pos2 < b && pos[arr[a]+1] > a) : 0);

        printf("%d\n",cnt);
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
