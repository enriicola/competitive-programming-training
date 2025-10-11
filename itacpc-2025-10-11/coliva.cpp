#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n{};
    int maxPow{};
    vector<int> bit;

    Fenwick() = default;

    explicit Fenwick(int n) { init(n); }

    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
        maxPow = 1;
        while (maxPow < n) {
            maxPow <<= 1;
        }
    }

    void add(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }

    int sum(int idx) const {
        idx = min(idx, n);
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res += bit[idx];
        }
        return res;
    }

    int range_sum(int l, int r) const {
        if (l > r) {
            return 0;
        }
        return sum(r) - sum(l - 1);
    }

    int find_by_order(int k) const {
        int idx = 0;
        int curr = 0;
        for (int step = maxPow; step > 0; step >>= 1) {
            int next = idx + step;
            if (next <= n && curr + bit[next] < k) {
                idx = next;
                curr += bit[next];
            }
        }
        return idx + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) {
        return 0;
    }
    while (T--) {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        vector<int> Llow(n + 1), Rhigh(n + 1);
        {
            vector<int> st;
            st.reserve(n);
            for (int i = 1; i <= n; ++i) {
                while (!st.empty() && a[st.back()] < a[i]) {
                    st.pop_back();
                }
                int pge = st.empty() ? 0 : st.back();
                Llow[i] = pge + 1;
                st.push_back(i);
            }
        }
        {
            vector<int> st;
            st.reserve(n);
            for (int i = n; i >= 1; --i) {
                while (!st.empty() && a[st.back()] < a[i]) {
                    st.pop_back();
                }
                int nge = st.empty() ? (n + 1) : st.back();
                Rhigh[i] = nge - 1;
                st.push_back(i);
            }
        }

        vector<vector<int>> byLlow(n + 2);
        for (int i = 1; i <= n; ++i) {
            byLlow[Llow[i]].push_back(i);
        }

        Fenwick bitLeft(n);
        int totalActive = 0;
        vector<int> rmin(n + 1, -1), rmax(n + 1, -1);
        for (int l = 1; l <= n; ++l) {
            for (int idx : byLlow[l]) {
                bitLeft.add(idx, 1);
                ++totalActive;
            }
            if (totalActive >= k1) {
                int minPos = bitLeft.find_by_order(k1);
                rmin[l] = minPos;
                if (totalActive >= k1 + 1) {
                    int nextPos = bitLeft.find_by_order(k1 + 1);
                    rmax[l] = nextPos - 1;
                } else {
                    rmax[l] = n;
                }
            }
            bitLeft.add(l, -1);
            --totalActive;
        }

        vector<vector<int>> addAt(n + 2), removeAt(n + 2);
        for (int l = 1; l <= n; ++l) {
            if (rmin[l] != -1) {
                addAt[rmin[l]].push_back(l);
                int rem = rmax[l] + 1;
                if (rem <= n) {
                    removeAt[rem].push_back(l);
                }
            }
        }

        vector<vector<int>> endAt(n + 2);
        for (int i = 1; i <= n; ++i) {
            int rem = Rhigh[i] + 1;
            if (rem <= n + 1) {
                endAt[rem].push_back(i);
            }
        }

        Fenwick bitRight(n);
        vector<int> lmin(n + 1), lmax(n + 1);
        int totalRight = 0;
        for (int r = 1; r <= n; ++r) {
            for (int idx : endAt[r]) {
                bitRight.add(idx, -1);
                --totalRight;
            }
            bitRight.add(r, 1);
            ++totalRight;
            if (totalRight >= k2) {
                int p = totalRight - k2;
                if (p == 0) {
                    int t1 = bitRight.find_by_order(1);
                    lmin[r] = 1;
                    lmax[r] = t1;
                } else {
                    int tp = bitRight.find_by_order(p);
                    int tp1 = bitRight.find_by_order(p + 1);
                    lmin[r] = tp + 1;
                    lmax[r] = tp1;
                }
            } else {
                lmin[r] = r + 1;
                lmax[r] = r;
            }
        }

        Fenwick active(n);
        int answer = -1;
        for (int r = 1; r <= n; ++r) {
            for (int idx : removeAt[r]) {
                active.add(idx, -1);
            }
            for (int idx : addAt[r]) {
                active.add(idx, 1);
            }
            if (lmin[r] > lmax[r]) {
                continue;
            }
            int L = lmin[r];
            int R = min(lmax[r], r);
            if (L > R) {
                continue;
            }
            L = max(L, 1);
            int before = active.sum(L - 1);
            int upto = active.sum(R);
            if (upto > before) {
                int lCandidate = active.find_by_order(before + 1);
                answer = max(answer, r - lCandidate + 1);
            }
        }

        cout << answer << '\n';
    }

    return 0;
}

