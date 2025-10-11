#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
   int a[n];
   for (size_t i = 0; i < n; i++)
   {
      cin >> a[i];
   }
   int tmp;
   int max_gifts = 0;

   int size = n;

   while (n > 0)
   {
      if (n%m == 0)
      {
         break;
      }
      --n;
   }

   for (size_t i = 0; i < size; ++i)
   {
      tmp = 0;
      for (size_t j = 0; j < size; ++j)
      {
         if (i == j) continue;
         if ((a[i]+a[j]) % m == 0)
         {
            tmp = a[i] + a[j];
            max_gifts = max(max_gifts, tmp);
         }
         
      }
   }






   cout << max_gifts << endl;

	return 0;
}
