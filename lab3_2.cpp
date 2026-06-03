#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void print_and_add(int t, deque<int>& x2, deque<int>& x3, deque<int>& x5) {
    cout << t << endl;
    x2.push_back(2 * t);
    x3.push_back(3 * t);
    x5.push_back(5 * t);
}

int main() {
    int n;
    cout << "Введите n: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "n должно быть больше 0" << endl;
        return 1;
    }
    
    deque<int> x2, x3, x5;
    
    print_and_add(1, x2, x3, x5);
    int k = 1;
    
    while (k < n) {
        int min_val = min({x2.front(), x3.front(), x5.front()});
        
        print_and_add(min_val, x2, x3, x5);
        k++;
        
        if (!x2.empty() && x2.front() == min_val) {
            x2.pop_front();
        }
        if (!x3.empty() && x3.front() == min_val) {
            x3.pop_front();
        }
        if (!x5.empty() && x5.front() == min_val) {
            x5.pop_front();
        }
    }
    
    return 0;
}
