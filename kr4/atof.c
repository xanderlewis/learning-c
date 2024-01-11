#include <ctype.h> /* (for isdigit function) */
#include <math.h> /* (for pow function) */

/* atof: convert string s to double (also handles scientific notation of the form 123.45e-6) */
double atof(char s[]) {
	double val, power;
	int i, e, sign, esign;

	// Skip whitespace
	for (i = 0; isspace(s[i]); i++)
		;
	// Extract sign
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	// Iterate through digits, adding their values accordingly (decimal left shift)
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	// See the decimal point
	if (s[i] == '.')
		i++;
	// Iterate through digits after the point, adding values
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0'); /* note: a - '0' gives the (integer) value of a interpreted as an ASCII represented digit */
		// Record how many digits there were after the decimal point in order that we can divide later
		power *= 10.0;
	}

	// Handle 'scientific' notation
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	else
		return sign * val / power;

	// Extract exponent
	esign = (s[i++] == '-') ? -1 : 1;
	e = s[i];

	return (sign * val / power) * pow(10, esign * e);
}
