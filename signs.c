/* convert from latin text to Linear B */

#include <string.h>
#include <stdio.h>
#include "signs.h"

/* our dictionary of Linear B sign pairs */

#define LB_BLOCK "\xf0\x90\x80"
#define LB_BLOCK_SPEC "\xf0\x90\x81"

static const SignPair lb_signs[LB_TOTAL_SIGNS] = {
	{ "a",   LB_BLOCK"\x80" },
	{ "ai",  LB_BLOCK_SPEC"\x81" },
	{ "au",  LB_BLOCK_SPEC"\x82" },
	{ "da",  LB_BLOCK"\x85" },
	{ "de",  LB_BLOCK"\x86" },
	{ "di",  LB_BLOCK"\x87" },
	{ "do",  LB_BLOCK"\x88" },
	{ "du",  LB_BLOCK"\x89" },
	{ "dwe", LB_BLOCK_SPEC"\x83" },
	{ "dwo", LB_BLOCK_SPEC"\x84" },
	{ "e",   LB_BLOCK"\x81" },
	{ "ha",  LB_BLOCK_SPEC"\x80" },
	{ "i",   LB_BLOCK"\x82" },
	{ "ja",  LB_BLOCK"\x8a" },
	{ "je",  LB_BLOCK"\x8b" },
	{ "jo",  LB_BLOCK"\x8d" },
	{ "ka",  LB_BLOCK"\x8f" },
	{ "ke",  LB_BLOCK"\x90" },
	{ "ki",  LB_BLOCK"\x91" },
	{ "ko",  LB_BLOCK"\x92" },
	{ "ku",  LB_BLOCK"\x93" },
	{ "ma",  LB_BLOCK"\x94" },
	{ "me",  LB_BLOCK"\x95" },
	{ "mi",  LB_BLOCK"\x96" },
	{ "mo",  LB_BLOCK"\x97" },
	{ "mu",  LB_BLOCK"\x98" },
	{ "na",  LB_BLOCK"\x99" },
	{ "ne",  LB_BLOCK"\x9a" },
	{ "ni",  LB_BLOCK"\x9b" },
	{ "no",  LB_BLOCK"\x9c" },
	{ "nu",  LB_BLOCK"\x9d" },
	{ "nwa", LB_BLOCK_SPEC"\x85" },
	{ "o",   LB_BLOCK"\x83" },
	{ "pa",  LB_BLOCK"\x9e" },
	{ "pe",  LB_BLOCK"\x9f" },
	{ "phu", LB_BLOCK_SPEC"\x87" },
	{ "pi",  LB_BLOCK"\xa0" },
	{ "po",  LB_BLOCK"\xa1" },
	{ "pte", LB_BLOCK_SPEC"\x86" },
	{ "pu",  LB_BLOCK"\xa2" },
	{ "qa",  LB_BLOCK"\xa3" },
	{ "qe",  LB_BLOCK"\xa4" },
	{ "qi",  LB_BLOCK"\xa5" },
	{ "qo",  LB_BLOCK"\xa6" },
	{ "ra",  LB_BLOCK"\xa8" },
	{ "rai", LB_BLOCK_SPEC"\x89" },
	{ "re",  LB_BLOCK"\xa9" },
	{ "ri",  LB_BLOCK"\xaa" },
	{ "ro",  LB_BLOCK"\xab" },
	{ "ru",  LB_BLOCK"\xac" },
	{ "rya", LB_BLOCK_SPEC"\x88" },
	{ "ryo", LB_BLOCK_SPEC"\x8a" },
	{ "sa",  LB_BLOCK"\xad" },
	{ "se",  LB_BLOCK"\xae" },
	{ "si",  LB_BLOCK"\xaf" },
	{ "so",  LB_BLOCK"\xb0" },
	{ "su",  LB_BLOCK"\xb1" },
	{ "ta",  LB_BLOCK"\xb2" },
	{ "te",  LB_BLOCK"\xb3" },
	{ "ti",  LB_BLOCK"\xb4" },
	{ "to",  LB_BLOCK"\xb5" },
	{ "tu",  LB_BLOCK"\xb6" },
	{ "twe", LB_BLOCK_SPEC"\x8c" },
	{ "two", LB_BLOCK_SPEC"\x8d" },
	{ "tya", LB_BLOCK_SPEC"\x8b" },
	{ "u",   LB_BLOCK"\x84" },
	{ "wa",  LB_BLOCK"\xb7" },
	{ "we",  LB_BLOCK"\xb8" },
	{ "wi",  LB_BLOCK"\xb9" },
	{ "wo",  LB_BLOCK"\xba" },
	{ "za",  LB_BLOCK"\xbc" },
	{ "ze",  LB_BLOCK"\xbd" },
	{ "zo",  LB_BLOCK"\xbf" },
};

