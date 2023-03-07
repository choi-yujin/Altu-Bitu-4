#include<iostream>

using namespace std;
const int MAX = 30000;

struct fountain {//숫자를 2개 반환할수 있는 구조체를 만들어줌
	int a;
	int b;
};

fountain fountainReduction(int a, int b) {//약분하는 함수
	for (int i = MAX; i >= 2; i--) {
		if (a % i == 0 && b % i == 0) {//이떄 a는 분자, b는 분모
			a /= i;
			b /= i;
		}
	}
	struct fountain result;
	result.a= a;
	result.b=b;
	return result; // 앞에서 만들어둔 구조체 fountain으로 반환
}

fountain fountainPlus(int a, int b, int c, int d) {// a/b + c/d
	a *= d;
	c *= b;
	//m = a + c; n = b * d;
	a = a + c; 
	b = b * d;
	struct fountain sum;
	sum.a = a;
	sum.b = b;
	return sum;
}

int main() {
	int a, b, c, d;

	cin >> a >> b;
	cin >> c >> d; //숫자 입력 받기

	struct fountain sum = fountainPlus(a, b, c, d);
	struct fountain result = fountainReduction(sum.a, sum.b);
	cout << result.a << " " << result.b;

}