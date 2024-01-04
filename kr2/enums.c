// Enumeration constants

enum boolean { NO, YES };
// The first name has value 0, the next 1, and so on.

// But we can also specify explicit values:
enum escapes { BELL = '\a\', TAB = '\t', NEWLINE = '\n', RETURN = '\r' };

enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
		/* FEB is 2, MAR is 3, etc. */

// Enumerations provide a convenient way to associate constant values with names, an alternative to #define with the advantage that the values can be generated for you.
