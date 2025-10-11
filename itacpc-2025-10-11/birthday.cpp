#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Option {
	int count_mod;
	int sum_mod;
	ll cost;
};

// TODO: redo all alone

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<ll>> groups(m);
	ll total_sum = 0;

	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		total_sum += x;
		int r = x % m;
		groups[r].push_back(x);
	}

	if (m == 1) {
		cout << total_sum;
		return 0;
	}

	const ll INF = (1LL << 62);
	vector<ll> dp(m * m, INF);
	dp[0] = 0;

	for (int r = 0; r < m; ++r) {
		auto &vals = groups[r];
		if (vals.empty()) {
			continue;
		}

		sort(vals.begin(), vals.end());

		vector<Option> options;
		options.push_back({0, 0, 0});

		vector<char> seen(m, 0);
		seen[0] = 1;

		ll running_sum = 0;
		for (size_t idx = 0; idx < vals.size(); ++idx) {
			running_sum += vals[idx];
			int k = static_cast<int>(idx) + 1;
			int c = k % m;
			if (!seen[c]) {
				seen[c] = 1;
				int s_mod = (static_cast<ll>(c) * r) % m;
				options.push_back({c, s_mod, running_sum});
				if (static_cast<int>(options.size()) == m) {
					break;
				}
			}
		}

		vector<ll> next_dp(m * m, INF);

		for (int c1 = 0; c1 < m; ++c1) {
			for (int s1 = 0; s1 < m; ++s1) {
				ll cur = dp[c1 * m + s1];
				if (cur == INF) {
					continue;
				}
				for (const auto &opt : options) {
					int new_c = (c1 + opt.count_mod) % m;
					int new_s = (s1 + opt.sum_mod) % m;
					ll candidate = cur + opt.cost;
					ll &ref = next_dp[new_c * m + new_s];
					if (candidate < ref) {
						ref = candidate;
					}
				}
			}
		}

		dp.swap(next_dp);
	}

	int target_count = n % m;
	int target_sum_mod = static_cast<int>(total_sum % m);

	ll removal = dp[target_count * m + target_sum_mod];
	if (removal >= INF / 2) {
		removal = total_sum;
	}

	ll answer = total_sum - removal;
	cout << answer << '\n';
	return 0;
}
