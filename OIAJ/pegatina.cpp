#include <string>

using namespace std;

string pegatina(int N, int K) {
    string s;
    for (int i = K; i <= N; i += K)
        s += to_string(i);
    return s;
}
