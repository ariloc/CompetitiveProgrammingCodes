#include <iostream>
#include <vector>

#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("red.in","r",stdin);
    freopen("red.out","w",stdout);

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
