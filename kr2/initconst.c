// 'If the variable in question is not automatic, the initialisation is done one only, conceptually before the program starts executing, and the initialiser must be a constant expression.

// define some things globally (this stuff is computed at compile time)
int d = 5;
int e = 7;
char f = 'm';

e = 2 * d; // what happens here? 'error: redefinition of e'. 

int g = 2 * d; // here? 'error: intializer is not a compile-time constant'.
	   /* kind of odd, since 2 * d IS constant and could seemingly be evaluated at compile-time..
	      but I guess it wants an ACTUAL syntactic constant. */
int h = 3 + 4; // fine? yep.

int i = 2 + d; // ? again, not a compile-time constant.
int j = d + e; // ? this works. I guess we just can't mix int literals with defined (even constant) ints.

int k; // since there's non initialiser, this should be initialised to zero (since it's external).


int main() {
	// I guess technically because we're within a function (even if it's main) the below are automatic?
	// Certainly this stuff is evaluated at runtime.
	int a = 3; // fine
	int b = 4; // fine
	int c;
	c = a + b; // all fine

	int d = a + b; // does it work? it compiles -- yes.
	
	int l; // no initialiser, but this is not external. so it'll just contain some garbage value.

	return 0;
}
