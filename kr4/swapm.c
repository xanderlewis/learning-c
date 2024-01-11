// A macro that interchanges two arguments of type t.
#define swap(t,x,y) t temp = x; x = y; y = temp

// test it?
int main() {
	int a, b;
	a = 3; b = 4;
	swap(int,a,b);
	return a; // (should be 4)
}
