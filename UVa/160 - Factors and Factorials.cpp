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

const int MAXN = 105;

bitset<MAXN> done;
int fact[MAXN][MAXN];

void criba() {
    for (int i = 4; i < MAXN; i+=2) done[i] = true;
    for (int i = 3; i*i < MAXN; i+=2)
        if (!done[i])
            for (int j = i+i; j < MAXN; j+=i)
                done[j] = true;
}

int main() {
    criba();
    forsn(i,2,MAXN)
        if (!done[i])
            for (int j = i; j < MAXN; j+=i) {
                int me = j;
                while (!(me%i)) {fact[j][i]++; me/=i;}
            }

    forsn(i,1,MAXN) forsn(j,1,MAXN) fact[i][j] += fact[i-1][j];

    int x;
    while (scanf("%d",&x) != EOF) {
        if (!x) break;
        printf("%3d! =",x);
        int cnt = 0;
        forsn(i,2,MAXN) if (!done[i]) {
            if (!fact[x][i]) break;
            cnt++;
            if (cnt == 16) printf("\n      ");
            printf("%3d",fact[x][i]);
        }
        puts("");
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
