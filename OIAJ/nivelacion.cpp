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

const int MAXN = 4001;

int dp[MAXN][MAXN];

int nivelacion (string palabra)
{
    int top = palabra.size()+1;
    dforsn (i,1,top)
        forsn (j,i+1,top)
            if (palabra[i-1] != palabra[j-1])
                dp[i][j] = 1+min(dp[i][j-1],dp[i+1][j]);
            else dp[i][j] = dp[i+1][j-1];

    return dp[1][top-1];
}

const static auto ____ = [](){
    FAST_IO; return 0;
}();
