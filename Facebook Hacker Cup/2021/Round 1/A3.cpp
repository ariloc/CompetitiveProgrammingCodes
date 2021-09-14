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

const int MAXN = 8e5+5;
const int INF = 1e9+5;
const int MOD = 1e9+7;

int cnt_here[MAXN];

int main() {
    FAST_IO;

    freopen("weak_typing_chapter_3_input.txt","r",stdin);
    freopen("salida.txt","w",stdout);

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        string s; cin >> s;

        ll final_n = 0;
        forn(i,n) {
            if (s[i] == '.') final_n = (final_n + final_n)%MOD;
            else final_n = (final_n+1)%MOD;
            cnt_here[i] = (int)final_n;
        }

        char f_char = 'F', l_char = 'F'; int f_ind = n, l_ind = n;
        forn(i,n) if (s[i] == 'X' || s[i] == 'O') {f_ind = l_ind = i, f_char = l_char = s[i]; break;}

        ll r = 0, r_l = 0, r_r = 0, cnt_l = 0;
        int cntF = 0; // cantidad de Fs en medio
        forsn(i,f_ind+1,n) {
            if (s[i] == '.') { 

                r = ( (( r + ((r_l*(ll)cnt_here[i-1])%MOD) )%MOD) + (( r + ((cnt_here[i-1]*(ll)r_r)%MOD) )%MOD) )%MOD;
                r_l = ( (r_l + r_l)%MOD + ((cnt_here[i-1]*(ll)cnt_l)%MOD) )%MOD;
                r_r = ( ((r_r + r_r)%MOD) + ((cnt_here[i-1]*(ll)cnt_l)%MOD) )%MOD;
                cnt_l = (cnt_l + cnt_l)%MOD;
                
                if (l_char != f_char && l_char != 'F' && f_char != 'F') {
                    int cnt_real_l = (cnt_here[i-1] - cntF + MOD)%MOD;
                    int cnt_real_r = (cnt_here[i-1] - cnt_here[f_ind] + 1 + MOD)%MOD;
                    r_l = (r_l + cnt_real_l)%MOD;
                    r_r = (r_r + cnt_real_r)%MOD;
                    r = (r + ((cnt_real_l * (ll)cnt_real_r)%MOD))%MOD;
                    cnt_l = (cnt_l+1)%MOD;
                }
            }
            else if (s[i] == 'X' || s[i] == 'O') {
                r = (r+r_l)%MOD, r_r = (r_r + cnt_l)%MOD;
                if (s[i] != l_char) {
                    int cnt_real = (cnt_here[i-1] - cntF + MOD)%MOD; 

                    r_l = (r_l+cnt_real)%MOD;
                    r_r = (r_r + 1)%MOD;
                    r = (r+cnt_real)%MOD;
                    cnt_l = (cnt_l+1)%MOD;
                }
                l_char = s[i], l_ind = i, cntF = 0;
            }
            else r = (r+r_l)%MOD, r_r = (r_r + cnt_l)%MOD, cntF++;
        }

        cout << "Case #" << o+1 << ": " << r << '\n';
    }

    return 0;
}