#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

ll llpow(int a, int b){
    ll res = 1;
    rep(i, b){
        res *= a;
    }
    return res;
}

int main() {
    ll N; cin >> N;
    for(int i = 1; i <= 38; i++) for(int j = 1; j <= 26; j++){
        if(llpow(3, i) + llpow(5, j) == N){
            cout << i << " " << j << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}