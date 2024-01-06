/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n) {
	int gap, i, j, temp;

	// Gap starts off as half the length of v and gets repeatedly halved, eventually reaching zero.
	// Ultimately, as long as gap eventually reaches 1 the array is guarunteed to become sorted
	// (and we could use any sequence of gaps), but we choose to use a geometric progession here.
	for (gap = n/2; gap > 0; gap /= 2)
		// Step along elements
		for (i = gap; i < n; i++)
			// Compare each pair separated by gap; reverse any that are out of order
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
				// Swap the j'th and (j + gap)th elements, if they are out of order
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
}

/* ESSENTIALLY: shellsort partitions the array into some number of subarrays according to the gap, sorts these arrays separately (using insertion sort)
   and continues, iterating through smaller and smaller gaps (and therefore smaller and smaller numbers of larger and larger subarrays) until eventually
   gap = 1 and it performs an insertion sort of the entire array (which will tend to not have to perform many comparisons because out-of-position elements
   have been moved close to where they should be). */
