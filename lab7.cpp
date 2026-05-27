#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<string, int> token_id;
int next_id = 1;


int make_tab_id(const string& id) {
    auto it = token_id.find(id);
    if (it != token_id.end()) {
        return it->second;
    }
    token_id[id] = next_id;
    return next_id++;
}

vector<int> result_id(const vector<string>& ids) {
    vector<int> result;
    for (const auto& id : ids) {
        result.push_back(make_tab_id(id));
    }
    return result;
}

int main() {
    vector<string> id;
    string input;

    cout << "Введите идентификаторы (через пробел, для завершения введите 0): ";
    while (cin >> input) {
        if (input == "0") break;
        id.push_back(input);
    }

    vector<int> result = result_id(id);

    cout << "Результат: {";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "}" << endl;

    return 0;
}
