// programmers-chuseok-traffic.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> lines) {
    int size = lines.size();
    int* end_times = new int[size];
    int* begin_times = new int[size];
    int answer = 0;

    for (int i = 0; i < size; i++) {
        string line = lines[i];
        string h = line.substr(11, 2);
        string m = line.substr(14, 2);
        string s = line.substr(17, 2);
        string ms = line.substr(20, 3);
        string during_s = line.substr(24, 5); // 3.000

        int h_ms = stoi(h) * 60 * 60 * 1000;
        int m_ms = stoi(m) * 60 * 1000;
        int s_ms = stoi(s) * 1000 + stoi(ms);

        int during_ms = stof(during_s) * 1000;

        int total_ms = h_ms + m_ms + s_ms;

        begin_times[i] = total_ms - during_ms + 1;
        end_times[i] = total_ms;
    }

    for (int i = 0; i < size; i++) {
        int count = 0;
        int end_time = end_times[i] + 1000;

        if (answer > size - i) {
            break;
        }

        for (int j = i; j < size; j++) {
            if (end_time > begin_times[j]) {
                count++;
            }
        }

        answer = max(answer, count);
    }

    delete[] end_times;
    delete[] begin_times;

    return answer;
}

int main()
{
    cout << "Hello World!\n";
}