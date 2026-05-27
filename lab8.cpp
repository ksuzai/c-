#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

void print(const vector<int>& v) {
    for (int x : v) cout << x << " ";
}

int main() {
    vector<int> v1 = { 1, 2, 3, 4, 5 };
    vector<int> v2 = { 1, 2, 3, 0, 5 };

    cout << "1. for_each (умножить каждый элемент на 2)" << endl;
    vector<int> for_each_v = v1;
    for_each(for_each_v.begin(), for_each_v.end(), [](int& x) { x *= 2; });
    cout << "Исходный: "; print(v1); cout << endl;
    cout << "Результат: "; print(for_each_v); cout << endl << endl;

    cout << "2. mismatch (поиск первого отличия)" << endl;
    auto diff = mismatch(v1.begin(), v1.end(), v2.begin());
    cout << "v1: "; print(v1); cout << endl;
    cout << "v2: "; print(v2); cout << endl;
    cout << "Первое отличие на позиции " << (diff.first - v1.begin()) << endl << endl;

    cout << "3. replace_copy (заменить 3 на 99)" << endl;
    vector<int> replace_result;
    replace_copy(v1.begin(), v1.end(), back_inserter(replace_result), 3, 99);
    cout << "Исходный: "; print(v1); cout << endl;
    cout << "Результат: "; print(replace_result); cout << endl << endl;

    cout << "4. remove (удалить все 3)" << endl;
    vector<int> remove_v = v1;
    auto new_end = remove(remove_v.begin(), remove_v.end(), 3);
    remove_v.erase(new_end, remove_v.end());
    cout << "Исходный: "; print(v1); cout << endl;
    cout << "Результат: ";  print(remove_v); cout << endl << endl;

    cout << "5. rotate (сдвиг на 2 позиции)" << endl;
    vector<int> rotate_v = v1;
    rotate(rotate_v.begin(), rotate_v.begin() + 2, rotate_v.end());
    cout << "Исходный: "; print(v1); cout << endl;
    cout << "Результат: ";  print(rotate_v); cout << endl << endl;

    cout << "6. partition (четные в начало)" << endl;
    vector<int> partition_v = v1;
    partition(partition_v.begin(), partition_v.end(), [](int x) { return x % 2 == 0; });
    cout << "Исходный: "; print(v1); cout << endl;
    cout << "Результат: ";  print(partition_v); cout << endl << endl;

    cout << "7. set_difference (разность множеств)" << endl;
    vector<int> A = v1;
    vector<int> B = v2;
    vector<int> diff_result;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    set_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(diff_result));
    cout << "Множество A: "; print(A); cout << endl;
    cout << "Множество B: "; print(B); cout << endl;
    cout << "A\\B: "; print(diff_result); cout << endl << endl;

    cout << "accumulate (сумма элементов)" << endl;
    vector<int> nums = v1;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    cout << "Вектор: "; print(nums); cout << endl;
    cout << "Сумма элементов: " << sum << endl;

    return 0;
}
