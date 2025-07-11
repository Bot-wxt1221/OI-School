#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Gem {
    long long A;
    long long B;
};

bool compareGems(const Gem& a, const Gem& b) {
    if (a.B != b.B) {
        return a.B < b.B;
    }
    return a.A < b.A;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<Gem> gems(N);
    
    for (int i = 0; i < N; i++) {
        cin >> gems[i].A;
    }

 for (int i = 0; i < N; i++) {
        cin >> gems[i].B;
    }   
    sort(gems.begin(), gems.end(), compareGems);
    
    long long t = 0;
    priority_queue<long long> max_heap;
    
    for (int i = 0; i < N; i++) {
        if (t <= gems[i].B) {
            t += gems[i].A;
            max_heap.push(gems[i].A);
        } else if (!max_heap.empty() && max_heap.top() > gems[i].A) {
            t = t - max_heap.top() + gems[i].A;
            max_heap.pop();
            max_heap.push(gems[i].A);
        }
    }
    
    cout << max_heap.size() << endl;
    
    return 0;
}
