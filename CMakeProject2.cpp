// CMakeProject2.cpp : Defines the entry point for the application.
//

#define _CRT_SECURE_NO_WARNINGS

#include "CMakeProject2.h"

using namespace std;

int main()
{
	unsigned char bu[128]={'0'};
	unsigned char *buff = bu;
	FILE *fptr;
	FILE *fptr2;
	
	
	printf("HTTP/1.x 200 OK\n");
	printf("Content-type: text/plain\n\n");
	printf("Hello XML!\n");
	//http://www.cplusplus.com/forum/beginner/15987/
	if (( fptr = fopen("\\data\\src\\file.txt", "r+t" )) == NULL || (fptr2 = fopen("\\data\\src\\file2.txt", "w+t")) == NULL){
	printf( "File could not be opened.\n");
	}

	else {
	while ( !feof(fptr)){

	fread (buff , 1 , sizeof(bu) , fptr );
	fwrite (buff , 1 , sizeof(bu) , fptr2 );
	printf("%s", buff);

	}
	fclose(fptr);
	fclose(fptr2);
	}
	
	
	return 0;
}
