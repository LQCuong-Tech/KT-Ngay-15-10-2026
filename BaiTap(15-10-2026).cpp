#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

bool docMaTranTrongSo(const string& filename, int**& matrix, int& n) {
    ifstream file(filename.c_str());
    if (!file.is_open()) {
        cerr << "Khong the mo file: " << filename << endl;
        return false;
    }
    file >> n;
	matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> matrix[i][j];
        }
    }
    file.close();
    return true;
}

void inMaTranTrongSo(int** matrix, int n) {
    char labels[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    cout << "=== MA TRAN TRONG SO CUA DO THI ===" << endl << endl;
    cout << "   ";
    for (int i = 0; i < n; ++i) {
        cout << setw(5) << labels[i];
    }
    cout << endl << "  " << string(5 * n + 3, '-') << endl;
    for (int i = 0; i < n; ++i) {
        cout << labels[i] << " |";
        for (int j = 0; j < n; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void giaiphongBoNho(int** matrix, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < n; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

int main() {
    string filename = "graph.txt";
    int** matrix =  NULL;
    int n = 0;
    if (docMaTranTrongSo(filename, matrix, n)) {
        inMaTranTrongSo(matrix, n);
        giaiphongBoNho(matrix, n);
    }
    return 0;
}
