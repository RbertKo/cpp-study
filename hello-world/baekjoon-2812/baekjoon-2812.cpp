// 문제: 
// N자리 숫자가 주어졌을 때, 여기서 숫자 K개를 지워서 얻을 수 있는 가장 큰 수를 구하는 프로그램을 작성하시오.
// 
// 입력:
// 첫째 줄에 N과 K가 주어진다. (1 ≤ K < N ≤ 500,000)
// 둘째 줄에 N자리 숫자가 주어진다.이 수는 0으로 시작하지 않는다.
// 
// 출력:
// 입력으로 주어진 숫자에서 K개를 지웠을 때 얻을 수 있는 가장 큰 수를 출력한다.
// 
// 예제 입력
// 4 2
// 1924
// 
// 예제 출력
// 94


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//int main() // Time out
//{
//	int n, k;
//	string target, temp_target;
//
//	cin >> n;
//	cin >> k;
//	cin >> target;
//
//	temp_target = target;
//	
//	sort(temp_target.begin(), temp_target.end());
//
//	for (int i = 0; i < k; i++) {
//		size_t pos = target.find(temp_target[i]);
//
//		target.erase(pos, 1);
//	}
//
//	cout << target << endl;
//}

int main()
{
	int n, k;
	string target;

	cin >> n >> k >> target;

	vector<char> vt;

	for (int i = 0; i < n; i++) {
		while (k && !vt.empty() && vt.back() < target[i]) {
			k--;
			vt.pop_back();
		}

		vt.push_back(target[i]);
	}

	for(int i = 0; i < vt.size(); i++) {
		cout << vt[i];
	}

	cout << endl;

	for (int i = 0; i < vt.size() - k; i++) {
		cout << vt[i];
	}

	return 0;
}