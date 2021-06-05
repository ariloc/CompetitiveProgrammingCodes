// https://www.hackerrank.com/challenges/square-subsequences/problem
#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

string ltrim(const string &);
string rtrim(const string &);

const int MAXN = 205;
const int MOD = 1e9+7;

int dp[MAXN][MAXN];

int sumMod (int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int difMod (int a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

int squareSubsequences(string s) {
    int n = s.size();
    int sum = 0;
    forsn(mid,1,n) {
        forn(i,MAXN) forn(j,MAXN) dp[i][j] = 0;
        forn(i,mid) dp[i+1][mid+1] = dp[i][mid+1] + (s[i] == s[mid]);
        forsn(i,1,mid+1) forsn(j,mid+2,n+1) 
            dp[i][j] = difMod( sumMod(dp[i-1][j],dp[i][j-1]), dp[i-1][j-1]*(s[i-1] != s[j-1]) );
        sum = sumMod(sum,dp[mid][n]);
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        int result = squareSubsequences(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}