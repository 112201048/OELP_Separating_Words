#include <bits/stdc++.h>
#define TRIALS 500
using namespace std;

int get_prime(int n, int m){
    int p = m + 1;
    while (true) {
        bool isPrime = true;
        for (int i = 2; i * i <= p; i++) {
            if (p % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) return p;
        p++;
    }
}

pair<int, int> generateHashParameters(int p) {
    int a = 1 + rand() % (p - 1); // a should be in range [1, p-1]
    int b = rand() % p; // b should be in range [0, p-1]
    return {a, b};
}

double check(int n, int m, int trials){
    vector<int> S, T;
    for (int i = 1; i <= n; i++){
        if (i == n/2){
            S.push_back(i);
            T.push_back(i+1);
            break;
        }
        else{
            S.push_back(i);
            T.push_back(i);
        }
    }
    int success_trials = 0;
    for (int i = 0; i < trials; i++){
        unordered_map<int, int> CS, CT;//Keeps the count of how many elements in S and T got mapped to a certain position
        int p = get_prime(n, m);
        pair<int, int> ab = generateHashParameters(p);
        int a = ab.first;
        int b = ab.second;
        for(int x : S){
            CS[((a * x + b) % p) % m]++;
        }
        for(int x : T){
            CT[((a * x + b) % p) % m]++;
        }
        bool mis = false;
        for(int j = 0; j < m; j++){
            if (CS[j] != CT[j]){
                mis = true;
                break;
            }
        }
        if (mis){
            success_trials++;
        }
    }
    // cout << "Probability that there exists an i such that |Si| != |Ti| : ";
    // cout << fixed << setprecision(6) << (double)success_trials / trials << endl;
    return (double)success_trials / trials;

}

int main(){
    srand(time(0)); // Seed randomness
    // int n = 10; // Length of x and y
    int trials = 2000; // Number of trials
    // for(int n = 2; n < TRIALS; n++)
    // {
    //     int m = sqrt(n);
    //     cout << n << ", " << check(n, m, trials) << endl;
    // }
    ofstream fout("data.txt");
    for(int n = 2; n < TRIALS; n++) {
        int m = sqrt(n);
        fout << n << " " << check(n, m, trials) << endl;
    }
    fout.close();
    return 0;
}