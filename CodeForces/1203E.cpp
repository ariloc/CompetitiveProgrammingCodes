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

const int MAXN = 15e4+2;
int box[MAXN];
bool occup[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;

    int cnt = N;
    forn (i,N) cin >> box[i];
    sort(box,box+N);

    forn (i,N) {
        if (box[i]-1 and !occup[box[i]-1]) occup[box[i]-1] = true;
        else if (occup[box[i]])
            if (!occup[box[i]+1]) occup[box[i]+1] = true;
            else cnt--;
        else occup[box[i]] = true;
    }
    cout << cnt;

    return 0;
}