#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int dp[1<<4][1<<4];
bool trans[1<<4][1<<4], reach[1<<4][1<<4];
ii dpmov[1<<4][1<<4];

bool palin (int mk, int l, int r) {
    forn(i,r-l+1) if (((mk&(1<<(l+i))) > 0) != ((mk&(1<<(r-i))) > 0)) return false;
    return true;
}

int flip(int mk, int l, int r) {
    forsn(i,l,r+1) mk ^= (1<<i);
    return mk;
}

int main() {
    FAST_IO;

    forn(i,1<<4) {
        forn(j,4) forsn(k,j+1,4) {
            if (palin(i,j,k)) {
                int x = flip(i,j,k);
                trans[i][x] = true;
                dpmov[i][x] = {k,j};
            }
        }
    }

    forn(i,1<<4) trans[i][i] = true;
    forn(i,1<<4) forn(j,1<<4) dp[i][j] = -1, reach[i][j] = trans[i][j];
    forn(i,1<<4) forn(j,1<<4) if(reach[i][j] && i != j) dp[i][j] = i;
    forn(ro,8) {
        forn(k,1<<4) forn(i,1<<4) forn(j,1<<4)
            if (reach[i][k] && trans[k][j] && !reach[i][j]) {
                reach[i][j] = true;
                dp[i][j] = k;
            }
    }

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        string a; cin >> a;
        string b; cin >> b;

        forn(i,n) a[i] -= '0', b[i] -= '0';

        vector<ii> mov;
        forn(i,n-4) {
            if (a[i] != b[i]) {
                if (a[i+1] == a[i]) {
                    a[i] ^= 1; a[i+1] ^= 1;
                    mov.pb({i,i+1});
                }
                else if (a[i+2] == a[i+1]) {
                    a[i+2] ^= 1;
                    mov.pb({i+1,i+2});
                    a[i] ^= 1;
                    mov.pb({i,i+1});
                }
                else {
                    a[i] ^= 1;
                    a[i+1] ^= 1;
                    a[i+2] ^= 1;
                    mov.pb({i,i+2});
                }
            }
        }

        int aa = a[n-1] | (a[n-2]<<1) | (a[n-3]<<2) | (a[n-4]<<3);
        int bb = b[n-1] | (b[n-2]<<1) | (b[n-3]<<2) | (b[n-4]<<3);

        
        vi auxi;
        while(dp[aa][bb] != -1) {
            auxi.pb(bb);
            bb = dp[aa][bb];
        }
        auxi.pb(bb);
        reverse(all(auxi));
        forsn(j,1,auxi.size()) {
            ii cur = dpmov[auxi[j-1]][auxi[j]];
            mov.pb({(3-cur.fst)+n-4,(3-cur.snd)+n-4});
        }

        cout << mov.size() << '\n';
        for (auto &j : mov) cout << j.fst+1 << ' ' << j.snd+1 << '\n';
    }

    return 0;
}
