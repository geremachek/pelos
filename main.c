/*
	* pelos - convert Latin text into the Aegean scripts.
	* licensed under GPL-3.0
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "signs.h"

void input_loop(char* (*parser)(char[SYLLABLE_SIZE]));
int return_error(char* message, char* name);

int main(int argc, char* argv[]) {
	char* bname = argv[0]; /* the name of the binary */

	if (argc > 1) {
		char* opt = argv[1];

		if (!strcmp(opt, "-h")) { /* print help information */
			printf("Usage: %s [-hlc]\n", bname);

			printf("\t-h\tDisplay this help information\n");
			printf("\t-l\tParse Linear B transliterations\n");
			printf("\t-c\tParse Cypriot Syllabary transliterations\n");
		} else if (!strcmp(opt, "-l")) /* parse Linear B or Cypriot script */
			input_loop(lb_convert);
		else if (!strcmp(opt, "-c"))
			input_loop(cy_convert);
		else
			return return_error("invalid argument", bname);
	} else
		return return_error("please supply an option", bname);

	return 0;
}

/* parse stdin */

void input_loop(char* (*parser)(char[SYLLABLE_SIZE])) {
	int c, i, alpha; /* our input variable */
	char syllable[SYLLABLE_SIZE];

	i = 0;

	/* input loop */

	do {
		c = getchar();

		/* always use lowercase */

		if (c >= 'A' && c <= 'Z') {
			c += ' ';
			alpha = 1; /* our character is alphabetic */
		} else
			alpha = (c >= 'a' && c <= 'z'); /* it still might be... let's check! */

		/* either add the character to the syllable array
		   or move to the next one (enforcing that the syllables
		   may only be 3 characters wide) */

		if (alpha && i < SYLLABLE_SIZE-1) {
			syllable[i] = c;
			++i;
		} else {
			syllable[i] = '\0';
			printf("%s", (*parser)(syllable));

			i = 0;

			if (c != '-')
				putchar(c);
		}

	} while (c != EOF); /* listen for input until EOF */
}

/* display an error message and return 1 */

int return_error(char* message, char* name) {
	fprintf(stderr, "%s: %s\n", name, message);
	return 1;
}