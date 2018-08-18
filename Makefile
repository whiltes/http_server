WORK_PATH=$(shell pwd)
BIN=httpd
SRC=httpd.c
CC=gcc
LDFLAGS=-lpthread -DDEBUG

.PHONY:all
all:$(BIN) cgi


$(BIN):$(SRC)
	@$(CC) -o $@ $^ $(LDFLAGS)
cgi:
	@cd wwwroot/cgi; make clean; make; cd -
	@cd connectSql; make clean; make; cd -

.PHONY:output
output:
	@mkdir -p output/wwwroot/cgi
	@cp $(BIN) output
	@cp start.h  output
	@cp wwwroot/*.html output/wwwroot
	@cp -rf wwwroot/imag output/wwwroot
	@cp wwwroot/cgi/math_cgi output/wwwroot/cgi
	@cp connectSql/insert_cgi output/wwwroot/cgi
	@cp connectSql/select_cgi output/wwwroot/cgi	
	@cp -rf lib/lib output/

.PHONY:clean
clean:
	@rm -f $(BIN)
	@rm -rf output
	@cd wwwroot/cgi; make clean; make; cd -
	@cd connectSql; make clean; make; cd -



