RunCheck: Check.h Check.c++
	g++ -pedantic -std=c++0x -Wall Check.c++ RunCheck.c++ -o RunCheck

run: RunCheck
	./RunCheck < RunCheck.in

# runv: RunCollatz
# 	valgrind RunCollatz < RunCollatz.in

# diff: RunCollatz
# 	RunCollatz < RunCollatz.in > RunCollatz.tmp
# 	diff RunCollatz.out RunCollatz.tmp
# 	rm RunCollatz.tmp

# TestCollatz: Collatz.h Collatz.c++ TestCollatz.c++
# 	g++ -lcppunit -ldl -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz

# test: TestCollatz
# 	TestCollatz

# testv: TestCollatz
# 	valgrind TestCollatz

clean:
	rm -f RunCheck
	rm -f TestCheck
	rm -f *.tmp
