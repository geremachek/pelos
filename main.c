#include <stdio.h>

int main() {
	int c, i; /* our input variable */
	char syllable[4];

	i = 0;

	/* input loop */

	do {
		/* alwyas use lowercase */

		if (c >= 'A' && c <= 'Z') {
			c = c + ' ';
			goto alpha;
		}

		/* either add the character to the syllable array
		   or move to the next one (enforcing the syllables
		   may only be 3 characters wide) */

		if (c >= 'a' && c <= 'z' && i < 3) {
			alpha:
			syllable[i] = c;
		} else {
			syllable[i] = '\0';
			printf("%s", syllable);

			i = -1;

			if (c != '-')
				putchar(c);
		}

		++i;

	} while ((c = getchar()) != EOF); /* listen for input until EOF */

	return 0;
}