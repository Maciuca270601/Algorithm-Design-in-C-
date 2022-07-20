#include <bits/stdc++.h>
#include <vector>

class Task {
 public:
    void solve() {
        read_input();
    }

 private:
    std::vector<int> target;
    std::vector<int> numbers;
    std::vector<int> points;
    int n, x, p, k;

    void read_input() {
        std::ifstream fin("prinel.in");
        std::ofstream fout("prinel.out");

        fin >> n >> k;

        // adding one fictive element because of indexing
        numbers.push_back(-1);
        for (int i = 0; i < n; i++) {
            fin >> x;
            numbers.push_back(x);
        }

        // adding one fictive element because of indexing
        points.push_back(-1);
        for (int i = 0; i < n; i++) {
            fin >> p;
            points.push_back(p);
        }

        // adding one fictive element because of indexing
        target.push_back(-1);
        // BASE CASE:

        // target[1] = 0;
        target.push_back(0);
        // target[2] = 1;
        target.push_back(1);

        // get the maximum element from the array
        int maximum = *max_element(numbers.rbegin(), numbers.rend());

        // obtain all targets between 1 and maximum
        populate_targets(maximum);

        // RUCSAC

        // if all operations could be used there is no need for RUCSAC
        int sum_pts = 0;
        int sum_weights = 0;
        for (int i = 1; i <= n; i++) {
            sum_pts += points[i];
            sum_weights += target[numbers[i]];
        }

        if (sum_weights <= k) {
            fout << sum_pts << std::endl;
        } else {
            // do the RUCSAC
            int result = rucsac(n, k, target, points, numbers);
            fout << result << std::endl;
        }

        fin.close();
        fout.close();
    }

    void populate_targets(int nr) {
        for (int i = 3; i <= nr; i++) {
            // the target can not be greater than the maximum
            // target[i] = nr;
            target.push_back(nr);
            for (int div = 1; div * div <= i; div++) {
                // the list of divisors is composed either by
                // div or nr/div (if nr/div is an integer)
                if (i % div == 0) {
                    if (i - div > 0) {
                        int aux = target[i - div] + 1;
                        aux = std::min(target[i], aux);
                        target.pop_back();
                        target.push_back(aux);
                    }
                }
                if (i % (i / div) == 0) {
                    if (i - (i / div) > 0) {
                        int aux = target[i - (i / div)] + 1;
                        aux = std::min(target[i], aux);
                        target.pop_back();
                        target.push_back(aux);
                    }
                }
            }
        }
    }

    // n   = number of elements
    // W   = numbers of total operations that could be done
    // (w[i], p[i]) = caracteristics of the specific object

    int rucsac(int n, int W, std::vector<int> &w, std::vector<int> &p,
                std::vector<int> &num) {
        // dp is a matrix of size (n + 1) x (W + 1)
        std::vector<std::vector<int> > dp(n + 1, std::vector<int>(W + 1, 0));

        // BASE CASE:
        // dp[0][*] pentru mulțimea vidă
        // dp[*][0] pentru situația în care ghiozdanul are capacitate 0
        for (int cap = 0; cap <= W; ++cap) {
            dp[0][cap] = 0;
        }

        // General case:
        for (int i = 1; i <= n; ++i) {
            for (int cap = 0; cap <= W; ++cap) {
                // don't use the object for i step => use object from step i-1
                dp[i][cap] = dp[i-1][cap];

                // use the object => the bag should contain at most cap - w[i]
                // operations
                if (cap - w[num[i]] >= 0) {
                    int sol_aux = dp[i-1][cap - w[num[i]]] + p[i];
                    dp[i][cap] = std::max(dp[i][cap], sol_aux);
                }
            }
        }

        return dp[n][W];
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
