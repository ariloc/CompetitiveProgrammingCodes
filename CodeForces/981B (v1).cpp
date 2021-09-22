#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define fst first
#define snd second

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

set<ll> chem;
map<ll,ll> price;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m, sum = 0;
    cin >> n;
    forn(i,n) {
        ll a,b;
        cin >> a >> b;
        chem.insert(a);
        if (!price.count(a) or price[a] < b) price[a] = b;
    }
    cin >> m;
    forn(i,m) {
        ll a,b;
        cin >> a >> b;
        chem.insert(a);
        if (!price.count(a) or price[a] < b) price[a] = b;
    }
    for (auto &i: chem) {
        sum+=price[i];
    }
    cout << sum;
    return 0;
}