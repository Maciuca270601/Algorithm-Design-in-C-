#include <bits/stdc++.h>

class Task {
 public:
    void solve() {
        read_input();
    }

 private:
    int n, k;
    int x, y;

    int expand_and_resolve(int dim, int x, int y) {
        if (dim == 1) {
            return 0;
        }

        int submatrix_dim = dim >> 1;

        // Pair (x,y) is in SUBMATRIX(1)
        if (x <= submatrix_dim && y <= submatrix_dim) {
            return expand_and_resolve(submatrix_dim, x, y);
        }

        // Pair (x,y) is in SUBMATRIX(2)
        if (x <= submatrix_dim && y > submatrix_dim) {
            return expand_and_resolve(submatrix_dim, x, y - submatrix_dim);
        }

        // Pair (x,y) is in SUBMATRIX(3)
        if (x > submatrix_dim && y <= submatrix_dim) {
            return expand_and_resolve(submatrix_dim, x - submatrix_dim, y);
        }

        // Pair (x,y) is in SUBMATRIX(4)
        if (x > submatrix_dim && y > submatrix_dim) {
            return !expand_and_resolve(submatrix_dim, x -
            submatrix_dim, y - submatrix_dim);
        }

        return -1;
    }

    void read_input() {
        std::ifstream fin("walsh.in");
        std::ofstream fout("walsh.out");
        fin >> n >> k;

        for (int i = 0; i < k; i++) {
            fin >> x >> y;
            fout << expand_and_resolve(n, x, y) << std::endl;
        }
        fin.close();
        fout.close();
    }
};

int main() {
    Task *task = new Task();
    if (!task) {
        std::cerr << "Error!\n";
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
