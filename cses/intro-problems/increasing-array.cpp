#include <iostream>
using namespace std;

int main() {
	long n;
	cin >> n;
	long a[n];
	long res = 0;

	for (long i = 0; i < n; i++) 
		cin >> a[i];

	for (long i = 0; i < n-1; ++i)
	{
		while (a[i] > a[i+1])
		{
			++a[i + 1];
			++res;
		}
	}




	cout << res << endl;
	return 0;
}