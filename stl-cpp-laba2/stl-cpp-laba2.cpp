/*

Лабораторная работа # 2. C++: STL.

Вариант 2
Реализуйте набор основных статистических функций (среднее арифметическое, наибольшее значение,
наименьшее значение, сумма всех значений) для вектора вещественных чисел.

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

double sum_of_elements(vector<double> v) {
    double s = 0;
    for (int i = 0; i < v.size(); i++) s += v[i];
    return s;
}

double average(vector<double> v) {
    return sum_of_elements(v) / v.size();
}

double Min(vector<double> v) {
    double m = v[0];
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < m) m = v[i];
    }
    return m;
}

double Max(vector<double> v) {
    double m = v[0];
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > m) m = v[i];
    }
    return m;
}

void print_vector(vector<double> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void print_vector(vector<double> v, string filename) {
    ofstream out(filename);
    for (int i = 0; i < v.size(); i++) {
        out << v[i] << " ";
    }
    out << endl;
}

void read_vector(vector<double>& v, int N) {
    double tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
}

void read_vector(vector<double>& v, string filename) {
    ifstream in(filename);
    double tmp;
    while (!in.eof()) {
        in >> tmp;
        v.push_back(tmp);
    }
}

void print_vector_statistics(vector<double>& v) {
    cout << "Average: " << average(v) << endl;
    cout << "Min: " << Min(v) << endl;
    cout << "Max: " << Max(v) << endl;
    cout << "Sum of elements : " << sum_of_elements(v) << endl;
}

void print_vector_statistics(vector<double>& v, string filename) {
    ofstream out(filename);
    out << "Average: " << average(v) << endl;
    out << "Min: " << Min(v) << endl;
    out << "Max: " << Max(v) << endl;
    out << "Sum of elements : " << sum_of_elements(v) << endl;
}

int main() {
    vector<double> v;

    read_vector(v, "in.txt");

    print_vector(v);
    print_vector(v, "out.txt");

    print_vector_statistics(v);
    print_vector_statistics(v, "statistics.txt");

    return 0;
}