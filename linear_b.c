/* convert from latin text to Linear B */

#include <string.h>
#include "linear_b.h"

/* our dictionary of sign pairs */

static SignPair signList[] = {
	{ "a",   LB_A },
	{ "e",   LB_E },
	{ "i",   LB_I },
	{ "o",   LB_O },
	{ "u",   LB_U },

	{ "da",  LB_DA },
	{ "de",  LB_DE },
	{ "di",  LB_DI },
	{ "do",  LB_DO },
	{ "du",  LB_DU },

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

	{ "pa",  LB_PA },
	{ "pe",  LB_PE },
	{ "pi",  LB_PI },
	{ "po",  LB_PO },
	{ "pu",  LB_PU },

	{ "qa",  LB_QA },
	{ "qe",  LB_QE },
	{ "qi",  LB_QI },
	{ "qo",  LB_QO },

	{ "ra",  LB_RA },
	{ "re",  LB_RE },
	{ "ri",  LB_RI },
	{ "ro",  LB_RO },
	{ "ru",  LB_RU },

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

	{ "wa",  LB_WA },
	{ "we",  LB_WE },
	{ "wi",  LB_WI },
	{ "wo",  LB_WO },

	{ "za",  LB_ZA },
	{ "ze",  LB_ZE },
	{ "zo",  LB_ZO },

	{ "ha",  LB_HA },
	{ "ai",  LB_AI },
	{ "au",  LB_AU },

	{ "dwe", LB_DWE },
	{ "dwo", LB_DWO },

	{ "nwa", LB_NWA },

	{ "pte", LB_PTE },
	{ "phu", LB_PHU },

	{ "rya", LB_RYA },
	{ "rai", LB_RAI },
	{ "ryo", LB_RYO },

	{ "tya", LB_TYA },
	{ "twe", LB_TWE },
	{ "two", LB_TWO },
};

/* convert from latin to Linear B */

char* lb_convert(char latin[SYLLABLE_SIZE]) {
	int i, signs;

	/* calculate the size of the sign list */

	signs = (sizeof(signList) / sizeof(SignPair));

	for (i = 0; i <= signs; i++) {
		/* if our input and syllable are the same, return the associated sign */

		if (!strcmp(signList[i].syllable, latin)) {
			return signList[i].sign;
		}
	}

	/* if we never find a match, return the original text */

	return latin;
}