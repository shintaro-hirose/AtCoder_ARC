#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    string commands[4] = {"A", "B", "X", "Y"};

    int ans = INF;
    rep(i, 4) rep(j, 4) rep(k, 4) rep(l, 4){
        string s1 = commands[i] + commands[j];
        string s2 = commands[k] + commands[l];
        int cnt = N;
        int ni = 0; 
        while(ni < N - 1){
            if((S[ni] == s1[0] && S[ni + 1] == s1[1]) || (S[ni] == s2[0] && S[ni + 1] == s2[1])){
                cnt--;
                ni ++;
            }
            ni++;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}