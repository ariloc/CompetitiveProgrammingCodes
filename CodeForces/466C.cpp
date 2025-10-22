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

int const MAXN = 5e5+5;

int arr[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    ll sum = 0;
    forn(i,n) cin >> arr[i], sum += arr[i];

    ll acc = 0, rta = 0;
    map<ll,int> reg;
    forn(i,n-1) {
        acc += arr[i];
        map<ll,int>::iterator it;
        if (!(acc&1) && (sum-acc) == acc/2 && (it = reg.find(acc/2)) != reg.end()) {
            rta += (*it).snd;
        }
        it = reg.find(acc);
        if (it == reg.end())
            reg[acc] = 1;
        else (*it).snd++;
    }

    cout << rta << '\n';

    return 0;
}
