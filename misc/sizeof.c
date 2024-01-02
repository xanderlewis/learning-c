// I seem to recall there's a sizeof keyword (probably a function?) that can give the size (maybe in bytes?) of some variable of piece of data.
// Let's try.
// Next day: OK, it turns out sizeof is *not* actually a function; it's part of the language. In fact, it's substituted for the size of the requested
// thing during compilation. So the compiled program is not even doing any size calculation!
// Hence, we need not enclose the argument in brackets.

int main() {
	int a;
	return sizeof a; // We got a return value of 4. So 4 bytes I guess.
}
