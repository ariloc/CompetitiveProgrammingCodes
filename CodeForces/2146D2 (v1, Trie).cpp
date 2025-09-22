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

int const MAXN = 2e5+5;
int const MAXK = 31;
int const MAXB = 1e7+5;

int arr[MAXN];
int trie[MAXB][2];
ii dat[MAXB];
int tnodes;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int l,r; cin >> l >> r;

        tnodes = 1;
        trie[0][0] = trie[0][1] = -1;
        dat[0] = {0,0};

        forsn(i,l,r+1) {
            int cur = 0;
            forn(k,MAXK) {
                if (trie[cur][(i&(1<<k))>>k] == -1) {
                    trie[cur][(i&(1<<k))>>k] = tnodes;
                    trie[tnodes][0] = trie[tnodes][1] = -1;
                    dat[tnodes] = {0,0};
                    tnodes++;
                }
                dat[cur].snd++;
                cur = trie[cur][(i&(1<<k))>>k];
            }
        }
        forsn(a,l,r+1) {
            int cur = 0, b = 0;
            forn(k,MAXK) {
                dat[cur].fst++;
                int ref = trie[cur][((1<<k) - (a&(1<<k)))>>k];
                if (ref != -1 && dat[ref].fst < dat[ref].snd) {
                    b |= (1<<k) - (a&(1<<k));
                    cur = ref;
                }
                else {
                    b |= (a & (1<<k));
                    cur = trie[cur][(a&(1<<k))>>k];
                }
            }
            arr[b-l] = a;
        }

        ll s = 0;
        forn(i,r-l+1) s += (arr[i] | (i+l));

        cout << s << '\n';
        forn(i,r-l+1) cout << arr[i] << ' ';
        cout << '\n';
    }

    return 0;
}