/* our dictionary of Cypriot syllabary sign pairs */

#define CY_BLOCK "\xf0\x90\xa0"

static const SignPair cy_signs[CY_TOTAL_SIGNS] = {
	{ "a",  CY_BLOCK"\x80" },
	{ "e",  CY_BLOCK"\x81" },
	{ "i",  CY_BLOCK"\x82" },
	{ "ja", CY_BLOCK"\x85" },
	{ "jo", CY_BLOCK"\x88" },
	{ "ka", CY_BLOCK"\x8a" },
	{ "ke", CY_BLOCK"\x8b" },
	{ "ki", CY_BLOCK"\x8c" },
	{ "ko", CY_BLOCK"\x8d" },
	{ "ku", CY_BLOCK"\x8e" },
	{ "la", CY_BLOCK"\x8f" },
	{ "le", CY_BLOCK"\x90" },
	{ "li", CY_BLOCK"\x91" },
	{ "lo", CY_BLOCK"\x92" },
	{ "lu", CY_BLOCK"\x93" },
	{ "ma", CY_BLOCK"\x94" },
	{ "me", CY_BLOCK"\x95" },
	{ "mi", CY_BLOCK"\x96" },
	{ "mo", CY_BLOCK"\x97" },
	{ "mu", CY_BLOCK"\x98" },
	{ "na", CY_BLOCK"\x99" },
	{ "ne", CY_BLOCK"\x9a" },
	{ "ni", CY_BLOCK"\x9b" },
	{ "no", CY_BLOCK"\x9c" },
	{ "nu", CY_BLOCK"\x9d" },
	{ "o",  CY_BLOCK"\x83" },
	{ "pa", CY_BLOCK"\x9e" },
	{ "pe", CY_BLOCK"\xaf" },
	{ "pi", CY_BLOCK"\xa0" },
	{ "po", CY_BLOCK"\xa1" },
	{ "pu", CY_BLOCK"\xa2" },
	{ "ra", CY_BLOCK"\xa3" },
	{ "re", CY_BLOCK"\xa4" },
	{ "ri", CY_BLOCK"\xa5" },
	{ "ro", CY_BLOCK"\xa6" },
	{ "ru", CY_BLOCK"\xa7" },
	{ "sa", CY_BLOCK"\xa8" },
	{ "se", CY_BLOCK"\xa9" },
	{ "si", CY_BLOCK"\xaa" },
	{ "so", CY_BLOCK"\xab" },
	{ "su", CY_BLOCK"\xac" },
	{ "ta", CY_BLOCK"\xad" },
	{ "te", CY_BLOCK"\xae" },
	{ "ti", CY_BLOCK"\xaf" },
	{ "to", CY_BLOCK"\xb0" },
	{ "tu", CY_BLOCK"\xb1" },
	{ "u",  CY_BLOCK"\x84" },
	{ "wa", CY_BLOCK"\xb2" },
	{ "we", CY_BLOCK"\xb3" },
	{ "wi", CY_BLOCK"\xb4" },
	{ "wo", CY_BLOCK"\xb5" },
	{ "xa", CY_BLOCK"\xb7" },
	{ "xe", CY_BLOCK"\xb8" },
	{ "za", CY_BLOCK"\xbc" },
	{ "zo", CY_BLOCK"\xbf" },
};

/* convert from latin to Aegean script */

const char* sign_convert(char latin[SYLLABLE_SIZE], const SignPair signs[], size_t total) {
	int low, mid, high, cmp;

	low = 0;
	high = total;

	/* do a binary search within the table */

	while (low <= high) {
		mid = (low + high)/2;
		cmp = strcmp(latin, signs[mid].syllable);

		if (!cmp)
			return signs[mid].sign;
		else if (cmp > 0)
			low = mid + 1;
		else
			high = mid -1;
	}

	/* if we never find a match, return the original text */

	return latin;
}

const char* lb_convert(char latin[SYLLABLE_SIZE]) {
	return sign_convert(latin, lb_signs, LB_TOTAL_SIGNS);
}

const char* cy_convert(char latin[SYLLABLE_SIZE]) {
	return sign_convert(latin, cy_signs, CY_TOTAL_SIGNS);
}
