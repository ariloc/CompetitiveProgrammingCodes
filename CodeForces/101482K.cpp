#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 2005;
const ll INF = 9e18;

int arr[MAXN],n,s,t;

ll getTime (int ind) {
    multiset<int> belt;
    forn(i,n) belt.insert(arr[i]);

    int pos = arr[ind]; ll r = 0;
    while (!belt.empty()) {
        auto it = belt.lower_bound(pos);
        if (it == belt.end()) it = belt.begin();
        r += ((*it)-pos+s)%s; pos = (*it);
        belt.erase(it); pos = (pos+t)%s;
        r += t;
    }

    return r;
}

int main() {
    FAST_IO;

    cin >> n >> s >> t;
    bool notEq = false;
    forn(i,n) cin >> arr[i], notEq |= (i && arr[i] != arr[i-1]);
    sort(arr,arr+n);

    ll mini = INF, maxi = 0, add = 0;
    forn(i,n) {
        ll aux = getTime(i);
        int prv = arr[(i-1+n)%n];
        ll top = aux + (prv != arr[i] || !notEq)*max(0,(arr[i]-prv-1+s)%s);

        mini = min(mini,aux);
        maxi = max(maxi,top);
        if (prv != arr[i] || !notEq) add += top*(top+1)/2 - (aux-1)*aux/2;
        notEq = true; // invierto a la primera
    }

    // armar frac
    ll dcm = __gcd((ll)s,add);
    add /= dcm, s /= dcm;

    cout << mini << '\n' << maxi << '\n';
    cout << add << '/' << s;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
