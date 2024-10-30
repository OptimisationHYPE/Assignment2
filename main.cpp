#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
#include <iomanip>

std::string buffer;
typedef double element_t;
typedef std::vector<element_t> row_t;
typedef std::vector<row_t> matrix_t;
std::vector<element_t> vbuffer;



template<typename T>
std::stringstream& operator >> (std::stringstream& ss, std::vector<T>& buffer){
    buffer.clear();
    for (T temp;ss >> temp;) buffer.push_back(temp);
    return ss;
}
template<typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v){
    for (T e:v)os << e << ' ';
    return os;
}

template<typename T>
std::ostream& operator << (std::ostream& os, const std::vector<std::vector<T>>& v){
    for (auto e:v)os << e << '\n';
    return os;
}


inline element_t operator * (const row_t& a,const row_t& b) {
    double acum = 0;
    for (int i=0; i< a.size(); i++){
        acum += a[i] * b[i];}
    return acum;}

class Matrix{
public:
    
    size_t n,m;
    matrix_t data;

    Matrix(){}
    Matrix(matrix_t data):data(data){
        n = data.size();
        m = data[0].size();
    }

    static Matrix input(std::istream& istream){
        matrix_t temp = {};
        for (getline(istream, buffer);!buffer.empty();getline(istream, buffer)) {
            std::stringstream sstream(buffer);
            sstream >> vbuffer;
            temp.push_back(vbuffer);
        }
        return Matrix(temp);
    }

    static Matrix diag(Matrix&  x){
        // Assume that x.n == 1
        matrix_t temp(x.m, row_t (x.m, 0));
        for (int i=0;i<x.m;i++)
            temp[i][i] = x.data[0][i];
        return Matrix(temp);
    }
    static Matrix identity(size_t size){
        Matrix ones_vector({row_t (size, 1)});
        return diag(ones_vector);
    }
    Matrix T(){
        matrix_t transposed(m);
        for (int i =0; i< m;i++){transposed[i] = this->operator()(i);}
        return Matrix(transposed);
    }
    row_t operator[] (int t)const {return data[t];} // get row operator
    row_t operator() (int t)const {                 // get column operator
        row_t temp(n,0);
        for (int i = 0; i< n; i++)
            temp[i] = data[i][t];
        return temp;
    } 
};
std::ostream& operator << (std::ostream& os, Matrix& m){return os << m.data;}
std::istream& operator >> (std::istream& is, Matrix& m){ m = Matrix::input(is);}
Matrix operator * (const Matrix& a, const Matrix& b){ // Matrix multiplication
    // Assume that a.m == b.n
    matrix_t result(a.n, row_t(b.m,0));
    for (int i = 0;i < result.size();i++)
        for (int j = 0; j< result[0].size(); j++){
            result[i][j] = a[i] * b(j);
            // std::cout << a[i] << " * " << b(i)  << " = " << result[i][j] << '\n';
        }
    return Matrix(result);
}

using std::cin,std::cout;
// By default all vectors are horizontal
int main(){
    // cout.precision(1);
    std::ios::sync_with_stdio(false);
    Matrix C, A, x, b;
    
    double eps = 0.001, alph1 = 0.5, aplph2 = 0.9;
    cin >> C >> A >> x;
    // cin >> b;
    while (true)
    {
        Matrix D = Matrix::diag(x);
        Matrix _A = A * D;
        Matrix _C = D * C.T();
        Matrix I = Matrix::identity(x.m);
        cout << D << '\n';
        cout << _A << '\n';
        cout << C << '\n';
        cout << _C << '\n';

        break;
    }
    

    return 0;
}

/*
1 1 0 0

2 4 1 0
1 3 0 -1

0.5 3.5 1 2



*/