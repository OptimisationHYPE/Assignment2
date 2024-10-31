#include <bits/stdc++.h>

using namespace std;

tuple<vector<float>, vector<vector<float>>, vector<float>, float> input() {
    // ввод вектора b
    vector<float> C, b;
    vector<vector<float>> A;
    float eps;

    string s;
    int n;

    while (true) {
        getline(cin, s);
        if (s.empty()) {
            break;
        }
        stringstream ss(s);
        while (ss >> n) {
            C.push_back(n);
        }
    }

    // ввод матрицы А
    while (true) {
        getline(cin, s);
        if (s.empty()) {
            break;
        }

        stringstream ss(s);
        while (ss >> n) {
            b.push_back(n);
        }
        A.push_back(b);
        b.clear();
    }

    // ввод вектора b
    for (int i = 0; i < A.size(); i++) {
        cin >> n;
        b.push_back(n);
    }

    cin >> eps;

    return {C, A, b, eps};
}

bool is_close(float a, float b, float eps) {
    return -eps < a - b && a - b <= eps;
}

bool is_less(float a, float b, float eps) { return a - b <= -eps; }

bool is_less_or_equal(float a, float b, float eps) { return a - b <= eps; }

// Maximization
void simplex(const vector<float> &C, const vector<vector<float>> &A,
             const vector<float> &b, const float eps) {
    // main table
    int n = A.size() + 1, m = C.size() + A.size() + 1;
    vector<vector<float>> M(n, vector<float>(m));
    // basic variables
    vector<int> basic(A.size());
    for (int i = 0; i < A.size(); i++)
        basic[i] = C.size() + i;

    // Fill in the z-row
    for (int j = 0; j < m; j++) {
        M[0][j] = j < C.size() ? -C[j] : 0;
    }
    // Fill in the coefficients matrix
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < C.size(); j++) {
            M[i][j] = A[i - 1][j];
        }
    }
    // Fill in the identity matrix
    for (int i = 1; i < n; i++) {
        for (int j = C.size(); j < m - 1; j++) {
            M[i][j] = i - 1 == j - C.size() ? 1 : 0;
        }
    }
    // rhs column
    for (int i = 1; i < n; i++) {
        M[i][m - 1] = b[i - 1];
    }

    /*for (int i = 0; i < A.size(); i++) {*/
    /*    for (int j = 0; j < A[i].size(); j++) {*/
    /*        cout << A[i][j] << " ";*/
    /*    }*/
    /*    cout << "\n";*/
    /*}*/

    float prev_z = 0;
    while (true) {
        // find min in z
        int entering = -1;
        float min_v = INFINITY;
        for (int j = 0; j < C.size(); j++) {
            if (is_less(M[0][j], min_v, eps) && is_less(M[0][j], 0, eps)) {
                min_v = M[0][j];
                entering = j;
            }
        }
        if (entering == -1) {
            printf("Normal finish\n");
            break;
        }

        // find min ratio
        int leaving_i = -1;
        min_v = INFINITY;
        for (int i = 1; i < n; i++) {
            if (is_less_or_equal(M[i][entering], 0, eps))
                continue;
            if (is_less(M[i][m - 1] / M[i][entering], min_v, eps)) {
                min_v = M[i][m - 1] / M[i][entering];
                leaving_i = i;
            }
        }
        if (leaving_i == -1) {
            printf("Unbounded solution\n");
            return;
        }
        basic[leaving_i - 1] = entering;

        // Row operations
        //
        // Normalize the row
        float pivot = M[leaving_i][entering];
        for (int j = 0; j < m; j++) {
            M[leaving_i][j] /= pivot;
        }
        // Row reduction
        for (int i = 0; i < n; i++) {
            if (i == leaving_i)
                continue;
            float scalar = M[i][entering] / pivot;
            for (int j = 0; j < m; j++) {
                M[i][j] -= scalar * M[leaving_i][j];
            }
        }

        if (is_close(prev_z, M[0][m - 1], eps)) {
            printf("Epsilon finish\n");
            break;
        }
    }

    // output
    printf("z = %f\nSolution: ", M[0][m - 1]);
    for (int i = 0; i < C.size(); i++) {
        if (auto it = find(basic.begin(), basic.end(), i); it != basic.end()) {
            printf("%f ", M[(it - basic.begin()) + 1][m - 1]);
        } else {
            printf("0 ");
        }
    }
    printf("\n");
}

int main() {
    auto [C, A, b, eps] = input();
    simplex(C, A, b, eps);
    return 0;
}