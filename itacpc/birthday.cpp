#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
   int original_n = n;
   n = n - (n % m);
   int a[n];
   int max_sum_of_n = 0;

   for (int i = 0; i < original_n; i++)
   {
      cin >> a[i];
      if (original_n == n)
      {
         
      }
      
   }

   for (int i = 0; i < original_n; ++i)
   {
      for (int j = 0; j < n; ++j)
      {
         if (i == j) continue;
         if ((a[i]+a[j]) % m == 0)
         {
            max_sum_of_n = max(max_sum_of_n, a[i] + a[j]);
         }
         
      }
      
   }


   cout << max_sum_of_n << endl;

	return 0;
}
