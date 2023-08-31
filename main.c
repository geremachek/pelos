/*
	* pelos - convert Latin text into Linear B
	* licensed under GPL-3.0
*/

#include <stdio.h>
#include "linear_b.h"

int main() {
	int c, i, alpha; /* our input variable */
	char syllable[SYLLABLE_SIZE];

	i, alpha = 0, 0;

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
			printf("%s", lb_convert(syllable));

			i = 0;

			if (c != '-')
				putchar(c);
		}

	} while (c != EOF); /* listen for input until EOF */

	return 0;
}