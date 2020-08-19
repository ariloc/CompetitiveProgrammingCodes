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

int n,a,b,k;

int usosPow(int x) {
    int restdmg = x % (a+b);
    if (!restdmg) return (a+b-1)/a;
    if (restdmg > a) return (restdmg-1)/a;
    return 0;
}

vi monst;

int main() {
    //FAST_IO;

    int r = 0;
    scanf("%d %d %d %d",&n,&a,&b,&k);
    forn (i,n) {
        int x;
        scanf("%d",&x);
        monst.push_back(usosPow(x));
    }

    sort(all(monst));

    int j = 0;
    for (auto &j : monst) {
        k -= j;
        if (k < 0) break;
        r++;
    }

    printf("%d",r);

    return 0;
}