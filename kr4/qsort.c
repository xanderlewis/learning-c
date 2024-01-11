/* qsort: sort v[left]...v[right] into increasing order */
/* Pass it an array of integers and indices of the far left and right elements to be considered in the array.*/
void qsort(int v[], int left, int right) {
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right)
		// Do nothing if array contains fewer than two elements (base case)
		return;

	// Move the 'partition element' to v[0]
	swap(v, left, (left + right) / 2);
	last = left;

	// Partition
	for (i = left + 1; i <= right; i++)
		if (v[i] < v[left])
			swap(v, ++last, i);
	// Restore partition element
	swap(v, left, last);

	// Sort subarrays
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j) {
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
