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

const int MAXN = 1e7+1;

bitset<MAXN> done;

int criba(int &a, int &b, int &c) {
    int cnt = 0;
    for (int i = 2; i <= c; i++) {
        if (done[i]) continue;
        for (int j = i; j <= b; j+=i)
            done[j] = true;
    }

    forsn(i,a,b+1)
        if (!done[i]) cnt++;

    return cnt;
}

int main() {
//    freopen("casi-primo.in","r",stdin);
//    freopen("casi-primo.out","w",stdout);

    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);

    printf("%d",criba(a,b,c));

    return 0;
}
