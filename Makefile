version := -std=c++11
gdb_args := -q
gdb_file := ./gdbscript.txt
program := ./validstring.cpp

a.out: $(program)
	g++ $(version) $<
	./$@

debug: $(program)
	g++ $< $(version) -ggdb -o $@
	gdb $(gdb_args) $@ -x $(gdb_file)

clean:
	rm -rf a.out