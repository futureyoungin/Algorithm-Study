#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m = 0;
    stack<int> s;
    string ans = "";
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (m < a) {
            while (m < a) {
                s.push(++m);
                ans += "+\n";
            }
            s.pop();
            ans += "-\n";
        } else {
            bool found = false;
            if (!s.empty()) {
                int top = s.top();
                s.pop();
                ans += "-\n";
                if (top == a)
                    found = true;
            }
            if (!found) {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }
    cout << ans;

    return 0;
}

