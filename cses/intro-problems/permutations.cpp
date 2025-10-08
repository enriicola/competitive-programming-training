#include <iostream>
using namespace std;

int main() {
	long n;
	cin >> n;

	if (n <= 3)
	{
		cout << "NO SOLUTION";
		return 0;
	}

	long res[n];
	int pos = 0;

	for (long i = 1; i <= n; i+=2)
	{
		res[pos++] = i;
	}
	for (long i = 2; i <= n; i+=2)
	{
		res[pos++] = i;
	}

	while (n--)
	{
		cout << res[n] << " ";
	}
	
	cout << endl;
	return 0;
}