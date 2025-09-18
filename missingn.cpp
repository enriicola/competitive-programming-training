#include <iostream>

using namespace std;

int main() {
	long int n;
	cin >> n;

	long int total = n * (n + 1) / 2;
	long int sum = 0;

	for(int i = 0; i < n - 1; ++i) {
		long int x;
		cin >> x;
		sum += x;
	}

	cout << (total - sum);
	return 0;
}

