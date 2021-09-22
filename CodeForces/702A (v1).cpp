#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define fst first
#define snd second

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N,prev,accum = 1,maxim=0;
    cin >> N;
    cin >> prev;
    forn (i,N-1) {
        ll x;
        cin >> x;
        if (x > prev) {accum++;}
        else {
            if (maxim < accum)
                maxim = accum;
            accum = 1;
        }
        prev = x;
    }
    if (maxim < accum) maxim = accum;

    cout << maxim;
    return 0;
}