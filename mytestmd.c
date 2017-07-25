#include "include/mbedtls/md5.h"

#include <string.h>


#define TEST_STR	"mytest stringggggggg"

int main(void)
{
	unsigned char output[16];
	mbedtls_md5(TEST_STR, sizeof(TEST_STR), output); 
	return 0;
}
