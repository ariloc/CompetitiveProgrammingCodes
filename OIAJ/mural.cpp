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

const int MAXN = 1001;

char mural[MAXN][MAXN];

void pintar(char &p, char &c) {
    if (!p) p = c;
    else {
        int a = p, b = c;
        if (a > b) swap(a,b);
        if (a == 'R' and b == 'Z') p = 'P';
        else if (a == 'A' and b == 'R') p = 'N';
        else if (a == 'A' and b == 'Z') p = 'V';
    }
}

int main() {
    freopen("mural.in","r",stdin);
    freopen("mural.out","w",stdout);
    int T,ph,pv;
    scanf("%d %d %d",&T,&ph,&pv);

    forn(i,ph) {
        int nf,cd,ch; char p;
        scanf("%d %c %d %d",&nf,&p,&cd,&ch);
        nf--; cd--;
        forsn(j,cd,ch)
            pintar(mural[nf][j],p);
    }

    forn(i,pv) {
        int nc,fd,fh; char p;
        scanf("%d %c %d %d",&nc,&p,&fd,&fh);
        nc--; fd--;
        forsn(j,fd,fh)
            pintar(mural[j][nc],p);
    }

    forn (i,T) {
        forn (j,T)
            printf("%c",(!mural[i][j] ? '.' : mural[i][j]));
        printf("\n");
    }

    return 0;
}
