#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>

using namespace std;

struct Emp {
	int x, y, z;
	Emp(int a, int b, int c) {
		x = a; y = b; z = c;
	}
	Emp(const Emp &e) {
		*this = e;
	}
};


int main(int argc, char* args[]) {
	int end;

	Emp a = Emp(1, 2, 3);
	cout << a.x;

	stack < std::pair <string, int> > x;



	cin >> end;
	return 0;
}