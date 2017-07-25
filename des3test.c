#include "include/mbedtls/cipher.h"
#include "include/mbedtls/des.h"
#include "include/mbedtls/cipher_internal.h"
//#include <trace.h>
#include <string.h>
#include <stdio.h>

//#define key    "0123456789ABCDEF"
//#define input  "23456789ABCDEF01"
void dump_printf(unsigned char *p,int size)
{
	int i;
	printf("dump_printf\n");
	for(i=0;i<size;i++)
	{
		printf("%02x ",p[i]);
	}
	printf("\n");
}
int main(void)
{
	mbedtls_des3_context ctx;
	unsigned char buf[8];
	unsigned char output[8];
	unsigned char output_o[8];
	int i;
	int mode = 0;
	unsigned char input[16]= "23456789ABCDEF01";
	unsigned char key[16]="0123456789ABCDEF"; 
/*
 *      * ECB mode
 *           */
//	memset(buf,0,16);
//	memset(key,0,16);
	mbedtls_des3_init(&ctx);
	printf("encryption\n");
	memcpy(buf,input,8);
	mbedtls_des3_set2key_enc( &ctx, key );

	mbedtls_des3_crypt_ecb(&ctx, buf,output);
	
	printf("decryption\n");
	memcpy(buf,input,8);
	mbedtls_des3_set2key_dec(&ctx,key );
	mbedtls_des3_crypt_ecb(&ctx, buf,output_o);


	printf("key:\n");
	dump_printf(key,sizeof(key)/sizeof(char));

	printf("enc---output\n");
	dump_printf(output,sizeof(output)/sizeof(char));

	printf("dec  output-o\n");
	dump_printf(output_o,sizeof(output_o)/sizeof(char));


	printf("mode = %d\n ",mode^1);
	return 0;

}
