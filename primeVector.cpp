// for getting all the prime numbers in the range [n, m],  n <= m;

vector<int> getPrimes(int n, int m) {
    vector<bool> prime(m + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= m; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= m; j += i)
                prime[j] = false;
        }
    }

    vector<int> ans;
    for (int i = max(2, n); i <= m; i++) {
        if (prime[i])
            ans.push_back(i);
    }

    return ans;
}