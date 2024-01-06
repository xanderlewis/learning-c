/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
// (that is, we're assuming v is already ordered)
// Returns the index of x in v, or -1 if x isn't present.

int binsearch(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		// Let mid be the mean of low and high
		mid = (low + high) / 2
			if (x < v[mid])
				// If x is in the lower half, set upper bound appropriately
				high = mid - 1
			else if (x > v[mid])
				// If x is in the upper half, ...
				low = mid + 1
			else
				// If x is in fact *equal* to mid, return it.
				return mid;
	}
	// Eventually, if x doesn't appear in v we'll end up with low and high converging to the same value
	// ...at which point we'll get high < low in the next step.
	return -1; /* no match */
}
