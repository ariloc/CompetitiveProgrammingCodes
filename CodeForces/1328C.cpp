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

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(i,t) {
        int N; cin >> N;
        string a,b;
        bool done = false;
        a+='1'; b+='1';
        forn (j,N) {
            char x; cin >> x;

            if (j) {
                if (x == '1') {
                    if (!done) {a+='1', b+='0'; done = true;}
                    else {a+='0', b+='1';}
                }
                if (x == '0') {a+='0', b+='0';}
                if (x == '2') {if (done) {a+='0', b+='2';} else {a+='1',b+='1';}}
            }
        }
        cout << a << '\n' << b << '\n';
    }

    return 0;
}