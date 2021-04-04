#include <iostream>
using namespace std;

struct Point {
	int x;
	int y;
};

int main() {
	int size, count = 0;
	cin >> size;

	int area[size][size];

	for (int i = 0; i < size; i++) {
		for (int z = 0; z < size; z++) {
			cin >> area[i][z];
		}
	}

	Point start, end;

	cin >> start.x;
	cin >> start.y;
	cin >> end.x;
	cin >> end.y;

	for (int i = start.y; i <= end.y; i++) {
		for (int z = start.x; z <= end.y; z++) {
			count += area[i][z];
		}
	}

	cout << count << endl;

	return 0;
}