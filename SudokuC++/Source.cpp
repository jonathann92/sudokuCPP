#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>
#include "Employee.h"

using namespace std;

void test(Emp *&x) {
	Emp *b=  new Emp(4, 5);
	cout << b->a;
	x = b;
	cout << x->a;

}

int main(int argc, char* args[]) {
	int end;

	Emp *a = new Emp(1, 2);
	test(a);
	cout << a->a;




	stack < std::pair <string, int> > x;



	cin >> end;
	return 0;
}