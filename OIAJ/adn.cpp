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

const int MAXK = 10;
const int MAXN = 200001;
const int INF = 1000000;

string a,b;
int l1,l2,K;
int DP[MAXK*2+1][MAXN]; // todo a 0 es que no hay nada

int lev (int i, int j){ // consideramos 0 como al menos 1, así si no hay nada en array, puede ser 0 c/u
    if (abs(i-j) > K) return INF;
    if (min(i,j) == -1) return max(i,j)+1;
    if (DP[K+i-j][j]) return DP[K+i-j][j]-1;

    int r = min({lev(i-1,j)+1, lev(i,j-1)+1, lev(i-1,j-1) + (a[i] != b[j])});
    DP[K+i-j][j] = r+1;
    return r;
}

int main() {
    FAST_IO;

    freopen("adn.in","r",stdin);
    freopen("adn.out","w",stdout);

    cin >> l1 >> l2 >> K;
    cin >> a >> b;

    if (abs(l1-l2) > K) {cout << "Muy distintas."; return 0;}

    int result = lev(l1-1,l2-1);
    if (result > K) cout << "Muy distintas.";
    else cout << result;

    return 0;
}
