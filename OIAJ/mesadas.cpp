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

const int MAXN = 2e5+2;

vector<ii> mesadas;

int L[MAXN], LISnd = 0;
multiset<int> restantes;

int solveLis(int &N) {
    int cantPilas = 1;
    forn (i,N) {
        int pos = upper_bound(L,L+LISnd,mesadas[i].snd) - L;
        if (pos+1 > LISnd) {
            LISnd = pos+1;
            L[pos] = mesadas[i].snd;
        }
        else {
            auto it = restantes.lower_bound(-mesadas[i].snd);
            if (it == restantes.end()) cantPilas++;
            else restantes.erase(it);
            restantes.insert(-mesadas[i].snd);
        }
    }
    return cantPilas;
}

int main() {
    //freopen("mesadas.in","r",stdin);
    //reopen("mesadas.out","w",stdout);

    int N;
    scanf("%d",&N);

    forn(i,N) {
        int x,y;
        scanf("%d %d",&x,&y);
        if (y < x) swap(x,y);
        mesadas.push_back({x,y});
    }

    sort(all(mesadas));

    printf("%d",solveLis(N));

    return 0;
}
