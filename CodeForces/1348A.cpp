#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 30;

ll potS[MAXN], pot[MAXN];

void gen() {
    pot[0] = 2;
    potS[0] = 2;
    int num = 2;
    forsn (i,1,MAXN) {
        num <<= 1;
        pot[i] = num;
        potS[i] = (potS[i-1]+num);
    }
}

int main() {
    FAST_IO;

    gen();
    int N; cin >> N;

    forn (i,N) {
        int x; cin >> x;
        if (x == 2) {cout << "2\n"; continue;}
        ll val = abs(potS[int((x-1)/2)-1]+pot[x-1]);
        cout << abs(potS[x-1]-2*val) << '\n';
    }

    return 0;
}