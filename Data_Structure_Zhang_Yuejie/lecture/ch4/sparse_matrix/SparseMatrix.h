#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Term {
public:
    int row;
    int col;
    int data;
};

class SparseMatrix {
private:
    int size;
    vector<Term*> elems;

public:
    SparseMatrix(const vector<vector<int> >& array, int rows, int cols) {
        size = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (array[i][j] != 0) {
                    Term* term = new Term();
                    term->row = i;
                    term->col = j;
                    term->data = array[i][j];
                    elems.push_back(term);
                    size++;
                }
            }
        }
    }

    friend istream& operator>>(istream& in, SparseMatrix& matrix) {
        int rows, cols;
        cout << "Enter the number of rows and columns: ";
        in >> rows >> cols;

        int** array = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            array[i] = new int[cols];
            cout << "Enter row " << i + 1 << ": ";
            for (int j = 0; j < cols; ++j) {
                in >> array[i][j];
            }
        }

        matrix = SparseMatrix(array, rows, cols);

        for (int i = 0; i < rows; ++i) {
            delete[] array[i];
        }
        delete[] array;

        return in;
    }
    friend ostream& operator<<(ostream& out, const SparseMatrix& matrix) {
        int rows = 0, cols = 0;

        // Find the number of rows and columns in the matrix
        for (const auto& term : matrix.elems) {
            rows = max(rows, term->row + 1);
            cols = max(cols, term->col + 1);
        }

        int** array = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            array[i] = new int[cols] {};

            // Fill in the array with matrix data
            for (const auto& term : matrix.elems) {
                if (term->row == i) {
                    array[i][term->col] = term->data;
                }
            }
        }

        // Print the matrix
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                out << array[i][j] << " ";
            }
            out << endl;
        }

        // Cleanup
        for (int i = 0; i < rows; ++i) {
            delete[] array[i];
        }
        delete[] array;

        return out;
    }
};

