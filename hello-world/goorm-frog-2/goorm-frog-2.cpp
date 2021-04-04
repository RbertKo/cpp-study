#include <iostream>
using namespace std;
int main() {
	int length, total = 0, cur_val = 0, cur_power = 0;
	cin >> length;

	for (int i = 0; i < length; i++) {
		int val, required_p;
		cin >> val;

		required_p = val - cur_val;

		if (cur_power < required_p) {
			int need = required_p - cur_power;
			total += need;
			cur_power += need;
		}

		cur_val = val;
		cur_power -= 1;
	}

	cout << total << endl;

	return 0;
}