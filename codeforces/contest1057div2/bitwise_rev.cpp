#include <iostream>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	
	while (tests--) {
		long long x, y, z;
		cin >> x >> y >> z;
		
		// For each bit position, check if a valid combination exists
		bool possible = true;
		
		for (int bit = 0; bit < 30; bit++) {
			int bx = (x >> bit) & 1;
			int by = (y >> bit) & 1;
			int bz = (z >> bit) & 1;
			
			// Check all 8 possible combinations of bits for a, b, c
			bool found = false;
			for (int a = 0; a <= 1; a++) {
				for (int b = 0; b <= 1; b++) {
					for (int c = 0; c <= 1; c++) {
						if ((a & b) == bx && (b & c) == by && (a & c) == bz) {
							found = true;
							break;
						}
					}
					if (found) break;
				}
				if (found) break;
			}
			
			if (!found) {
				possible = false;
				break;
			}
		}
		
		cout << (possible ? "YES" : "NO") << endl;
	}
	
	return 0;
}
