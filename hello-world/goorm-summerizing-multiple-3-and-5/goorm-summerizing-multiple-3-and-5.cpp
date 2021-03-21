#include <iostream>
using namespace std;
int main() {
	int input;
	unsigned int count = 0;
	cin >> input;

	for (int i = 1; i <= input; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			count += i;
		}
	}

	cout << count << endl;
	return 0;
}