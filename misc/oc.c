/* K&R talks about the 'largest negative number' to mean what I would call the *smallest* negative number.
 * Let's check whether in C these  numbers really are considered large... */

int main() {
	return (-5 < -3); // 1?
}
