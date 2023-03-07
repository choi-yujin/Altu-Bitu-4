#include<iostream>

using namespace std;
const int MAX = 30000;

struct fountain {//���ڸ� 2�� ��ȯ�Ҽ� �ִ� ����ü�� �������
	int a;
	int b;
};

fountain fountainReduction(int a, int b) {//����ϴ� �Լ�
	for (int i = MAX; i >= 2; i--) {
		if (a % i == 0 && b % i == 0) {//�̋� a�� ����, b�� �и�
			a /= i;
			b /= i;
		}
	}
	struct fountain result;
	result.a= a;
	result.b=b;
	return result; // �տ��� ������ ����ü fountain���� ��ȯ
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
	cin >> c >> d; //���� �Է� �ޱ�

	struct fountain sum = fountainPlus(a, b, c, d);
	struct fountain result = fountainReduction(sum.a, sum.b);
	cout << result.a << " " << result.b;

}