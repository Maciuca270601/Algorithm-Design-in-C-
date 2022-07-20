#include <bits/stdc++.h>
#include <vector>

#define BIGNUMBER 1000000007

class Task {
 public:
    void solve() {
        read_input();
    }

 private:
    std::string crypto_text;
    std::string cipher_text;
    int n;
    int s;

    // contains the number of occurrences of each substring in the cipher_text
    std::vector<long long int> freq;
    // a backup for the freq vector
    std::vector<long long int> freq_aux;

    void read_input() {
        std::ifstream fin("crypto.in");
        std::ofstream fout("crypto.out");

        fin >> n >> s;
        fin >> crypto_text >> cipher_text;

        // calculate the numbers of distinctive appearances
        // of each letter in a substring
        std::vector<int> fr;
        for (int i = 0; i < 26; i++) {
            fr.push_back(0);
        }

        for (int i = 0; i < s; i++) {
            fr[cipher_text[i] - 'a']++;
        }

        int multiplier = 0;
        for (int i = 0; i < 26; i++) {
            if (fr[i] > 0) {
                multiplier++;
            }
        }

        // initialize freq vector and aux_freq vector
        freq.push_back(1);
        freq_aux.push_back(1);
        for (int i  = 0; i < s; i++) {
            freq.push_back(0);
            freq_aux.push_back(0);
        }

        // get every letter from crypto_text
        for (int i = 0; i < n; i++) {
            // if the letter is '?'
            if (crypto_text[i] == '?') {
                // double the counter for null
                // and for the rest apply v[i] = 2 * v[i] + aux[i-1]
                for (int i = 1; i <= s; i++) {
                    freq[i] = (multiplier * freq[i] + freq_aux[i - 1])
                    % BIGNUMBER;
                }
                freq[0] = (multiplier * freq[0]) % BIGNUMBER;

                // update freq_aux vector
                for (int i = 0; i <= s; i++) {
                    freq_aux[i] = freq[i];
                }
            } else {
                // search for every appearance of the letter in the substring
                // update the freq vector
                for (int j = 0; j < s; j++) {
                    if (cipher_text[j] == crypto_text[i]) {
                        // j is the index that we are looking for
                        // apply v[j] = v[j] + aux[j-1];
                        freq[j + 1] = (freq[j + 1] + freq_aux[j]) % BIGNUMBER;
                    }
                }

                // update freq_aux vector
                for (int i = 0; i < s; i++) {
                    freq_aux[i] = freq[i];
                }
            }
        }

        fout << freq[s] << std::endl;
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
