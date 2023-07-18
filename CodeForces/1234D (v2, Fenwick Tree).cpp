#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int const MAXN = 1e5+5;
int const MAXA = 26;

int FTA[MAXA][MAXN];

void setFT (int p, int v, int *FT) {
    p += 3;
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT (int p, int *FT) {
    p += 3;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int main() {
    FAST_IO;

    string s; cin >> s;

    forn(i,s.size()) setFT(i,1,FTA[s[i]-'a']);

    int q; cin >> q;
    forn(_,q) {
        int typ; cin >> typ;
        if (typ == 1) {
            int pos; char c; cin >> pos >> c; pos--;
            setFT(pos,-1,FTA[s[pos]-'a']);
            s[pos] = c;
            setFT(pos,1,FTA[s[pos]-'a']);
        }
        else {
            int l,r; cin >> l >> r, r--, l--;
            int cnt = 0;
            forn(i,MAXA) {
                cnt += ((getFT(r,FTA[i])-getFT(l-1,FTA[i])) > 0);
            }
            cout << cnt << '\n';
        }
    }
        
    return 0;
}
