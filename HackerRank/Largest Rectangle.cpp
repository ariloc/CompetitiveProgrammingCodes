// https://www.hackerrank.com/challenges/largest-rectangle/problem
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
vector<string> split(const string &);

/*
 *  * Complete the 'largestRectangle' function below.
 *   *
 *    * The function is expected to return a LONG_INTEGER.
 *     * The function accepts INTEGER_ARRAY h as parameter.
 *      */

const int MAXN = 1e5+5;
const int MAXH = 1e6+5;
const int INF = 2e9;

long largestRectangle(vector<int> h_aux) {
    int n = h_aux.size();
    vi pm(n+2,0), pm2(n+2,0), h(n+2,0);
    forn(i,n) h[i+1] = h_aux[i];

    h[0] = h[n+1] = -INF;
    dforsn(i,1,n+1) {int j; for (j = i+1; h[j] >= h[i]; j = pm[j]); pm[i] = j;}
    forsn(i,1,n+1) {int j; for (j = i-1; h[j] >= h[i]; j = pm2[j]); pm2[i] = j;}

    ll rta = 0;
    forsn(i,1,n+1)
        rta = max(rta, (ll)(pm[i]-pm2[i]-1)*h[i]);

    return rta;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
            int h_item = stoi(h_temp[i]);
    
            h[i] = h_item;
        }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
            tokens.push_back(str.substr(start, end - start));
    
            start = end + 1;
        }

    tokens.push_back(str.substr(start));

    return tokens;
}
