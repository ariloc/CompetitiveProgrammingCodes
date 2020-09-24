
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

const int MAXN = 1e6+5;

bitset<MAXN> done;

int main() {
    for (int i = 4; i < MAXN; i+=2) done[i] = true;
    for (int i = 3; i*i < MAXN; i+=2)
        if (!done[i])
            for (int j = i+i; j < MAXN; j+=i)
                done[j] = true;

    char s[10],rev[10];
    while (scanf("%s",s) != EOF) {
        int me; sscanf(s,"%d",&me);
        memset(rev,0,sizeof(rev));
        int sz = strlen(s); int ind = 0;
        dforn(i,sz) rev[ind++] = s[i];
        int revMe; sscanf(rev,"%d",&revMe);

        printf("%d is %s.\n",me,(done[me] ? "not prime" : (!done[revMe] and revMe != me) ? "emirp" : "prime"));
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
