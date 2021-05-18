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

const int MAXN = 102;

void comp(bool *arr, int &N) {
    forsn (i,1,N+1) arr[i] = !arr[i];
}

void invert(bool *arr, int &N) {
    forsn (i,1,(N/2)+1) swap(arr[i],arr[N-i+1]);
}

void dummy() {
    int tmp;
    cout << 1 << endl;
    cin >> tmp;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    int N; cin >> N;

    forn (i,t) {
        bool arr[MAXN];
        forn (j,N+1) arr[j] = false;
        int n = N;

        int indI, indD;
        indI = indD = -1;
        int act = 1;
        while (n) {
            bool do1 = false, do2 = false;
            if (indI != -1) {
                int v;
                cout << indI << endl;
                cin >> v;

                if (v != arr[indI])
                    do1 = true;
            } else dummy();
            if (indD != -1) {
                int v;
                cout << indD << endl;
                cin >> v;

                if (do1)
                    {if (v == arr[indD]) do2 = true;}
                else if (v != arr[indD])
                    do2 = true;
            } else dummy();

            if (do1) comp(arr,N);
            if (do2) invert(arr,N);

            int actA = act;
            forsn (j,actA,actA+4) {
                int b1, b2;
                cout << j << endl;
                cin >> b1;
                cout << N-j+1 << endl;
                cin >> b2;

                arr[j] = b1;
                arr[N-j+1] = b2;

                if (indI == -1 and b1 == b2) indI = j;
                if (indD == -1 and b1 != b2) indD = j;

                act++; n-=2;
                if (n <= 0) break;
            }
        }

        forsn (j,1,N+1) {char x = arr[j]+'0'; cout << x;}
        cout << endl;
        char r; cin >> r;
        if (r == 'N') return 0;
    }
    return 0;
}
