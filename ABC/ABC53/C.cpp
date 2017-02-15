#include <iostream>

using namespace std;

int main() {
    long long x;
    cin >> x;

    long long r = x % 11;
    x /= 11;
    long long ans;

    if (r == 0) {
        ans = x * 2;
    } else if (r <= 6) {
        ans = x * 2 + 1;
    } else {
        ans = x * 2 + 2;
    }

    cout << ans << endl;

    return 0;
}