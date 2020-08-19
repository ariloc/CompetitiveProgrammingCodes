#include <bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
 
const ll INF = 1e13;
 
int main() {
    FAST_IO;
 
    ll N; cin >> N;
    ll rta = INF;
 
    for (ll i = 2; i*i <= N; i++)
        if (!(N % i)) {
            ll mini = min(N/i,i), maxi = max(N/i,i);
            if (!(maxi % mini) and (rta == INF or !(maxi % rta))) rta = min(rta,mini);
            else {rta = 1; break;}
        }
 
    cout << (rta == INF ? N : rta);
 
 
    return 0;
}