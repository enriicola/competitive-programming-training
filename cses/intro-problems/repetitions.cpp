#include <iostream>
using namespace std;

int main() {
	string dna;
	cin >> dna;
	int max, count;
	max = count = 1;
	int size = dna.length();

	for (size_t i = 0; i < size; i++)
	{
		if (dna[i] == dna[i + 1])
		{
			++count;
			if (count > max)
				max = count;
		}
		else
		{
			count = 1;
		}
	}

	cout << max << endl;

	return 0;
}