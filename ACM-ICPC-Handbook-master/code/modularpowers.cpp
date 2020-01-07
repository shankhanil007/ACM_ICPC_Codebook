template<typename T> T gcd(T a, T b) { return (b ? __gcd(a,b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a,b))); }
int add(int a, int b, int c) {
	int res = a + b;
	return (res >= c ? res - c : res);
}
int mod_neg(int a, int b, int c) {
	int res; if(abs(a-b) < c) res = a - b;
	else res = (a-b) % c;
	return (res < 0 ? res + c : res);
}
int mul(int a, int b, int c) {
	long long res = (long long)a * b;
	return (res >= c ? res % c : res);
}
int power(long long a, long long n, int m) {
	int x = 1, p = a % m;
	while(n) {
		if(n & 1) x = mul(x, p, m);
		p = mul(p, p, m);
		n >>= 1;
	}
	return x;
}
template<typename T> T extended_euclid(T a, T b, T &x, T &y) {
	T xx = 0, yy = 1; y = 0; x = 1;
	while(b) {
		T q = a / b, t = b;
		b = a % b; a = t;
		t = xx; xx = x - q * xx;
		x = t; t = yy;
		yy = y - q * yy; y = t;
	}
	return a;
}
template<typename T> T mod_inverse(T a, T n) {
	T x, y, z = 0;
	T d = extended_euclid(a, n, x, y);
	return (d > 1 ? -1 : mod_neg(x, z, n));
}
