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

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn(i,t) {
        int n,m;
        vi arr, swappable;
        vector<ii> arr2, segments;
        cin >> n >> m;

        forn(j,n) {
            int x;
            cin >> x;
            arr.push_back(x);
            arr2.push_back({x,j});
        }

        sort(all(arr2));

        forn (j,m) {
            int x;
            cin >> x;
            swappable.push_back(x);
        }

        sort(all(swappable));

        int i1 = -1, j1 = -1, lastDone = -1;
        forn (j,m) {
            if (i1 == -1) i1 = j1 = swappable[j];
            else if (swappable[j] == swappable[j-1]+1)
                j1 = swappable[j];
            else {
                segments.push_back({i1-1,j1});
                i1 = j1 = swappable[j];
                lastDone = j;
            }
        }
        segments.push_back({i1-1,j1});

        bool posib = true;
        forn (j,n) {
            if (arr2[j].fst != arr[j]) {
                int high = segments.size();
                int low = -1;

                auto it = lower_bound(all(segments),arr2[j].snd,[](const ii &a, const int &b){return a.snd < b;});
                if (it == segments.end()) {posib = false; break;}
                ii found = *it;

                if (arr2[j].snd <= found.snd and arr2[j].snd >= found.fst) {
                    if (!(j <= found.snd and j >= found.fst)) {posib = false; break;}
                }
                else {posib = false; break;}
            }
        }

        if (posib) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}