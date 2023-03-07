#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;

vector<char> rouletteMaker(int n, int k) {
	vector<char>roulette(n, '?');
	return roulette;
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<char>roulette = rouletteMaker(n, k);
	int num;
	char alphabet;
	int here = 0;//화살표가 가리키고 있는 곳
	for (int i = 1; i <= k; i++) {
		cin >> num >> alphabet;
		int next = num + here;
		if (next > n - 1) {
			next %= n;
		}
		if (roulette[next] != '?') {
			roulette[next] = 'N';
		}
		roulette[next] = alphabet;
		here = next;
	}
	
	reverse(roulette.begin(), roulette.end());//룰렛이 돌아가는 방향과 읽는 방향은 반대
	rotate(roulette.begin(), roulette.begin() + here, roulette.end());
	//마지막 숫자(here)이 vector의 젤 처음에 오도록 변경

	for (int i = 0; i < n; i++) {
		if (roulette[i] == 'N') {
			roulette[0] = 'N';
		}

		for (int i = 0; i < n; i++) {
			if (roulette[0] == 'n') {
				cout << "!";
				return 0;
			}
			cout << roulette[i];
		}
		return 0;
	}
}