#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
    cin >> T;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        int first = -1, last = -1;
        for (int i = 0; i < N; ++i)
            if (S[i] == '1') { first = i; break; }

        for (int i = N - 1; i >= 0; --i)
            if (S[i] == '1') { last = i; break; }

        if (first == -1) {
            cout << 0 << '\n';
            continue;
        }

        int flips = 0;
        for (int i = first; i <= last; ++i)
            if (S[i] == '0') ++flips;

        cout << flips << '\n';
    }
    return 0;


}

