#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    long long count = 0, prefixSum = 0;
    
    unordered_map<long long, long long> freq;
    freq[0] = 1;
    
    for (int i = 0; i < n; i++) {
        prefixSum += a[i];
        long long resto = ((prefixSum % n) + n) %n;
        
        if (freq.find(resto) != freq.end()) {
            count += freq[resto];
        }
        freq[resto]++;
    }
    
    cout << count << endl;
    return 0;
}