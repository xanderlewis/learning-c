// Messing around with different 'C-style' escape characters.

#include <stdio.h>

int main() {
	// printf("\a \b \c \d \e \f \g \h \i \j \k \l \m \n \o \p \q \r \s \t \u \v \w \x \y \z");
	printf("\x2a\x40\n");
	return 0;
}
