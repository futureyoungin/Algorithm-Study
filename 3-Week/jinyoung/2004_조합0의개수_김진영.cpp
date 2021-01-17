#include <iostream>
#include <algorithm>
using namespace std;
void numberOfTwoFive(int k, int& two, int& five)
{
    two = five = 0;
    for (long long i = 2; i <= k; i *= 2) {
        two += k/i;
    }
    for (long long i = 5; i <= k; i *= 5) {
        five += k/i;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int two, five, twoSum = 0, fiveSum = 0;
    numberOfTwoFive(n, two, five);
    twoSum += two, fiveSum += five;
    numberOfTwoFive(n-m, two, five);
    twoSum -= two, fiveSum -= five;
    numberOfTwoFive(m, two, five);
    twoSum -= two, fiveSum -= five;
    cout << min(twoSum, fiveSum) << '\n';
    return 0;
}