.PHONY:all
all:test_cgi math_cgi

test_cgi:test_cgi.c
	@gcc -o $@ $^
math_cgi:math_cgi.c
	@gcc -o $@ $^


.PHONY:clean
clean:
	@rm -f test_cgi math_cgi
