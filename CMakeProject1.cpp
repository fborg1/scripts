// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"

using namespace std;

int main()
{
	char m[200];
    char *data = m;
	printf("HTTP/1.x 200 OK\n");
	printf("Content-type: text/html\n\n");
	printf("<!DOCTYPE html>");

	printf("<html lang=\"en\" xmlns=\"http://www.w3.org/1999/xhtml\">");
	printf("<head>");
	printf("<meta charset=\"utf-8\"/>");
	printf("<title></title>");
	printf("</head>");
	printf("<body>");
	printf("<div>Hello World!</div>");
	printf("<div>");
	
    data=getenv("QUERY_STRING");
	printf(data);
	printf("</div>");
	printf("<div>");
	printf("<script type=\"text/javascript\">");
	printf("document.write(window.location.search)");//["name"];
    printf("</script>");
	printf("</div>");
	printf("</body>");
	printf("</html>");
	return 0;
}
