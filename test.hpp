#ifndef TEST_HPP
# define TEST_HPP

// STD library includes
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>

// STL containers includes
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <set>

// FT containers includes
#include "List.hpp"
#include "Vector.hpp"
#include "Map.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "Deque.hpp"
#include "Set.hpp"
#include "Multiset.hpp"
#include "Multimap.hpp"

char randchar();
int randint(int min, int max);
std::string randstring(size_t length);
void print_ok();
void print_ko();

template < typename I >
void log_container(I it, I ite);

template < typename C1, typename C2 >
void test_containers(C1 stdc, C2 ftc);

template < typename T >
void test_values(T const &value1, T const &value2);

template < typename C1, typename C2 >
void randcontint(C1 &c1, C2 &c2);

template < typename C1, typename C2 >
void randcontchar(C1 &c1, C2 &c2);

bool int_predicate(int val);
bool string_predicate(std::string val);
bool int_binary_predicate(int val1, int val2);
bool string_binary_predicate(std::string val1, std::string val2);

// Test includes
#include "test_utils.hpp"

#endif
