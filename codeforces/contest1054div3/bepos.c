#include <stdio.h>

int productf(int array[], int n)
{
	int p = 1;
	for (int i = 0; i < n; ++i)
		p *= array[i];

	return p;
}

int main(void)
{
	int tests;
	scanf("%d", &tests);

	int n, count;
	
	while (tests--)
	{
		scanf("%d", &n);
		int array[n];
		int product;
		int count = 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", &array[i]);

		product = productf(array, n);
		while (product <= 0)
		{
			if (product == 0)
				for (int i = 0; i < n; i++)
					if (array[i] == 0)
					{
						++array[i];
						++count;
					}
			if (product < 0)
				for (int i = 0; i < n; i++)
					if (array[i] == -1)
					{
						array[i] += 2;
						count += 2;
						break;
					}
			



			product = productf(array, n);
		}

		printf("\n%d", count);
	}

	return 0;
}