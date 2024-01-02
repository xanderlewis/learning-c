// adding together two hex ints ...?

int main() {
	int a, b;
	
	a = 0xba; // decimal 176 + 10 = 186
	b = 0x0003; // decimal 3

	return a + b; // hopefully 186 + 3 = 189
}

// SUCCESS! when we compile and run this and then check the shell variable $?, we get 189. It worked!
