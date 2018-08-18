#pragma once

#include <string>
#include <iostream>
#include <mysql.h>

void test();
MYSQL* mysql_connect();

int mysql_insert(MYSQL* myfd, std::string &name, std::string &school, std::string &hobby);
int mysql_select(MYSQL* myfd);

void myclose(MYSQL* myfd);
