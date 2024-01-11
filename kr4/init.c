/* §4.9 Initialisation */

// We can initialise an array by following its declaration with a list of initialisers enclosed in curly brackets and separateed by commas. e.g.:

int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Character arrays are a special case of initialisation; a string may be used instead of the curly brackets and commas notation:

char pattern[] = "ould";

// is a shorthand for the longer but equivalent

char pattern[] = { 'o', 'u', 'l', 'd', '\0' };

// (in this case, the array size is five (four characters plus the terminating '\0').
