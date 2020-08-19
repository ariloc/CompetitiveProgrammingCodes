#include <vector>
#include <string>
#include <map>

using namespace std;

int receta(vector<string> heladera, vector<string> ingredientes, vector<string> &faltantes)
{
    map<string, int> h;
    for (auto i : heladera) {
        h[i] = 1;
    }
    for (auto i : ingredientes) {
        if (!h.count(i)) faltantes.push_back(i);
        h[i] = 1;
    }
    return faltantes.size();
}
