struct Emp {
	static int x;
	int a;
	int b;

	Emp(int k, int y) {
		a = k;
		b = y;
	}

	static int getX() {
		return x;
	}
};

int Emp::x = 0;