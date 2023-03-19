CFLAGS := -Wall $(CFLAGS)
CXX = g++

#auto find correspeonding .c and .o files
cpp_files=$(shell find *.cpp)
programs=$(cpp_files:.cpp=)
o_files=$(programs:=.o)

all: $(programs)

.PHONY: clean

%: %.cpp
	$(CXX) $+ $(CFLAGS) -o $@

clean:
	rm $(o_files) $(programs) -f