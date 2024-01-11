void swap_not(int x, int y) { /* WRONG */
	int temp;

	temp = x;
	x = y;
	y = temp;
}

/* this time, we pass in *pointers* to the two ints */
void swap(int *px, int *py) {
	int temp;

	// We derefence the pointer px to access the thing it points to (x)
	temp = *px;
	// ..and we dereference x on the other size of the equality, too, to set the value of x to that pointed to by py
	*px = *py;
	*py = temp;
}

int main() {
	int x = 3, y = 4;

	/*swap(x, y); -- NO! */

	// We pass the *addresses* of x and y to the swap function
	swap(&x, &y);
	return 0;
}

