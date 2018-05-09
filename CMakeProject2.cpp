// CMakeProject2.cpp : Defines the entry point for the application.
//

#define _CRT_SECURE_NO_WARNINGS

#include "CMakeProject2.h"

using namespace std;

int main()
{
	unsigned char bu[2048]={'0'};
	unsigned char *buff = bu;
	FILE *fptr;
	FILE *fptr2;
	
	char    outbuf[180];                         // size of the szOut Buffer defined in SERVICE.C -> ServiceStart
    DWORD   bytesRead;
    BOOL    ret;
    LPSTR   lpszPipeName = "\\\\.\\pipe\\simple";
    LPSTR   lpszString = "World";
    unsigned int ndx;
    HRESULT hr;

    printf("HTTP/1.x 200 OK\n");
    printf("Content-type: text/plain\n\n");
   
    printf("Hello XML!\n");
    // allow user to define pipe name
    /*for ( ndx = 1; ndx < argc; ndx++ )
    {
       if ( (*argv[ndx] == '-') || (*argv[ndx] == '/') )
       {
          if ( !(_stricmp( "pipe", argv[ndx]+1 )) && ( (ndx + 1) < argc))
          {
             lpszPipeName = argv[++ndx];
          }
          else if ( !(_stricmp( "string", argv[ndx]+1 )) && ( (ndx + 1) < argc))
          {
             lpszString = argv[++ndx];
          }
          else
          {
             printf("usage: client [-pipe <pipename>] [-string <string>]\n");
             exit(1);
          }
       }
       else
       {
          printf("usage: client [-pipe <pipename>] [-string <string>]\n");
          exit(1);
       }

    }*/

    hr = StringCchLength(lpszString,100,&ndx);
    if (FAILED(hr))
    {
        printf("Buffer is too large!\n");
        return 0;
    }

    ret = CallNamedPipe(lpszPipeName,
                       lpszString, ndx,
                       outbuf,180 ,
                       &bytesRead, NMPWAIT_WAIT_FOREVER);

    if (!ret)
    {
       printf("client: CallNamedPipe failed, GetLastError = %d\n", GetLastError());
       exit(1);
    }

    printf("client: received: %s\n", outbuf);
	
	
	
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
