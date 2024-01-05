/* Just a nice one-liner for correctly using plurals. (no '(s)' ugliness!). */
// (using the ternary conditional operator)

printf("You have %d item%s.\n", n, n == 1 ? "" : "s");
// (if n is 1 we append the empty string, otherwise we stick on an 's'.)
// The expression p ? a : b evaluates to a if p is true (nonzero) and b if it is false (zero).
