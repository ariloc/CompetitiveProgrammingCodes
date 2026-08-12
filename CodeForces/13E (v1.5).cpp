#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1e5+5;
int const BLOCK = 320;

ii nxt[MAXN];
int arr[MAXN],n,m;

void calc(int b) {
    int lb = b*BLOCK, rb = min(n,(b+1)*BLOCK);
    if (lb >= n) return;
    dforsn(i,lb,rb) {
        if (i + arr[i] >= rb) nxt[i] = {i+arr[i],1};
        else {
            int ot = i+arr[i];
            nxt[i] = {nxt[ot].fst, nxt[ot].snd+1};
        }
    }
}

ii trail(int p) {
    int cnt = 0;
    while (nxt[p].fst < n) {
        cnt += nxt[p].snd;
        p = nxt[p].fst;
    }
    while (p+arr[p] < n) p += arr[p], ++cnt;
    return {p,cnt};
}

int main() {
    FAST_IO;

    cin >> n >> m;
    forn(i,n) cin >> arr[i];

    forn(i,BLOCK) calc(i);

    forn(i,m) {
        int typ; cin >> typ;
        if (!typ) {
            int a,b; cin >> a >> b; --a;
            arr[a] = b;
            calc(a/BLOCK);
        }
        else {
            int a; cin >> a; --a;
            ii auxi = trail(a);
            cout << auxi.fst+1 << ' ' << auxi.snd+1 << '\n';
        }
    }

    return 0;
}
