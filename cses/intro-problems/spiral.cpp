#include <iostream>
using namespace std;
typedef long long ll;

int main() 
{
	int tests;
	cin >> tests;
	while (tests--)
	{
		ll y, x, res, n, pivot;
		cin >> y >> x;

		n = max(y, x);
		pivot = (n * n) - (n-1);
		
		// solution 1 
		// if(i_pivot%2) #se dispari
		// 	if(c>r)
		//			pivot+(r-c)
		// 	else
		// 		pivot+(c-r)
		// else
		//		if(c>r)
		//			pivot-(r-c)
		//		else
		//			pivot-(c-r)

		// solution 2
		// if (n%2 == 0)
		// {
		// 	res = pivot + (y - x);
		// }
		// else
		// {
		// 	res = pivot - (y - x);
		// }
		
		// solution 3
		res = pivot + (n%2 == 0 ? (y - x) : (x - y));		
		

		cout << res << endl;
	}
	return 0;
}