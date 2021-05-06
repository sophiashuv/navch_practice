#include <iostream>
#include <queue>
#include <numeric>
using namespace std;


queue<int> order_queue(vector<int> all_children, int n, int k) {
    queue<int> ordered_children = queue<int>();
    int i = 0, j = 0;
    for (auto it = all_children.begin(); all_children.size() >= k; )
    {
        j = i;
        auto dist = distance(all_children.begin() + i, all_children.end());
        ordered_children.push(*(all_children.begin() + i));
        if (dist <= k) i = k - dist;
        else i += k - 1;

        all_children.erase(all_children.begin() + j);
    }
    return ordered_children;
}

void print_result(queue<int> ordered_children) {
    while (ordered_children.size() != 1) {
        int curr_child = ordered_children.front();
        ordered_children.pop();
        cout << curr_child << " => ";
    }
    cout << ordered_children.front() << "\n";
}

int main() {
    unsigned long int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;
    vector<int> all_children(n);
    iota(all_children.begin(), all_children.end(), 1);
    queue<int> ordered_children = order_queue(all_children, n, k);
    
    print_result(ordered_children);

    return 0;
}