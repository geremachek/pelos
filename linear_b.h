/* standard definitions of Linear B syllabic signs */

/* sign pair type */

#define SYLLABLE_SIZE 4
#define SIGN_SIZE     5

typedef struct {
	char syllable[SYLLABLE_SIZE];
	char sign[SIGN_SIZE];
} SignPair;

/* our conversion function */

char* lb_convert(char latin[SYLLABLE_SIZE]);

/* first block of syllabic values */

#define LB_BLOCK "\xf0\x90\x80"

#define LB_A  LB_BLOCK"\x80"
#define LB_E  LB_BLOCK"\x81"
#define LB_I  LB_BLOCK"\x82"
#define LB_O  LB_BLOCK"\x83"
#define LB_U  LB_BLOCK"\x84"

#define LB_DA LB_BLOCK"\x85"
#define LB_DE LB_BLOCK"\x86"
#define LB_DI LB_BLOCK"\x87"
#define LB_DO LB_BLOCK"\x88"
#define LB_DU LB_BLOCK"\x89"

#define LB_JA LB_BLOCK"\x8a"
#define LB_JE LB_BLOCK"\x8b"
#define LB_JO LB_BLOCK"\x8d"

#define LB_KA LB_BLOCK"\x8f"
#define LB_KE LB_BLOCK"\x90"
#define LB_KI LB_BLOCK"\x91"
#define LB_KO LB_BLOCK"\x92"
#define LB_KU LB_BLOCK"\x93"

#define LB_MA LB_BLOCK"\x94"
#define LB_ME LB_BLOCK"\x95"
#define LB_MI LB_BLOCK"\x96"
#define LB_MO LB_BLOCK"\x97"
#define LB_MU LB_BLOCK"\x98"

#define LB_NA LB_BLOCK"\x99"
#define LB_NE LB_BLOCK"\x9a"
#define LB_NI LB_BLOCK"\x9b"
#define LB_NO LB_BLOCK"\x9c"
#define LB_NU LB_BLOCK"\x9d"

#define LB_PA LB_BLOCK"\x9e"
#define LB_PE LB_BLOCK"\x9f"
#define LB_PI LB_BLOCK"\xa0"
#define LB_PO LB_BLOCK"\xa1"
#define LB_PU LB_BLOCK"\xa2"

#define LB_QA LB_BLOCK"\xa3"
#define LB_QE LB_BLOCK"\xa4"
#define LB_QI LB_BLOCK"\xa5"
#define LB_QO LB_BLOCK"\xa6"

#define LB_RA LB_BLOCK"\xa8"
#define LB_RE LB_BLOCK"\xa9"
#define LB_RI LB_BLOCK"\xaa"
#define LB_RO LB_BLOCK"\xab"
#define LB_RU LB_BLOCK"\xac"

#define LB_SA LB_BLOCK"\xad"
#define LB_SE LB_BLOCK"\xae"
#define LB_SI LB_BLOCK"\xaf"
#define LB_SO LB_BLOCK"\xb0"
#define LB_SU LB_BLOCK"\xb1"

#define LB_TA LB_BLOCK"\xb2"
#define LB_TE LB_BLOCK"\xb3"
#define LB_TI LB_BLOCK"\xb4"
#define LB_TO LB_BLOCK"\xb5"
#define LB_TU LB_BLOCK"\xb6"

#define LB_WA LB_BLOCK"\xb7"
#define LB_WE LB_BLOCK"\xb8"
#define LB_WI LB_BLOCK"\xb9"
#define LB_WO LB_BLOCK"\xba"

#define LB_ZA LB_BLOCK"\xbc"
#define LB_ZE LB_BLOCK"\xbd"
#define LB_ZO LB_BLOCK"\xbf"

/* second block: "Special values" */

#define LB_BLOCK_SPEC "\xf0\x90\x81"

#define LB_HA  LB_BLOCK_SPEC"\x80"
#define LB_AI  LB_BLOCK_SPEC"\x81"
#define LB_AU  LB_BLOCK_SPEC"\x82"

#define LB_DWE LB_BLOCK_SPEC"\x83"
#define LB_DWO LB_BLOCK_SPEC"\x84"

#define LB_NWA LB_BLOCK_SPEC"\x85"

#define LB_PTE LB_BLOCK_SPEC"\x86"
#define LB_PHU LB_BLOCK_SPEC"\x87"

#define LB_RYA LB_BLOCK_SPEC"\x88"
#define LB_RAI LB_BLOCK_SPEC"\x89"
#define LB_RYO LB_BLOCK_SPEC"\x8a"

#define LB_TYA LB_BLOCK_SPEC"\x8b"
#define LB_TWE LB_BLOCK_SPEC"\x8c"
#define LB_TWO LB_BLOCK_SPEC"\x8d"