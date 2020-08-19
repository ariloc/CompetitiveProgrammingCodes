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

const int MAXN = 1002;

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int N; cin >> N;
        int arr[MAXN];
        forn (j,N) cin >> arr[j];

        int a = 0, b = 0, prevA = 0, prevB = 0, moves = 0, cnt = 0, indA = 0, indB = N-1;
        bool turn = true;
        while (cnt < N) {
            moves++;
            int cntA = 0;
            if (turn) {
                while (cntA <= prevB and cnt < N) {cnt++; a += arr[indA]; cntA += arr[indA++];}
                prevA = cntA;
            }
            else {
                while (cntA <= prevA and cnt < N) {cnt++; b += arr[indB]; cntA += arr[indB--];}
                prevB = cntA;
            }

            //cerr << a << ' ' << b << endl;

            turn = !turn;
        }

        cout << moves << ' ' << a << ' ' << b << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!