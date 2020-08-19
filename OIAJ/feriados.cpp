#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e6+2;

bitset<MAXN> dias;

int main() {
    int N,D,F;
    scanf("%d %d %d",&N,&D,&F);

    forn (i,N) {
        int x; scanf("%d",&x);
        dias[x-1] = true;
    }

    //Sliding Window
    int i = 0, best = -1, suma = 0;
    suma += !dias[i];
    forsn (j,1,D+1) {
        best = max(best,j-i);

        suma += !dias[j];

        while (suma > F)
            {suma -= !dias[i]; i++;}
    }
    printf("%d",best);
    return 0;
}
