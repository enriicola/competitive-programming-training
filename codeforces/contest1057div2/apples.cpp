#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	
	while (tests--) {
		int n;
		cin >> n;
		int beauty[n];
		
		for (int i = 0; i < n; ++i) {
			cin >> beauty[i];
		}
		
		sort(beauty, beauty + n);
		
		int eaten = 1;
		int last_eaten = beauty[0];

		for (int i = 1; i < n; ++i) {
			if (beauty[i] > last_eaten) {
				eaten++;
				last_eaten = beauty[i];
			}
		}
		
		cout << eaten << endl;
	}
	
	return 0;
}
