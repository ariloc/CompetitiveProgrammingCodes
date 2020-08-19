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

const int MAXC = 80;
const int MAXN = 1e6+2;
const int INF = 1e9+5;

int categM[MAXC],categF[MAXC];
vector<vi> CF(MAXC),CM(MAXC);
pair<int,bool> J[MAXN]; // F -> true | M -> false

int main() {
    freopen("carrera.in","r",stdin);
    freopen("carrera.out","w",stdout);

    int A,cf,cm,L;
    scanf("%d %d %d %d",&A,&cf,&cm,&L);

    forn (i,cf) {
        int Fn,Fx;
        scanf("%d %d",&Fn,&Fx);
        categF[i] = Fx;
    }
    forn (i,cm) {
        int Mn,Mx;
        scanf("%d %d",&Mn,&Mx);
        categM[i] = Mx;
    }
    forn (i,A) {
        int E;
        char X;
        scanf("%d %c",&E,&X);
        if (X == 'F') {
            int ind = lower_bound(categF,categF+cf,E) - categF;
            J[i] = {ind,true};
        }
        else {
            int ind = lower_bound(categM,categM+cm,E) - categM;
            J[i] = {ind,false};
        }
     }
    forn (i,L) {
        int x;
        scanf("%d",&x);
        if (J[x-1].snd) { // es F
            if (CF[J[x-1].fst].size() < 3)
                CF[J[x-1].fst].push_back(x);
        }
        else { // es M
            if (CM[J[x-1].fst].size() < 3)
                CM[J[x-1].fst].push_back(x);
        }
    }
    forn (i,cf) {
        printf("%d ",i+1);
        for (auto &j : CF[i])
            printf("%d ",j);
        forn (j,3-CF[i].size()) printf("0 ");
        printf("\n");
    }
    forn (i,cm) {
        printf("%d ",i+1);
        for (auto &j : CM[i])
            printf("%d ",j);
        forn (j,3-CM[i].size()) printf("0 ");
        printf("\n");
    }

    return 0;
}
