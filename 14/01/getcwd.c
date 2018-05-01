#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/*

man 3 getcwd

       POSIX.1-2001  標準の拡張として、  glibc  では  buf  が  NULL   の場合、
       getcwd()  は必要なバッファーを malloc(3)  を用いて動的に割り当てる。 こ
       の場合、 size が 0 の場合を除き、バッファーの長さは size となる。  size
       が  0  の場合には必要な大きさが確保される。  呼び出し側で、返されたバッ
       ファーを free(3)  すべきである。

*/

int main(int ac, char** av)
{
	
	char* buf;
	buf = getcwd(NULL, 0);
	printf("currentdir: %s\n", buf);
	free(buf);
	exit(0);
}
