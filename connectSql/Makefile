LIB_DIR=$(shell pwd)/../lib
INCLUDE=-I$(LIB_DIR)/include
LIB=-L$(LIB_DIR)/lib

.PHONY:all
all:insert_cgi select_cgi
 
insert_cgi:insert_cgi.cpp comm.cpp
	@g++ -o $@ $^ $(INCLUDE) $(LIB) -lmysqlclient 

select_cgi:select_cgi.cpp comm.cpp
	@g++ -o $@ $^ $(INCLUDE)	$(LIB) -lmysqlclient 

.PHONY:clean
clean:
	@rm -f insert_cgi select_cgi
