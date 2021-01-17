#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    char buffer[51];
    cin >> buffer;
    
    int len = strlen(buffer), count = 1;
    for (int i = 0; i < len; i++) {
        if (buffer[i] == '+') count++;
        else if (buffer[i] == '-') break;
    }
    int ans = 0;
    char* ptr = strtok(buffer, "+-");
    while (ptr != nullptr) {
        if (count) {
            ans += atoi(ptr);
            count--;
        } else {
            ans -= atoi(ptr);
        }
        ptr = strtok(nullptr, "+-");
    }
    cout << ans << '\n';
    return 0;
}