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

const int MAXW = 1005;
const int MAXH = 12;
const int INF = 2e9;

bool mat[MAXH][MAXW];

int main() {
    FAST_IO;

    int h,w,k; cin >> h >> w >> k;

    forn(i,h) {
        string s; cin >> s;
        forn(j,w) mat[i][j] = s[j]-'0';
    }

    int rta = INF;
    forn(mk,1<<h) {
        vi id(h,0), cur_cnt(h,0);
        int prox_libre = 0, cuts = 0;
        forsn(i,1,h) {
            if ( ((mk&(1<<i)) > 0) != ((mk&(1<<(i-1))) > 0) ) prox_libre++;
            id[i] = prox_libre;
        }
        cuts = prox_libre;
        prox_libre++;

        bool posib = 1;
        forn(j,w) {
            vi acc(prox_libre, 0);
            forn(i,h) cur_cnt[id[i]] += mat[i][j], acc[id[i]] += mat[i][j];
            
            bool make_cut = 0;
            forn(i,prox_libre) {
                if (cur_cnt[i] > k) make_cut = 1;
                if (acc[i] > k) posib = 0;
            }

            if (make_cut) {
                cuts++;
                forn(i,prox_libre) cur_cnt[i] = acc[i];
            }
        }

        if (posib) rta = min(rta, cuts);
    }

    cout << rta;

    return 0;
}


