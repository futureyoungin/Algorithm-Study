#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
int* strToArr(int n, char* arrString)
{
    if (n <= 0) return nullptr;
    int* arr = new int[n];
    char* ptr = strtok(arrString, "[,]");
    int i = 0;
    while (ptr != nullptr) {
        arr[i++] = atoi(ptr);
        ptr = strtok(nullptr, "[,]");
    }
    return arr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string cmd, ans = "[";
        char arrString[500000];
        int n;
        bool inversion = false, errorFlag =false;
        cin >> cmd >> n >> arrString;
        int* arr = strToArr(n, arrString);
        int startIdx = 0, endIdx = n;
        for (char ch:cmd) {
            if (ch == 'R') {
                inversion = !inversion;
            } else if (ch == 'D') {
                if (startIdx == endIdx) {
                    errorFlag = true;
                    break;
                }
                if (!inversion) ++startIdx;
                else --endIdx;
            }
        }
        if (errorFlag) {
            cout << "error" << '\n';
        } else if (startIdx == endIdx) {
            cout << "[]" << '\n';
        } else {
            if (!inversion) {
                for (int i = startIdx; i < endIdx; i++) {
                    ans += to_string(arr[i]);
                    if (i == endIdx-1) {
                        ans += "]";
                        continue;
                    }
                    ans += ",";
                }
            } else {
                for (int i = endIdx-1; i >= startIdx; i--) {
                    ans += to_string(arr[i]);
                    if (i == startIdx) {
                        ans += "]";
                        continue;
                    }
                    ans += ",";
                }
            }
            cout << ans << '\n';
        }
        delete[] arr;
    }
    return 0;
}