// As an example, define a macro called max:
#define max(A, B) ((A) > (B) ? (A) : (B))

/* Although it looks like a function call, a use of max here expands into in-line code.
 * Each occurrence of a formal parameter (here A or B) will be replaced by the corresponding actual argument. */

// Thus the line
x = max(p + q, r + s);

// will be replaced by the lin
x = ((p + q) > (r + s) ? (p + q) : (r + s));

/* So long as the arguments are treated consistently, this macro will serve for any data type; there is no need for
 * different kinds of max for different data types, as there would be with functions. */

// Bad things can happen if we put increment or decrement operators into max...

// getchar and putchar in <stdio.h> are apparently usually implemented as macros to avoid having a function call for every character processed...

// a nice debugging print macro:
#define dprint(expr) printf(#expr " = %g\n", expr) // (#expr gets expanded into a string constant)

// when invoked as dprint(x / y);
// this macro is expanded into
printf("x / y = %g\n", x / y);

#define paste(front, back) front ## back

// paste(name, 1) creates the token name1
