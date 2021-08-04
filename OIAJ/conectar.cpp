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

const int MAXN = 2e6;

struct DS{
    void init(int n){
        r.clear();
        r.resize(n,-1);
    }
    int find(int x){
        return r[x] == -1 ? x : r[x] = find(r[x]);
    }
    bool join(int x, int y){
        x = find(x);
        y = find(y);
        if( x != y ){
            r[x] = y;
            return true;
        }
        return false;
    }
    vector<int> r;
};

int main(){
    FAST_IO;

    freopen("conectar.in","r",stdin);
    freopen("conectar.out","w",stdout);

    DS s;
    s.init(MAXN);
    vector<char> r;

    while(true) {
        int k1,k2;
        char R;
        cin >> R;
        if (R == 'F') break;
        cin >> k1 >> k2;
        if (R == 'C') s.join(k1,k2);
        else if(s.find(k1) == s.find(k2)) r.push_back('S');
        else r.push_back('N');
    }
    for (auto &i : r) cout << i << endl;
    return 0;
}