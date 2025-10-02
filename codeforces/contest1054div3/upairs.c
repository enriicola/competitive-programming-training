#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b)
{
	int int_a = *((int *)a);
	int int_b = *((int *)b);

	if (int_a == int_b)
		return 0;
	else if (int_a < int_b)
		return -1;
	else
		return 1;
}

int main(void)
{
	int tests;
	scanf("%d", &tests);

	while (tests--)
	{
		int n;
		scanf("%d", &n);
		int array[n]; // Sort the array
		qsort(array, n, sizeof(int), compare);

		// Find max

		for (int i = 0; i < n; i++)
			scanf("%d", &array[i]);

		// Sort the array
		qsort(array, n, sizeof(int), compare);

		// Find maximum difference among adjacent pairs
		int max_diff = 0;
		for (int i = 0; i < n; i += 2)
		{
			int diff = array[i + 1] - array[i];
			if (diff > max_diff)
				max_diff = diff;
		}

		printf("%d\n", max_diff);
	}

	return 0;
}