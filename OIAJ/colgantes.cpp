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

const int MAXN = 102;

int arr[MAXN];

int main() {
    FAST_IO;
    freopen("colgantes.in","r",stdin);
    freopen("colgantes.out","w",stdout);

    int N; cin >> N;
    forn (i,N) {
        int x;
        cin >> x;
        arr[x]++;
    }

    int v = 0, pT = 0;
    forn (i,MAXN)
        {v+=(arr[i]/2); pT += ((arr[i]/2)*2*i);}

    if (!v) cout << "no se puede";
    else cout << pT << ' ' << v;

    return 0;
}