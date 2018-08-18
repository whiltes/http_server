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
	
	

	std::cout << buf << std::endl;
	strtok(buf, "=&");
	std::string name = strtok(NULL, "=&");
	strtok(NULL, "=&");
	std::string school = strtok(NULL, "=&");
	strtok(NULL, "=&");
	std::string hobby = strtok(NULL, "=&");
	
	MYSQL* myfd = mysql_connect();
	mysql_insert(myfd, name, school, hobby);
	myclose(myfd);

	return 0;

}
