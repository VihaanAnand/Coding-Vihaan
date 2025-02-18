#include <iostream>
#define MAXN 1000005
using namespace std;
int a[MAXN], pref[MAXN], cnt[MAXN];
long long ans = 0;
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
                cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
                pref[i] = pref[i-1];
                cnt[a[i]]++;
                if (cnt[a[i]] == 1) {
                        pref[i]++;
                }
        }
        memset(cnt, 0, sizeof cnt);
        for (int i = n; i >= 1; i--) {
                cnt[a[i]]++;
                if (cnt[a[i]] == 2) {
                        ans += pref[i-1];
                }
        }
        for (int i = 1; i <= n; i++) {
                if (cnt[i] >= 3) {
                        ans--;
                }
        }
        cout << ans;
}