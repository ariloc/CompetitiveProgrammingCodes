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
ii byl[MAXN],byr[MAXN];
set<pair<ii,int>> bylen;
set<int> ocu;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> arr[i];

    int l = 0;
    arr[n] = -1; // dummy
    forsn(i,1,n+1) {
        if (arr[i] != arr[i-1]) {
            byl[l] = {i-1,i-l};
            byr[i-1] = {l,i-l};
            bylen.insert({{i-l,-l},i-1});
            l = i;
        }
    }

    forn(i,n) ocu.insert(i);

    int cnt = 0;
    while (!bylen.empty()) {
        auto it = prev(bylen.end());
        int li = -(*it).fst.snd;
        int ri = (*it).snd;
        bylen.erase(it);

        forsn(i,li,ri+1) ocu.erase(i);
        
        auto it1 = ocu.lower_bound(li), it2 = ocu.upper_bound(ri);
        if (it1 != ocu.begin() && it2 != ocu.end()) {
            it1 = prev(it1);
            if (arr[*it1] == arr[*it2]) {
                ii auxi1 = byr[*it1], auxi2 = byl[*it2];
                int lens = auxi1.snd + auxi2.snd;
                byl[auxi1.fst] = {auxi2.fst, lens};
                byr[auxi2.fst] = {auxi1.fst, lens};
                bylen.erase({{auxi1.snd,-auxi1.fst},*it1});
                bylen.erase({{auxi2.snd,-*it2},auxi2.fst});
                bylen.insert({{lens,-auxi1.fst},auxi2.fst});
            }
        }
        cnt++;
    }

    cout << cnt << '\n';
   
    return 0;

}
