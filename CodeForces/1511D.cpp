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

const int MAXN = 2e5+5;

int n,k;
set<string> done;
string seq;

// de Bruijn
void dfs (string s) {
    forn(i,k) {
        string aux = s; aux += (i+'a');
        if (!done.count(aux)) 
            done.insert(aux), dfs(aux.substr(1)), seq.pb(i+'a');
    }
}

int main() {
    FAST_IO;

    cin >> n >> k;

    dfs("a"); seq.pb('a');

    if ((int)seq.size() >= n) cout << seq.substr(0,n);
    else {
        seq.pop_back();
        string r = seq;
        while ((int)r.size() < n) r += seq;
        cout << r.substr(0,n);
    }
    
    return 0;
}