#include <iostream>
#include <deque>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    string inputFilename = "input.txt";
    string outputFilename = "output.txt";
    
    deque<double> numbers;
    
    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        cerr << "Ошибка: не удалось открыть файл " << inputFilename << endl;
        return 1;
    }
    
    copy(istream_iterator<double>(inputFile),
         istream_iterator<double>(),
         front_inserter(numbers));
    inputFile.close();
    
    if (numbers.empty()) {
        cerr << "Предупреждение: файл пуст или не содержит чисел" << endl;
        return 1;
    }
    
    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        cerr << "Ошибка: не удалось открыть файл " << outputFilename << endl;
        return 1;
    }
    
    copy(numbers.begin(), numbers.end(),
         ostream_iterator<double>(outputFile, "\n"));
    outputFile.close();
    
    cout << "Готово! Числа из файла " << inputFilename 
         << " записаны в обратном порядке в файл " << outputFilename << endl;
    
    return 0;
}
