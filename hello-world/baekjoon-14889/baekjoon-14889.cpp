#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int result = 2147483647;

void DFS(int number, int depth, int n, int** point, bool* visit) {
    int start_pw = 0, link_pw = 0;

    if (!result) {
        return ;
    }

    if (depth == n / 2) {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (visit[i] && visit[j]) {
                    start_pw += (point[i][j] + point[j][i]);
                }
                else if (!visit[i] && !visit[j]) {
                    link_pw += (point[i][j] + point[j][i]);
                }
            }
        }

        result = min(result, abs(start_pw - link_pw));
        return;
    }

    for (int i = number; i < n; i++) {
        if (!visit[i]) {
            visit[i] = true;
            DFS(i + 1, depth + 1, n, point, visit);
            visit[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    int** point = new int*[n];
    bool* visit = new bool[n];

    for (int i = 0; i < n; i++) {
        point[i] = new int[n];
        visit[i] = false;

        for (int j = 0; j < n; j++) {
            cin >> point[i][j];
        }
    }

    DFS(0, 0, n, point, visit);

    cout << result << endl;
}
