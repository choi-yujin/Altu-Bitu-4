#include<iostream>
#include<vector>
#include<queue>

using namespace std;
const int MAX = 100000;

vector<int>isPrime() {
	vector<int>primes(MAX + 1, 0);
	for (int i = 2; i * i <= MAX; i++) {
		if (primes[i] != 0) {
			continue;
		}
		for (int j = i * i; j <= MAX; j += i) {
			if (primes[j] == 0) {
				primes[j] = i;
			}
		}
	}
	return primes;
}

void Gold(int n, vector<int>& primes) {
	for (int i = 3; i < primes.size(); i += 2) {
		if (primes[i] == 0 && primes[n - i] == 0) {
			cout << n << " = " << i << " + " << n - i << '\n';
			return;
		}
	}
	cout << "Goldbach's conjecture is wrong." << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int>primes(MAX+1);
	primes = isPrime();
	
	queue <int> test;
	while (1) {
		int n;
		cin >> n;
		test.push(n);
		if (n == 0) {
			break;
		}
	}
	while (!test.empty()) {
		if (test.front() == 0) {
			return 0;
		}
		Gold(test.front(), primes);
		test.pop();
	}
}