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

int main() {
    FAST_IO;

    int t;cin  >> t;
    forn(_,t) {
        vi vec(3);
        cin >> vec[0] >> vec[1] >> vec[2];
        int cnt = 0;
        while (vec[0] != vec[1] && vec[1]!=vec[2] &&vec[0] != vec[2]) {
            vector<ii> auxi = {{vec[0],0},{vec[1],1},{vec[2],2}};
            sort(all(auxi));
            vec[auxi.back().snd]--;
            vec[auxi[0].snd]++;
            ++cnt;
        }
        cout << cnt << '\n';
    }

    return 0;
}
