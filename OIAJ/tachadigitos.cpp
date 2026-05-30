#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXK = 10;
int const INF = 2e9;

int cnt[MAXK];

int tachadigitos(int K, string &d) {
    for (auto &c : d) cnt[c-'0']++;
    int tot = (int)d.size();

    if (K <= 6) {
        int ret = 0;
        while (tot > 0) {
            bool ok = true;
            int s = 0;
            ret++;
            while (s < K && ok) {
                ok = false;
                dforn(i,K-s+1)
                    if (cnt[i] > 0) {
                        cnt[i]--, tot--;
                        s += i;
                        ok = true;
                        break;
                    }
            }
        }

        return ret;
    }

    if (K == 7) {
        int ret = 0;
        dforn(i,K+1) {
            while (cnt[i] > 0) {
                int s = 0;
                if (i != 3 || !cnt[2]) {
                    while (cnt[i] > 0 && s+i <= K)
                        s += i, cnt[i]--;
                }
                else {
                    s = 3;
                    cnt[i]--;
                }

                bool ok = true;
                while (s < K && ok) {
                    ok = false;
                    dforn(j,min(i,K-s+1)) {
                        if (cnt[j] > 0) {
                            cnt[j]--;
                            s += j;
                            ok = true;
                            break;
                        }
                    }
                }
                ret++;
            }
        }

        return ret;
    }

    if (K == 8) {
        int ret1 = 0, ret2 = 0;
        // strategy 1: forces to add 2 2s when only one 4
        dforn(i,K+1) {
            while (cnt[i] > 0) {
                int s = 0;
                while (cnt[i] > 0 && s+i <= K)
                    s += i, cnt[i]--;

                if (i == 4 && s == 4 && cnt[2] >= 2) {
                    cnt[2] -= 2; s += 4;
                }

                bool ok = true;
                while (s < K && ok) {
                    ok = false;
                    dforn(j,min(i,K-s+1)) {
                        if (cnt[j] > 0) {
                            cnt[j]--;
                            s += j;
                            ok = true;
                            break;
                        }
                    }
                }
                ret1++;
            }
        }
        
        // strategy 2: standard greedy
        for (auto &c : d) cnt[c-'0']++;
        dforn(i,K+1) {
            while (cnt[i] > 0) {
                int s = 0;
                while (cnt[i] > 0 && s+i <= K)
                    s += i, cnt[i]--;

                bool ok = true;
                while (s < K && ok) {
                    ok = false;
                    dforn(j,min(i,K-s+1)) {
                        if (cnt[j] > 0) {
                            cnt[j]--;
                            s += j;
                            ok = true;
                            break;
                        }
                    }
                }
                ret2++;
            }
        }

        return min(ret1,ret2);
    }

    //// K == 9
    // Hay tres posibles decisiones que pueden cambiar el resultado
    // final:
    // * Si tengo 5 y me quedé sin 4s, elijo +3 o +2+2?
    // * Si tengo 4, elijo entre +4+1 o +3+2?
    // * Si tengo 3, elijo +3+3 o +2+2+2? 
    // En el primer caso es si me quedo sin 4s, así que no afecta al
    // segundo caso, elijo si puedo +2+2.
    // Luego así me conviene siempre si puedo en el segundo caso, +3+2
    // En el tercer caso siempre me conviene agarrar los de dos,
    // ya que luego se podrán acomodar mejor con los 1s que queden.
    // Y sino uso los 3 con cuidado, puedo quedar con 3+3+2, despediciando
    // espacio.
    
    int ret = 0;
    dforn(i,K+1) {
        while (cnt[i] > 0) {
            int s = 0;

            if (i == 5 && !cnt[4] && cnt[2] >= 2) {
                cnt[2] -= 2;
                cnt[5]--;
                s = 9;
            }
            else if (i == 4 && cnt[3] && cnt[2]) {
                cnt[3]--;
                cnt[2]--;
                cnt[4]--;
                s = 9;
            }
            else if (i == 3 && cnt[2] >= 3) {
                cnt[3]--;
                cnt[2] -= 3;
                s = 9;
            }
            else {
                while (cnt[i] > 0 && s+i <= K)
                    s += i, cnt[i]--;
            }

            bool ok = true;
            while (s < K && ok) {
                ok = false;
                dforn(j,min(i,K-s+1)) {
                    if (cnt[j] > 0) {
                        cnt[j]--;
                        s += j;
                        ok = true;
                        break;
                    }
                }
            }
            ret++;
        }
    }

   
    return ret;
}
