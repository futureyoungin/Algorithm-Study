/*
정답이 아닌 소스임. 추후 수정하겠음
*/
#include <iostream>
using namespace std;
class Student {
public:
    static int inBoxCount;
    bool inBox;
    int count, time;
    Student()
    : inBox(false), count(0), time(-1) { }
};
int Student::inBoxCount = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Student students[101];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        if (Student::inBoxCount < n) {
            // 비어있는 사진틀이 있는 경우
            students[num].count += 1;
            if (students[num].inBox) continue;
            students[num].inBox = true;
            students[num].time = i;
            Student::inBoxCount += 1;
        } else {
            // 비어있는 사진틀이 없는 경우
            if (students[num].inBox) {
                students[num].count += 1;
                continue;
            }
            int idx, minCount = m+1, minTime = m+1;
            for (int j = 1; j <= 100; j++) {
                if (students[j].inBox) {
                    if (minCount > students[j].count) {
                        idx = j;
                        minCount = students[j].count;
                        minTime = students[j].count;
                    } else if (minCount == students[j].count) {
                        if (minTime > students[j].time) {
                            idx = j;
                            minTime = students[j].time;
                        }
                    }
                }
            }
            // idx 번호 학생 삭제
            students[idx].inBox = false;
            students[idx].count = 0;
            students[idx].time = -1;
            // 그 자리에 num 학생 추가
            students[num].inBox = true;
            students[num].count += 1;
            students[num].time = i;
        }
    }
    for (int i = 1; i <= 100; i++) {
        if (students[i].inBox) {
            cout << i << " ";
        }
    }
    cout << '\n';
    return 0;
}