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

int const MAXN = 1e6+5;
int const MAXB = 30;

// consider represented reverse
// 000111 would be 111000
struct trie {
    trie* edges[2] = {NULL, NULL};

    int s = 0;

    void insert (int v, int i) {
        if (i > 0) {
            if (edges[v&1] == NULL) {
                edges[v&1] = new trie();
            }
            (*edges[v&1]).insert(v>>1,i-1);
        }
        ++s;
    }

    int search (int val, int k, int i, bool msb = false) {
        if (!i) return s;

        int r = 0;
        msb |= (k&1);

        int b = (val&1);
        if (!msb) {
            if (edges[b^1] != NULL) r += (*edges[b^1]).s; // 1
            if (edges[b] != NULL) r += (*edges[b]).search(val>>1,k>>1,i-1,msb); // 0
        }
        else {
            if (k&1) {
                if (edges[b^1] != NULL) r += (*edges[b^1]).search(val>>1,k>>1,i-1,msb); // 1
            }
            else {
                if (edges[b^1] != NULL) r += (*edges[b^1]).s; // 1
                if (edges[b] != NULL) r += (*edges[b]).search(val>>1,k>>1,i-1,msb); // 0
            }
        }

        return r;
    }
};

int arr[MAXN];
trie T;
 
int main() {
    FAST_IO;

    int n,k; cin >> n >> k;
    forn(i,n) cin >> arr[i];

    int revk = 0;
    forn(j,MAXB) revk |= (((k>>j)&1) << (MAXB-j-1));

    T.insert(0,MAXB);

    int cur = 0;
    ll rta = 0;
    forn(i,n) {
        cur ^= arr[i];

        int rev = 0;
        forn(j,MAXB) rev |= (((cur>>j)&1) << (MAXB-j-1));

        rta += T.search(rev,revk,MAXB);
        T.insert(rev,MAXB);
    }

    cout << rta << '\n';
 
    return 0;
}
