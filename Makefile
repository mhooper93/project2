
all: maxprotein_timing test

test: maxprotein_test 
	./maxprotein_test

maxprotein_test: maxprotein.hh rubrictest.hh maxprotein_test.cc
	g++ -std=c++11 maxprotein_test.cc -o maxprotein_test

maxprotein_timing: maxprotein.hh timer.hh maxprotein_timing.cc
	g++ -std=c++11 maxprotein_timing.cc -o maxprotein_timing

clean:
	rm -f maxprotein_test maxprotein_timing
