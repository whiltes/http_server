#include "comm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char buf[1024];
	char method[64];

	if(getenv("METHOD"))
	{
		if(strcasecmp(getenv("METHOD"), "GET") == 0)
		{
			strcpy(buf, getenv("QUERY_STRING"));
		}
		else
		{
			int len = atoi(getenv("CONTENT_LENGTH"));
			int i = 0;
			for(; i < len; i++)
			{
				read(0, buf+i, 1);
			}
			buf[i] = '\0';
		}

	}

	
	MYSQL* myfd = mysql_connect();
	mysql_select(myfd);
	myclose(myfd);

	return 0;

}
