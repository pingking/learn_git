#include "include/mbedtls/cipher.h"
#include "include/mbedtls/aes.h"
#include "include/mbedtls/cipher_internal.h"
#include <string.h>
#include <stdio.h>

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
	mbedtls_aes_context ctx;
	unsigned char buf[16];
	unsigned char output[16];
	unsigned char output_o[16];
	int i;
	int mode = 0;
	unsigned char input[16]= "23456789ABCDEF01";
	unsigned char key[16]="0123456789ABCDEF";
	mbedtls_aes_init( &ctx );
/*
 *      * ECB mode
 *           */
//	memset(buf,0,16);
//	memset(key,0,16);
	mbedtls_aes_init(&ctx);
	printf("encryption\n");
	memcpy(buf,input,sizeof(input)/sizeof(char));
	mbedtls_aes_setkey_enc( &ctx, key, 128 );

	mbedtls_aes_crypt_ecb(&ctx, 1,buf,output);
	
	printf("decryption\n");
	memcpy(buf,input,sizeof(input)/sizeof(char));
	mbedtls_aes_setkey_dec(&ctx,key, 128 );
	mbedtls_aes_crypt_ecb(&ctx, 0,buf,output_o);


	printf("key:\n");
	dump_printf(key,sizeof(key)/sizeof(char));

	printf("enc---output\n");
	dump_printf(output,sizeof(output)/sizeof(char));

	printf("dec  output-o\n");
	dump_printf(output_o,sizeof(output_o)/sizeof(char));

	printf("modefied the first");
	printf("mode = %d\n ",mode^1);
	return 0;

}
