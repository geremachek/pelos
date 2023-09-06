/* interface for parsing Agean syllabaries */

/* sign pair type */

#define SYLLABLE_SIZE  4
#define SIGN_SIZE      5

#define LB_TOTAL_SIGNS 73
#define CY_TOTAL_SIGNS 55

typedef struct {
	char syllable[SYLLABLE_SIZE];
	char sign[SIGN_SIZE];
} SignPair;

static SignPair lb_signs[LB_TOTAL_SIGNS];
static SignPair cy_signs[CY_TOTAL_SIGNS];

/* our conversion function */

char* sign_convert(char latin[SYLLABLE_SIZE], SignPair signs[], size_t total);

char* lb_convert(char latin[SYLLABLE_SIZE]);
char* cy_convert(char latin[SYLLABLE_SIZE]);