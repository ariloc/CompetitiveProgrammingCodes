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

const int MAXN = 1000;

vi cl,indices;
queue<int> op;

int main() {
    FAST_IO;

    string s;
    cin >> s;

    forn (i,s.size()) {
        if (s[i] == '(') op.push(i+1);
        else cl.push_back(i+1);
    }

    while (not op.empty() and not cl.empty()) {
        int a = op.front(); op.pop();
        int b = cl.back(); cl.pop_back();

        if (b < a) break;

        indices.push_back(a); indices.push_back(b);
    }

    if (indices.empty()) cout << 0;
    else {
        sort(all(indices));
        cout << "1\n" << indices.size() << '\n';
        for (auto &i : indices) cout << i << ' ';
    }

    return 0;
}