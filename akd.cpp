#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // Count frequency of each stick length
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        
        // Collect pairs and singles for symmetrical polygon
        vector<int> pairs;    // Sticks that can be used in pairs
        vector<int> singles;  // Sticks that can be used individually
        
        for (auto& p : freq) {
            int length = p.first;
            int count = p.second;
            
            // Add pairs (each pair contributes 2 sides)
            for (int i = 0; i < count / 2; i++) {
                pairs.push_back(length);
            }
            
            // Add leftover single stick
            if (count % 2 == 1) {
                singles.push_back(length);
            }
        }
        
        // Sort in descending order to maximize perimeter
        sort(pairs.rbegin(), pairs.rend());
        sort(singles.rbegin(), singles.rend());
        
        long long max_perimeter = 0;
        
        // Try even-sided polygons (pairs only)
        for (int num_pairs = 2; num_pairs <= (int)pairs.size(); num_pairs++) {
            vector<int> sides;
            for (int i = 0; i < num_pairs; i++) {
                sides.push_back(pairs[i]);
                sides.push_back(pairs[i]);
            }
            
            sort(sides.rbegin(), sides.rend());
            long long perimeter = 0;
            for (int side : sides) {
                perimeter += side;
            }
            
            // Check triangle inequality
            long long max_side = sides[0];
            long long sum_others = perimeter - max_side;
            
            if (max_side < sum_others) {
                max_perimeter = max(max_perimeter, perimeter);
            }
        }
        
        // Try odd-sided polygons (pairs + 1 single)
        if (!singles.empty()) {
            for (int single : singles) {
                for (int num_pairs = 1; num_pairs <= (int)pairs.size(); num_pairs++) {
                    vector<int> sides;
                    sides.push_back(single);
                    for (int i = 0; i < num_pairs; i++) {
                        sides.push_back(pairs[i]);
                        sides.push_back(pairs[i]);
                    }
                    
                    if (sides.size() < 3) continue;  // Need at least 3 sides
                    
                    sort(sides.rbegin(), sides.rend());
                    long long perimeter = 0;
                    for (int side : sides) {
                        perimeter += side;
                    }
                    
                    // Check triangle inequality
                    long long max_side = sides[0];
                    long long sum_others = perimeter - max_side;
                    
                    if (max_side < sum_others) {
                        max_perimeter = max(max_perimeter, perimeter);
                    }
                }
            }
        }
        
        cout << max_perimeter << endl;
    }
    return 0;
}
