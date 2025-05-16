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

int arr[MAXN];
bitset<MAXN> done;
map<int,int> histo;
map<int,vi> inds;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;

        forn(i,n) cin >> arr[i];
        
        forn(i,n) done[i] = 0;
        histo.clear();
        inds.clear();
        
        forn(i,n) histo[arr[i]]++;

        int prv = -1;
        forn(i,n) {
            if (prv != arr[i]) {
                inds[arr[i]].pb(i);
            }
            prv = arr[i];
        }

        priority_queue<ii> Q;
        int clones = 0, left = n;
        while (left > 0) {
            while (!Q.empty() && Q.top().fst == (*histo.rbegin()).fst) {
                auto e = Q.top(); Q.pop();
                --left;
                histo[e.fst]--;
                if (!histo[e.fst]) histo.erase(e.fst);

                if (e.snd-1 >= 0 && !done[e.snd-1]) {
                    Q.push({arr[e.snd-1], e.snd-1});
                    done[e.snd-1] = true;
                }
                if (e.snd+1 < n && !done[e.snd+1]) {
                    Q.push({arr[e.snd+1], e.snd+1});
                    done[e.snd+1] = true;
                }
            }

            if (left > 0) {
                int cur = (*prev(histo.end())).fst;
                vi &toAdd = inds[cur];
                for (auto &k : toAdd) {
                    if (done[k]) continue;
                    Q.push({cur, k});
                    ++clones;
                    done[k] = true;
                }
            }
        }

        cout << clones << '\n';
    }

    return 0;
}
