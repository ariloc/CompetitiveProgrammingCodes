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

char bicisenda[MAXN];

void pintar(char &p, char &c) {
    if (!p) p = c;
    else {
        int a = p, b = c;
        if (a > b) swap(a,b);
        if (a == 'R' and b == 'Z') p = 'P';
        else if (a == 'A' and b == 'R') p = 'N';
        else if (a == 'A' and b == 'Z') p = 'V';
        else {
            if (a == 'N' and b == 'Z') p = 'M';
            if (a == 'R' and b == 'V') p = 'M';
            if (a == 'A' and b == 'P') p = 'M';
        }
    }
}

int main() {
    freopen("bicisenda.in","r",stdin);
    freopen("bicisenda.out","w",stdout);
    int B,t;
    scanf("%d %d",&B,&t);

    forn(i,t) {
        int p,f; char c;
        scanf("%d %d %c",&p,&f,&c);
        p--;
        forsn(j,p,f)
            pintar(bicisenda[j],c);
    }

    forn (i,B)
        printf("%c",(!bicisenda[i] ? '.' : bicisenda[i]));


    return 0;
}
