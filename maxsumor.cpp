#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    int count;             // number of available numbers passing through this node
    TrieNode* child[2];    // 0- and 1-branches
    TrieNode() : count(0) { child[0] = child[1] = nullptr; }
};

class BitwiseTrie {
    TrieNode* root;
    static const int MAXB = 31; // assume 32-bit signed ints

public:
    BitwiseTrie() { root = new TrieNode(); }

    void insert(int val) {
        TrieNode* cur = root;
        for (int b = MAXB; b >= 0; --b) {
            int bit = (val >> b) & 1;
            if (!cur->child[bit]) cur->child[bit] = new TrieNode();
            cur = cur->child[bit];
            cur->count++;
        }
    }

    void erase(int val) {
        TrieNode* cur = root;
        for (int b = MAXB; b >= 0; --b) {
            int bit = (val >> b) & 1;
            cur = cur->child[bit];
            cur->count--;
        }
    }

    // Find and remove best value from trie for given b_val
    int extractBest(int b_val) {
        TrieNode* cur = root;
        int res = 0;
        for (int b = MAXB; b >= 0; --b) {
            int bit = (b_val >> b) & 1;
            int preferred;
            if (bit == 0) {
                // Try to set this bit to 1 by choosing a=1 if possible
                preferred = 1;
                if (cur->child[preferred] && cur->child[preferred]->count > 0) {
                    res |= (1 << b);
                } else {
                    preferred = 0;
                }
            } else {
                // OR already has 1, try 0 if available to save bigger bits
                preferred = 0;
                if (!(cur->child[preferred] && cur->child[preferred]->count > 0))
                    preferred = 1;
                if (preferred == 1) res |= (1 << b);
            }
            cur = cur->child[preferred];
        }
        erase(res); // remove chosen value
        return res;
    }
};

pair<long long, vector<int>> maximizeBitwiseORSum(vector<int> a, vector<int> b) {
    int n = a.size();
    vector<pair<int,int>> b_sorted;
    for (int i = 0; i < n; ++i) b_sorted.push_back({b[i], i});
    sort(b_sorted.rbegin(), b_sorted.rend()); // sort by b descending

    BitwiseTrie trie;
    for (int x : a) trie.insert(x);

    long long total_sum = 0;
    vector<int> result_a(n);

    for (auto& [b_val, idx] : b_sorted) {
        int chosen = trie.extractBest(b_val);
        result_a[idx] = chosen;
        total_sum += (chosen | b_val);
    }
    return {total_sum, result_a};
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        int n = r - l + 1;
        
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++){ 
            a[i] = l + i;           
            b[i] = l + i;            
        }
        
        pair<long long, vector<int>> ans = maximizeBitwiseORSum(a, b);
        cout << ans.first << endl;
        for(int i = 0; i < n; i++){
            cout << ans.second[i];
            if(i < n - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}