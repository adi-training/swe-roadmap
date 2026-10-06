CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -g -fsanitize=address,undefined

.PHONY: all clean test

all: dsa_runner vector_test

dsa_runner: src/dsa_solutions.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) src/dsa_solutions.cpp -o build/dsa_runner

vector_test: tests/test_custom_vector.cpp src/custom_vector.hpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -I src tests/test_custom_vector.cpp -o build/vector_test

test: all
	./build/dsa_runner
	./build/vector_test

clean:
	rm -rf build