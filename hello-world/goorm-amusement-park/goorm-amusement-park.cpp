// goorm-amusement-park.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include<cstdio>
#include<cstdlib>
#include<memory.h>
#include<iostream>
#include<algorithm>


using namespace std;


int get_minimum_trashes(int** waste, int N, int K) {
	int answer = -1;
	int x = 0, y = 0;

	while (!(x == (N - K + 1) && y == (N - K))) {
		if (x >= (N - K + 1)) {
			y += 1;
			x = 0;
		}

		int i = x, z = y;
		int current = 0;

		while (1) {
			// cout << waste[z][i] << ' ';

			current += waste[z][i];

			if (i == (x + K - 1) && z == (y + K - 1) || (answer != -1 && current > answer)) {
				// cout << endl << endl;
				break;
			}

			if (i == (x + K - 1)) {
				z += 1;
				i = x;
				// cout << endl;
				continue;
			}

			i += 1;
		}

		answer = answer == -1 || answer > current ? current : answer;

		x += 1;
	}

	return answer;
}

void test_case(int caseIndex) {
	int N, K;
	scanf_s("%d %d", &N, &K);

	int** wastes = new int* [N];
	for (int r = 0; r < N; r += 1) {
		wastes[r] = new int[N];
		for (int c = 0; c < N; c += 1) {
			scanf_s("%d", &wastes[r][c]);
		}
	}

	int answer = get_minimum_trashes(wastes, N, K);
	printf("%d\n", answer);

	for (int r = 0; r < N; r += 1) {
		delete[] wastes[r];
	}
	delete[] wastes;
}

int main() {
	int caseSize;
	cin >> caseSize;

	for (int caseIndex = 0; caseIndex < caseSize; caseIndex += 1) {
		test_case(caseIndex);
	}
	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
