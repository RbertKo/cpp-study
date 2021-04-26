#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	int a_len, b_len;

	cin >> a_len;
	cin >> b_len;

	int* input = new int[a_len + b_len];


	for (int i = 0; i < a_len + b_len; i++) {
		cin >> input[i];
	}

	sort(input, input + a_len + b_len);

	for (int i = 0; i < a_len + b_len; i++) {
		cout << input[i] << ' ';
	}

	delete[] input;

	return 0;
}