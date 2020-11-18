// https://www.hackerrank.com/contests/simulacro-2-oia-2020/challenges/problem-1-escaping-the-farm/problem
#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

int escapingFarm(vector <int> v) {
    int maxi = 0;
    forn(i,(1<<(int)v.size())) {
        vi u(10,0); int bitsOn = 0;
        forn(j,20) if (i&(1<<j)) {
            bitsOn++;
            int aux = v[j], cnt = 0;
            while (aux) {
                u[cnt] += (aux%10);
                cnt++; aux /= 10;
            }
        }
        bool posib = true;
        for (auto &k : u) if (k > 9) {posib = false; break;}
        if (posib) maxi = max(maxi,bitsOn);
    }
    return maxi;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector <int> v(N);
    for(int i=0; i<N; i++)
        cin >> v[i];

    cout << escapingFarm(v) << endl;

    return 0;
}
