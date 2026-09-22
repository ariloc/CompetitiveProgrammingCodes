#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

string binario(string numero) {
    int num = 0;
    forn(i,numero.size()) {
        num *= 10;
        num += numero[i]-'0';
    }
    string r;
    while (num > 2) r.pb((num%2)+'0'), num /= 2;
    r.pb(num%2 + '0');
    if (num/2) r.pb(num/2 + '0');
    reverse(all(r));
    return r;
}
