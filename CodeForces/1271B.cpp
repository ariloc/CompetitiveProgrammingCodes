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

vi indices;

int main() {
    FAST_IO;

    int N; cin >> N;
    string s; cin >> s;

    // si cant ambos impar, no se puede
    int B = 0, W = 0;
    forn (i,s.size())
        if (s[i] == 'B') B++;
        else W++;

    if (B%2 and W%2) {cout << -1; return 0;}
    if (!W or !B) {cout << 0; return 0;}

    char target = 'B';
    if (W%2) target = 'W';

    int cnt = 0;
    forn(i,s.size()-1) {
        if (s[i] != target) cnt++;
        else {
            if (cnt % 2) {
                indices.push_back(i);
                swap(s[i],s[i-1]);
                cnt = 1;
                continue;
            }
            cnt = 0;
        }
    }
    forsn (i,1,s.size()) {
        if (s[i] == s[i-1] and s[i] != target) {
            s[i] = s[i-1] = target;
            indices.push_back(i);
        }
    }

    B = 0, W = 0;
    forn (i,s.size()) {
        if (s[i] == 'B') B++;
        else W++;
    }

    if (B and W) cout << -1;
    else {
        cout << indices.size() << '\n';
        for (auto &i : indices) cout << i << ' ';
    }

    return 0;
}