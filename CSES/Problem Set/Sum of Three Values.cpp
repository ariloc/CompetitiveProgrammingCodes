#include <iostream>
#include <algorithm>

#pragma GCC optimize ("O3")

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
//typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 5002;

ii arr[MAXN];

int main() {
    //FAST_IO;

    int n,x; scanf("%d %d",&n,&x);
    forn (i,n) arr[i].snd = i;
    forn (i,n) scanf("%d",&arr[i].fst);

    sort(arr,arr+n);

    int rta[3] = {-1,-1,-1};

    forn (k,n) {
        int i = 0;
        dforn (j,n) {
            while (i < j and (arr[i].fst + arr[j].fst + arr[k].fst) < x) i++;
            if (i >= j) break;
            if ((arr[i].fst + arr[j].fst + arr[k].fst) == x and i != j and i != k and j != k)
                {rta[0] = arr[i].snd; rta[1] = arr[j].snd; rta[2] = arr[k].snd; break;}
        }
        if (rta[0] != -1) break;
    }

    if (rta[0] != -1) printf("%d %d %d",rta[0]+1, rta[1]+1, rta[2]+1);
    else printf("IMPOSSIBLE");

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
