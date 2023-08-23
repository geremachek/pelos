/*
	* pelos - convert Latin text into Linear B
	* licensed under GPL-3.0
*/

#include <stdio.h>
#include "linear_b.h"

int main() {
	int c, i; /* our input variable */
	char syllable[SYLLABLE_SIZE];

	i = 0;

	/* input loop */

	do {
		/* alwyas use lowercase */

		if (c >= 'A' && c <= 'Z') {
			c += ' ';
			goto alpha;
		}

		/* either add the character to the syllable array
		   or move to the next one (enforcing that the syllables
		   may only be 3 characters wide) */

		if (c >= 'a' && c <= 'z' && i < SYLLABLE_SIZE-1) {
			alpha:
			syllable[i] = c;
		} else {
			syllable[i] = '\0';
			printf("%s", lb_convert(syllable));

			i = -1;

			if (c != '-')
				putchar(c);
		}

		++i;

	} while ((c = getchar()) != EOF); /* listen for input until EOF */

	return 0;
}