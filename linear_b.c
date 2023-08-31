	/* convert from latin text to Linear B */

#include <string.h>
#include "linear_b.h"

/* our dictionary of sign pairs */

static SignPair signList[] = {
	{ "a",   LB_A },
	{ "ai",  LB_AI },
	{ "au",  LB_AU },
	{ "da",  LB_DA },
	{ "de",  LB_DE },
	{ "di",  LB_DI },
	{ "do",  LB_DO },
	{ "du",  LB_DU },
	{ "dwe", LB_DWE },
	{ "dwo", LB_DWO },
	{ "e",   LB_E },
	{ "ha",  LB_HA },
	{ "i",   LB_I },
	{ "ja",  LB_JA },
	{ "je",  LB_JE },
	{ "jo",  LB_JO },
	{ "ka",  LB_KA },
	{ "ke",  LB_KE },
	{ "ki",  LB_KI },
	{ "ko",  LB_KO },
	{ "ku",  LB_KU },
	{ "ma",  LB_MA },
	{ "me",  LB_ME },
	{ "mi",  LB_MI },
	{ "mo",  LB_MO },
	{ "mu",  LB_MU },
	{ "na",  LB_NA },
	{ "ne",  LB_NE },
	{ "ni",  LB_NI },
	{ "no",  LB_NO },
	{ "nu",  LB_NU },
	{ "nwa", LB_NWA },
	{ "o",   LB_O },
	{ "pa",  LB_PA },
	{ "pe",  LB_PE },
	{ "phu", LB_PHU },
	{ "pi",  LB_PI },
	{ "po",  LB_PO },
	{ "pte", LB_PTE },
	{ "pu",  LB_PU },
	{ "qa",  LB_QA },
	{ "qe",  LB_QE },
	{ "qi",  LB_QI },
	{ "qo",  LB_QO },
	{ "rai", LB_RAI },
	{ "ra",  LB_RA },
	{ "re",  LB_RE },
	{ "ri",  LB_RI },
	{ "ro",  LB_RO },
	{ "ru",  LB_RU },
	{ "rya", LB_RYA },
	{ "ryo", LB_RYO },
	{ "sa",  LB_SA },
	{ "se",  LB_SE },
	{ "si",  LB_SI },
	{ "so",  LB_SO },
	{ "su",  LB_SU },
	{ "ta",  LB_TA },
	{ "te",  LB_TE },
	{ "ti",  LB_TI },
	{ "to",  LB_TO },
	{ "tu",  LB_TU },
	{ "twe", LB_TWE },
	{ "two", LB_TWO },
	{ "tya", LB_TYA },
	{ "u",   LB_U },
	{ "wa",  LB_WA },
	{ "we",  LB_WE },
	{ "wi",  LB_WI },
	{ "wo",  LB_WO },
	{ "za",  LB_ZA },
	{ "ze",  LB_ZE },
	{ "zo",  LB_ZO },
};

/* convert from latin to Linear B */

char* lb_convert(char latin[SYLLABLE_SIZE]) {
	int low, mid, high, cmp;

	low = 0;

	/* calculate the size of the sign list */

	high = (sizeof(signList) / sizeof(SignPair)) - 1;

	/* do a binary search within the table */

	while (low <= high) {
		mid = (low + high)/2;
		cmp = strcmp(latin, signList[mid].syllable);

		if (!cmp)
			return signList[mid].sign;
		else if (cmp > 0)
			low = mid + 1;
		else
			high = mid -1;
	}

	/* if we never find a match, return the original text */

	return latin;
}