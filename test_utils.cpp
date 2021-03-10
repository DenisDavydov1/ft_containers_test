#include "test.hpp"

char randchar()
{
	const char charset[] =
	"0123456789!@#$%^&*()_+}{[]?></.,\\;\"\': 	`~"
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	"abcdefghijklmnopqrstuvwxyz";
	const size_t max_index = (sizeof(charset) - 1);
	return charset[std::rand() % max_index];
}

int randint(int min, int max)
{
	return min + (std::rand() % static_cast<int>(max - min + 1));
}

std::string randstring(size_t length)
{
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}

void print_ok()
{
	std::cout << "\033[1;32mOK\033[0m ";
}

void print_ko()
{
	std::cout << "\033[1;31mKO\033[0m ";
}

bool int_predicate(int val)
{
	return val % 2;
}

bool string_predicate(std::string val)
{
	return val[0] > 'A';
}

bool int_binary_predicate(int val1, int val2)
{
	return val1 >= val2;
}

bool string_binary_predicate(std::string val1, std::string val2)
{
	return val1.size() >= val2.size();
}
