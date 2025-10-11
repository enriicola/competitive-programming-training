#include <iostream>
#include <vector>
using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int tests;
   cin >> tests;
   while (tests--)
   {
      int n, k1, k2;
      cin >> n >> k1 >> k2;
      vector<int> v(n);
      for (int i = 0; i < n; i++)
      {
         cin >> v[i];
      }

      int max_length = -1;
      
      // For each starting position i
      for (int i = 0; i < n; i++) {
         // If we can't get a better result, skip
         if (n - i <= max_length) break;
         
         int left_count = 1;
         int max_left = v[i];
         
         // For each ending position j
         for (int j = i; j < n; j++) {
            // Update left count for position j
            if (j > i && v[j] > max_left) {
               left_count++;
               max_left = v[j];
            }
            
            // Skip if left count exceeds k1 
            if (left_count > k1) break;
            
            // Calculate right count only if left count matches k1
            if (left_count == k1) {
               int right_count = 1;
               int max_right = v[j];
               
               for (int k = j - 1; k >= i; k--) {
                  if (v[k] > max_right) {
                     right_count++;
                     max_right = v[k];
                     if (right_count > k2) break; // Early exit
                  }
               }
               
               if (right_count == k2) {
                  max_length = max(max_length, j - i + 1);
               }
            }
         }
      }
      
      cout << max_length << endl;
   }
   return 0;
}