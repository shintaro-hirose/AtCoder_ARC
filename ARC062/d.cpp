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

const ll mod = 998244353;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    rep(i, n){
        char c = s[i];
        if(i % 2 == 0){
            if(c == 'p'){
                ans--;
            }
        } else {
            if(c == 'g'){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
