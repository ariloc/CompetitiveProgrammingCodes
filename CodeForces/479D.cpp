#include <bits/stdc++.h>

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forsn(i,s,n) for (int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for (int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e5+5;

ll arr[MAXN];
set<ll> nums;

int main() {
    FAST_IO;

    ll n,l,x,y; cin >> n >> l >> x >> y;
    forn(i,n) cin >> arr[i];

    bool posib1 = 0, posib2 = 0;

    forn(i,n) {
        if (nums.count(arr[i]-x)) posib1 = true;
        if (nums.count(arr[i]-y)) posib2 = true;
        nums.insert(arr[i]);
    }

    if (posib1 && posib2) cout << 0;
    else if (posib1 != posib2)
        cout << "1\n" << (posib1 ? y : x);
    else {
        ll r = -1;
        forn(i,n) {
            ll tg = arr[i]+x;
            if (tg >= 0 && tg <= l && (nums.count(tg+y) || nums.count(tg-y))) r = tg;

            tg = arr[i]-x;
            if (tg >= 0 && tg <= l && (nums.count(tg+y) || nums.count(tg-y))) r = tg;

            tg = arr[i]+y;
            if (tg >= 0 && tg <= l && (nums.count(tg+x) || nums.count(tg-x))) r = tg;

            tg = arr[i]-y;
            if (tg >= 0 && tg <= l && (nums.count(tg+x) || nums.count(tg-x))) r = tg;
        }

        if (r == -1) cout << "2\n" << x << ' ' << y;
        else cout << "1\n" << r;
    }
    
    return 0;
}