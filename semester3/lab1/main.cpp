#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:

    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    double getReal() const { return real; }
    double getImag() const { return imag; }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex((real * other.real) - (imag * other.imag), (real * other.imag) + (imag * other.real));
    }

    void print() const {
        std::cout << real << " + " << imag << "i";
    }
};

class ComplexMatrix {
private:
    Complex** matrix;
    int rows;
    int cols;

public:

    ComplexMatrix(int r, int c) : rows(r), cols(c) {
        matrix = new Complex*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new Complex[cols];
        }
    }


    // Конструктор копіювання (глибоке копіювання)
    ComplexMatrix(const ComplexMatrix& other) : rows(other.rows), cols(other.cols) {
        matrix = new Complex*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new Complex[cols];
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    // Оператор присвоєння (глибоке копіювання)
    ComplexMatrix& operator=(const ComplexMatrix& other) {
        if (this == &other) return *this; // Захист від самоприсвоєння

        // Звільнення старої пам'яті
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;

        // Копіювання нових даних
        rows = other.rows;
        cols = other.cols;

        matrix = new Complex*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new Complex[cols];
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }

        return *this;
    }

    ~ComplexMatrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    ComplexMatrix operator+(const ComplexMatrix& other) const {
        ComplexMatrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.setValue(i, j, matrix[i][j] + other.getValue(i, j));
            }
        }
        return result;
    }

    ComplexMatrix operator-(const ComplexMatrix& other) const {
        ComplexMatrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.setValue(i, j, matrix[i][j] - other.getValue(i, j));
            }
        }
        return result;
    }

    ComplexMatrix operator*(const ComplexMatrix& other) const {
        if (cols != other.rows) {
            std::cerr << "Matrix dimensions do not match for multiplication!" << std::endl;
            return ComplexMatrix(0, 0);
        }
        ComplexMatrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                Complex sum;
                for (int k = 0; k < cols; ++k) {
                    sum = sum + (getValue(i, k) * other.getValue(k, j));
                }
                result.setValue(i, j, sum);
            }
        }
        return result;
    }


    void setValue(int r, int c, const Complex& value) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            matrix[r][c] = value;
        }
    }

    Complex getValue(int r, int c) const {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            return matrix[r][c];
        }
        return Complex();
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j].print();
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }


    ComplexMatrix strassenMultiply(const ComplexMatrix& other) const {
        return strassenMultiply(*this, other);
    }

private:
    // Допоміжна функція для алгоритму Штрассена
    ComplexMatrix strassenMultiply(const ComplexMatrix& A, const ComplexMatrix& B) const {
        int n = A.rows; // Передбачається, що A і B квадратні
        if (n == 1) {
            // Базовий випадок
            ComplexMatrix C(1, 1);
            C.setValue(0, 0, A.getValue(0, 0) * B.getValue(0, 0));
            return C;
        }

        int newSize = n / 2;

        // Створення підматриць
        ComplexMatrix A11(newSize, newSize);
        ComplexMatrix A12(newSize, newSize);
        ComplexMatrix A21(newSize, newSize);
        ComplexMatrix A22(newSize, newSize);
        ComplexMatrix B11(newSize, newSize);
        ComplexMatrix B12(newSize, newSize);
        ComplexMatrix B21(newSize, newSize);
        ComplexMatrix B22(newSize, newSize);

        // Заповнюємо підматриці
        for (int i = 0; i < newSize; ++i) {
            for (int j = 0; j < newSize; ++j) {
                A11.setValue(i, j, A.getValue(i, j));
                A12.setValue(i, j, A.getValue(i, j + newSize));
                A21.setValue(i, j, A.getValue(i + newSize, j));
                A22.setValue(i, j, A.getValue(i + newSize, j + newSize));

                B11.setValue(i, j, B.getValue(i, j));
                B12.setValue(i, j, B.getValue(i, j + newSize));
                B21.setValue(i, j, B.getValue(i + newSize, j));
                B22.setValue(i, j, B.getValue(i + newSize, j + newSize));
            }
        }

        // Розрахунок M1, M2, M3, M4, M5, M6, M7
        ComplexMatrix M1 = (A11 + A22).strassenMultiply(B11 + B22);
        ComplexMatrix M2 = (A21 + A22).strassenMultiply(B11);
        ComplexMatrix M3 = A11.strassenMultiply(B12 - B22);
        ComplexMatrix M4 = A22.strassenMultiply(B21 - B11);
        ComplexMatrix M5 = (A11 + A12).strassenMultiply(B22);
        ComplexMatrix M6 = (A21 - A11).strassenMultiply(B11 + B12);
        ComplexMatrix M7 = (A12 - A22).strassenMultiply(B21 + B22);

        // Складання результатів
        ComplexMatrix C(n, n);

        // C11 = M1 + M4 - M5 + M7
        for (int i = 0; i < newSize; ++i) {
            for (int j = 0; j < newSize; ++j) {
                C.setValue(i, j, M1.getValue(i, j) + M4.getValue(i, j) - M5.getValue(i, j) + M7.getValue(i, j));
            }
        }

        // C12 = M3 + M5
        for (int i = 0; i < newSize; ++i) {
            for (int j = 0; j < newSize; ++j) {
                C.setValue(i, j + newSize, M3.getValue(i, j) + M5.getValue(i, j));
            }
        }

        // C21 = M2 + M4
        for (int i = 0; i < newSize; ++i) {
            for (int j = 0; j < newSize; ++j) {
                C.setValue(i + newSize, j, M2.getValue(i, j) + M4.getValue(i, j));
            }
        }

        // C22 = M1 - M2 + M3 + M6
        for (int i = 0; i < newSize; ++i) {
            for (int j = 0; j < newSize; ++j) {
                C.setValue(i + newSize, j + newSize, M1.getValue(i, j) - M2.getValue(i, j) + M3.getValue(i, j) + M6.getValue(i, j));
            }
        }

        return C;
    }




};




int main() {
    ComplexMatrix m1(2, 2);
    ComplexMatrix m2(2, 2);

    // Заповнюємо першу матрицю
    m1.setValue(0, 0, Complex(1, 1));
    m1.setValue(0, 1, Complex(2, 2));
    m1.setValue(1, 0, Complex(3, 3));
    m1.setValue(1, 1, Complex(4, 4));

    // Заповнюємо другу матрицю
    m2.setValue(0, 0, Complex(5, 5));
    m2.setValue(0, 1, Complex(6, 6));
    m2.setValue(1, 0, Complex(7, 7));
    m2.setValue(1, 1, Complex(8, 8));

    // Множимо матриці
    ComplexMatrix result = m1.strassenMultiply(m2);

    m1.print();
    std::cout << "\n\n";

    m2.print();
    std::cout << "\n\n";
    // Виводимо результат
    result.print();

    return 0;
}
