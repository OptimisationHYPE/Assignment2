#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <stdexcept>
#include <cmath>

std::string buffer;
typedef std::vector<double> row_t;
typedef std::vector<row_t> matrix_t;
std::vector<double> vbuffer;

template<typename T>
std::stringstream& operator>>(std::stringstream& ss, std::vector<T>& buffer) {
    buffer.clear();
    for (T temp; ss >> temp;) buffer.push_back(temp);
    return ss;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    for (T e : v) os << e << ' ';
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& v) {
    for (auto e : v) os << e << '\n';
    return os;
}

inline double operator*(const row_t& a, const row_t& b) { // dot product
    double acum = 0;
    for (int i = 0; i < a.size(); i++)acum += a[i] * b[i];
    return acum;
}



class Matrix {
public:
    size_t n, m;
    matrix_t data;

    Matrix() {}
    Matrix(matrix_t data) : data(data) {
        n = data.size();
        m = data[0].size();
    }

    static Matrix input(std::istream& istream = std::cin) {
        matrix_t temp = {};
        for (getline(istream, buffer); !buffer.empty(); getline(istream, buffer)) {
            std::stringstream sstream(buffer);
            sstream >> vbuffer;
            temp.push_back(vbuffer);
        }
        return Matrix(temp);
    }

    static Matrix diag(Matrix& x) {
        // Assume that x.n == 1
        matrix_t temp(x.m, row_t(x.m, 0));
        for (int i = 0; i < x.m; i++)
            temp[i][i] = x.data[0][i];
        return Matrix(temp);
    }

    static Matrix identity(size_t size) {
        Matrix ones_vector({ row_t(size, 1) });
        return diag(ones_vector);
    }

    Matrix T() {
        matrix_t transposed(m);
        for (int i = 0; i < m; i++) { transposed[i] = this->operator()(i); }
        return Matrix(transposed);
    }

    Matrix Inverse() {
        if (n != m) throw std::invalid_argument("Matrix must be square to calculate inverse");

        Matrix augmented = *this;  // Copy the original matrix
        Matrix identity_matrix = Matrix::identity(n);

        for (size_t i = 0; i < n; i++)
            augmented.data[i].insert(augmented.data[i].end(), identity_matrix.data[i].begin(), identity_matrix.data[i].end());

        for (size_t i = 0; i < n; i++) {
            double pivot = augmented.data[i][i];
            if (pivot == 0) throw std::runtime_error("Matrix is singular and cannot be inverted");

            for (size_t j = 0; j < 2 * n; j++)
                augmented.data[i][j] /= pivot;

            for (size_t k = 0; k < n; k++) {
                if (k != i) {
                    double factor = augmented.data[k][i];
                    for (size_t j = 0; j < 2 * n; j++)
                        augmented.data[k][j] -= factor * augmented.data[i][j];
                }
            }
        }

        matrix_t inverse_data(n, row_t(n));
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                inverse_data[i][j] = augmented.data[i][j + n];
            }
        }

        return Matrix(inverse_data);
    }

    row_t operator[](int t) const { return data[t]; } // Get row operator
    row_t operator()(int t) const {                   // Get column operator
        row_t temp(n, 0);
        for (int i = 0; i < n; i++)
            temp[i] = data[i][t];
        return temp;
    }
};

std::ostream& operator<<(std::ostream& os, Matrix& m) { return os << m.data; }
std::istream& operator>>(std::istream& is, Matrix& m) { m = Matrix::input(is); }
Matrix operator*(const Matrix& a, const Matrix& b) { // Matrix multiplication
    // Assume that a.m == b.n
    matrix_t result(a.n, row_t(b.m));
    for (int i = 0; i < result.size(); i++)
        for (int j = 0; j < result[0].size(); j++) {
            result[i][j] = a[i] * b(j);
        }
    return Matrix(result);
}
Matrix operator -(const Matrix& a, const Matrix& b) { // Matrix multiplication
    // Assume that a.m == b.m && a.n == b.n
    matrix_t result(a.n, row_t(a.m));
    for (int i = 0; i < result.size(); i++)
        for (int j = 0; j < result[0].size(); j++) {
            result[i][j] = a.data[i][j] - b.data[i][j];
        }
    return Matrix(result);
}
Matrix operator*(const Matrix& a, const double coef) { // mult Matrix by coeficient
    matrix_t copy = a.data;
    for (int i = 0; i < copy.size(); i++)
        for (int j = 0; j< copy[0].size();j++)
            copy[i][j] *= coef;
    return Matrix(copy);
}
Matrix operator +(const Matrix& a, const Matrix& b) { // Matrix sum
    matrix_t result(a.n, row_t(a.m));
    for (int i = 0; i < result.size(); i++)
        for (int j = 0; j < result[0].size(); j++) {
            result[i][j] = a.data[i][j] + b.data[i][j];
        }
    return Matrix(result);
}

using std::cin, std::cout;

double min(Matrix& m){
    double ans = 0;
    for (row_t row: m.data)
        for (auto element: row) 
            ans = std::min(ans, element);
    return ans;
}

double distance(const row_t& x_, const row_t& x) {
    if (x_.size() != x.size()) throw std::invalid_argument("Vectors must be of the same length to calculate distance");
    double sum_of_squares = 0;
    for (size_t i = 0; i < x_.size(); ++i) 
        sum_of_squares += (x_[i] - x[i]) * (x_[i] - x[i]);
    return std::sqrt(sum_of_squares);
}
Matrix interPointAlgorithm(Matrix& C, Matrix& A, Matrix x, double alpha, double eps){
    int n = C.m;
    while (true) {
        Matrix D = Matrix::diag(x);
        Matrix A1 = A * D;
        Matrix I = Matrix::identity(x.m);
        Matrix P = I - A1.T() * (A1 * A1.T()).Inverse() * A1;
        Matrix cp = P *(D * C.T());
        double v = std::abs(min(cp)),coef = alpha / v;
        Matrix x1 = Matrix({row_t(n,1)}).T(); // vector of ones vertical
        Matrix cpm = cp*coef;
        Matrix x_new = x1 + cpm;
        Matrix x_= D * x_new;
        cout << x_ << '\n';
        if (distance(x[0],x_(0)) < eps)return x_;
        x = x_.T();
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    Matrix C = Matrix::input(), A = Matrix:: input() , x = Matrix::input(), b;
    double eps =  0.00001, alph1 = 0.5, alph2 = 0.9;
    interPointAlgorithm(C,A,x,alph1,eps);
    return 0;
}
/*
1 1 0 0

2 4 1 0
1 3 0 -1

0.5 3.5 1 2



*/