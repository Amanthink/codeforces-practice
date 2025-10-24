#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 250005;
const int BLOCK_SIZE = 500;

int n, q;
vector<int> a;
vector<pair<int, int>> queries;
vector<int> query_indices;

int mo_l, mo_r;
long long current_cost;
int freq0[MAXN], freq1[MAXN];
vector<int> pos0, pos1;
int p0_map[MAXN], p1_map[MAXN];

struct Query {
    int l, r, idx;
};

bool compareQueries(const Query& a, const Query& b) {
    int block_a = a.l / BLOCK_SIZE;
    int block_b = b.l / BLOCK_SIZE;
    if (block_a != block_b) {
        return block_a < block_b;
    }
    if (block_a % 2 == 0) {
        return a.r < b.r;
    }
    return a.r > b.r;
}

void add(int idx) {
    if (a[idx] == 0) {
        int pos_in_vec = p0_map[idx];
        freq0[pos_in_vec]++;
        if (freq0[pos_in_vec] >= 3) {
            int i = pos_in_vec - 2;
            int j = pos_in_vec - 1;
            int k = pos_in_vec;
            if (i >= 0) {
                current_cost += min(pos0[k] - pos0[j], pos0[j] - pos0[i]);
            }
        }
    } else {
        int pos_in_vec = p1_map[idx];
        freq1[pos_in_vec]++;
        if (freq1[pos_in_vec] >= 3) {
            int i = pos_in_vec - 2;
            int j = pos_in_vec - 1;
            int k = pos_in_vec;
            if (i >= 0) {
                current_cost += min(pos1[k] - pos1[j], pos1[j] - pos1[i]);
            }
        }
    }
}

void remove(int idx) {
    if (a[idx] == 0) {
        int pos_in_vec = p0_map[idx];
        if (freq0[pos_in_vec] >= 3) {
            int i = pos_in_vec - 2;
            int j = pos_in_vec - 1;
            int k = pos_in_vec;
            if (i >= 0) {
                current_cost -= min(pos0[k] - pos0[j], pos0[j] - pos0[i]);
            }
        }
        freq0[pos_in_vec]--;
    } else {
        int pos_in_vec = p1_map[idx];
        if (freq1[pos_in_vec] >= 3) {
            int i = pos_in_vec - 2;
            int j = pos_in_vec - 1;
            int k = pos_in_vec;
            if (i >= 0) {
                current_cost -= min(pos1[k] - pos1[j], pos1[j] - pos1[i]);
            }
        }
        freq1[pos_in_vec]--;
    }
}

void solve() {
    cin >> n >> q;
    a.resize(n);
    pos0.clear();
    pos1.clear();
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            p0_map[i] = pos0.size();
            pos0.push_back(i);
        } else {
            p1_map[i] = pos1.size();
            pos1.push_back(i);
        }
    }

    vector<int> prefix_sum0(n + 1, 0);
    vector<int> prefix_sum1(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum0[i+1] = prefix_sum0[i] + (a[i] == 0);
        prefix_sum1[i+1] = prefix_sum1[i] + (a[i] == 1);
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end(), compareQueries);

    vector<long long> answers(q);
    mo_l = 0;
    mo_r = -1;
    current_cost = 0;
    
    // Initialize frequency arrays
    fill(freq0, freq0 + pos0.size() + 1, 0);
    fill(freq1, freq1 + pos1.size() + 1, 0);

    for (const auto& query : queries) {
        int l = query.l;
        int r = query.r;

        int num0 = prefix_sum0[r+1] - prefix_sum0[l];
        int num1 = prefix_sum1[r+1] - prefix_sum1[l];

        if (num0 % 3 != 0 || num1 % 3 != 0) {
            answers[query.idx] = -1;
            continue;
        }

        while (mo_l > l) {
            mo_l--;
            add(mo_l);
        }
        while (mo_r < r) {
            mo_r++;
            add(mo_r);
        }
        while (mo_l < l) {
            remove(mo_l);
            mo_l++;
        }
        while (mo_r > r) {
            remove(mo_r);
            mo_r--;
        }
        
        answers[query.idx] = current_cost;
    }

    for (int i = 0; i < q; ++i) {
        cout << answers[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
