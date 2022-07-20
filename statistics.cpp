#include <bits/stdc++.h>
#include <vector>

class Task {
 public:
    void solve() {
        read_input();
    }

 private:
    int n;
    std::vector<std::string> words;
    std::vector<int> dominance;
    std::string word;
    char chr;
    int result;

    // function that returns the number of occurrences of a character
    // in a string
    static int get_force_of_char(std::string s1, char chr) {
        int counter = 0;
        for (int i = 0; (i = s1.find(chr, i)) != std::string::npos; i++) {
            counter++;
        }
        return counter;
    }

    void read_input() {
        std::ifstream fin("statistics.in");
        std::ofstream fout("statistics.out");
        fin >> n;

        for (int i = 0; i < n; i++) {
            fin >> word;
            words.push_back(word);
        }

        result = -1;

        // iterating through all the letters in the alphabet
        for (char i = 'a'; i <= 'z'; i++) {
            int counter = 0;
            int sum_dom = 0;
            int sem = 0;
            int len = 0;
            for (int w = 0; w < n; w++) {
                // dom stores the gain of each word
                // the gain is described in the README
                int force = get_force_of_char(words[w], i);
                int dom = 2 * force - words[w].length();

                // each word with a positive gain is added to the counter
                // otherwise we have to store them in a separe array
                // which is going to be sorted later
                if (dom >= 0) {
                    sum_dom += dom;
                    counter++;
                } else {
                    dominance.push_back(dom);
                    len++;
                }
            }

            // sorting the array
            sort(dominance.rbegin(), dominance.rend());

            // adding words until the sum of the gains is positive
            for (int j = 0; j < len && sem == 0; j++) {
                if (sum_dom + dominance[j] > 0) {
                    sum_dom += dominance[j];
                    counter++;
                } else {
                    sem = 1;
                }
            }

            dominance.clear();

            // update the result if the counter is greater than
            // the current result
            if (counter > result) {
                result = counter;
            }
        }

        fin.close();
        fout << result << std::endl;
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
