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

int main() {
    FAST_IO;
    freopen("mensajes.in","r",stdin);
    freopen("mensajes.out","w",stdout);

    int N;
    string s,t;
    cin >> N;
    forn(i,N) {char c; cin >> c; s+=c;}

    cin >> t;
    if (s.find(t) != string::npos) cout << "SI\nI";
    else {
        reverse(all(s));
        if (s.find(t) != string::npos) cout << "SI\nD";
        else cout << "NO";
    }

    return 0;
}