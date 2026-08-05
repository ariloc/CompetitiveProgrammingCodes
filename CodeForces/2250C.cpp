#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define snd second
#define fst first
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int const MAXN = 5005;

ii ra[MAXN], rb[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        forn(i,n) {
            int l,r,u,v; cin >> l >> r >> u >> v;
            ra[i] = {l,r};
            rb[i] = {u,v};
        }

        int rta = 0;
        forn(i,n+1) {
            int m = n-i;

            bool posib = true;
            int cnt = 0;
            forn(j,n) {
                int l = ra[j].fst, r = ra[j].snd;
                int u = rb[j].fst, v = rb[j].snd;

                swap(u,v);
                u = m+1-u;
                v = m+1-v;

                --l, --r, --u, --v;

                int ldel = j-l, rdel = j-r;
                int udel = j-u, vdel = j-v;

                if (ldel > rdel) swap(ldel,rdel);
                if (udel > vdel) swap(udel,vdel);

                rdel++, vdel++;

                ldel = max(ldel, 0);
                rdel = max(rdel, 0);
                udel = max(udel, 0);
                vdel = max(vdel, 0);

                //cerr << ldel << ' ' << rdel << ' ' << udel << ' ' << vdel << ' ' << ' ' << i << "!!" << endl;
                
                if ((ldel <= cnt && cnt < rdel) || (udel <= cnt && cnt < vdel))
                    cnt++;
            }

            //cerr << "CUT" << endl;
                    
            if (cnt <= i) {
                rta = m;
                break;
            }
        }

        cout << rta << '\n';
    }

    return 0;
}
