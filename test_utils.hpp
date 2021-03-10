#ifndef TEST_UTILS_HPP
# define TEST_UTILS_HPP

#include "test.hpp"

template < typename I1, typename I2 >
bool check_by_value(I1 it1, I1 ite1, I2 it2, I2 ite2)
{
	for (; it1 != ite1 && it2 != ite2; ++it1, ++it2)
	{
		if (*it1 != *it2)
			return true;
	}
	if (it1 != ite1 || it2 != ite2)
		return true;
	return false;
}

template < typename I >
void log_container(I it, I ite)
{
	for (; it != ite; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template < typename C1, typename C2 >
void test_containers(C1 stdc, C2 ftc)
{
	if (check_by_value(stdc.begin(), stdc.end(), ftc.begin(), ftc.end()) == true)
	{
		std::cout << std::endl;
		print_ko();
		std::cout << "Error found!" << std::endl << "Expected: ";
		log_container(stdc.begin(), stdc.end());
		std::cout << "But got: ";
		log_container(ftc.begin(), ftc.end());
		std::cout << "___________________________________________" << std::endl << std::endl;
		return;
	}
	print_ok();
}

template < typename S1, typename S2 >
void test_stacks(S1 stdc, S2 ftc)
{
	if (stdc.size() != ftc.size() || stdc.empty() != ftc.empty() ||
		(stdc.size() > 0 && stdc.top() != ftc.top()))
	{
		return print_ko();
	}
	print_ok();
}

template < typename Q1, typename Q2 >
void test_queues(Q1 stdc, Q2 ftc)
{
	if (stdc.size() != ftc.size() || stdc.empty() != ftc.empty() ||
		(stdc.size() > 0 && stdc.front() != ftc.front() && stdc.back() != ftc.back()))
	{
		return print_ko();
	}
	print_ok();
}

template < typename I1, typename I2 >
bool check_maps_by_value(I1 it1, I1 ite1, I2 it2, I2 ite2)
{
	for (; it1 != ite1 && it2 != ite2; ++it1, ++it2)
	{
		if (it1->first != it2->first ||
			it1->second != it2->second)
			return true;
	}
	if (it1 != ite1 || it2 != ite2)
		return true;
	return false;
}

template < typename M1, typename M2 >
void test_maps(M1 const &stdc, M2 const &ftc)
{
	if (stdc.size() != ftc.size() || stdc.empty() != ftc.empty() ||
		check_maps_by_value(stdc.begin(), stdc.end(), ftc.begin(), ftc.end()) == true)
		return print_ko();
	print_ok();
}

template < typename S1, typename S2 >
void test_sets(S1 const &stdc, S2 const &ftc)
{
	if (stdc.size() != ftc.size() || stdc.empty() != ftc.empty() ||
		check_by_value(stdc.begin(), stdc.end(), ftc.begin(), ftc.end()) == true)
		return print_ko();
	print_ok();
}

template < typename D1, typename D2 >
void test_deques(D1 const &stdc, D2 const &ftc)
{
	if (stdc.size() != ftc.size() || stdc.empty() != ftc.empty() ||
		check_by_value(stdc.begin(), stdc.end(), ftc.begin(), ftc.end()) == true)
		return print_ko();
	print_ok();
}

template < typename T >
void test_values(T const &value1, T const &value2)
{
	if (value1 == value2)
		print_ok();
	else
	{
		std::cout << std::endl;
		print_ko();
		std::cout << "Error found!" << std::endl << "Expected: "
			<< value1 << ", but got: " << value2 << std::endl;
		std::cout << "___________________________________________" << std::endl << std::endl;
	}
}

template < typename C1, typename C2 >
void randcontint(C1 &c1, C2 &c2)
{
	c1.clear(); c2.clear();
	int size = randint(10, 100);
	int val;
	for (int i = 0; i < size; i++)
	{
		val = randint(-100000, 100000);
		c1.push_back(val); c2.push_back(val);
	}
}

template < typename C1, typename C2 >
void randcontchar(C1 &c1, C2 &c2)
{
	c1.clear(); c2.clear();
	int size = randint(10, 100);
	char val;
	for (int i = 0; i < size; i++)
	{
		val = randchar();
		c1.push_back(val); c2.push_back(val);
	}
}

template < typename C1, typename C2 >
void randcontstring(C1 &c1, C2 &c2)
{
	c1.clear(); c2.clear();
	int size = randint(10, 100);
	std::string val;
	for (int i = 0; i < size; i++)
	{
		val = randstring(10);
		c1.push_back(val); c2.push_back(val);
	}
}

template < typename S >
void clearstack(S &s)
{
	while (s.size() > 0)
	{
		s.pop();
	}
}

template < typename S1, typename S2 >
void randstackint(S1 &s1, S2 &s2)
{
	clearstack(s1); clearstack(s2);
	int size = randint(10, 100);
	int val;
	for (int i = 0; i < size; i++)
	{
		val = randint(-100000, 100000);
		s1.push(val); s2.push(val);
	}
}

template < typename S1, typename S2 >
void randstackstring(S1 &s1, S2 &s2)
{
	clearstack(s1); clearstack(s2);
	int size = randint(10, 100);
	std::string val;
	for (int i = 0; i < size; i++)
	{
		val = randstring(10);
		s1.push(val); s2.push(val);
	}
}

template < typename D1, typename D2 >
void randdequeint(D1 &d1, D2 &d2)
{
	d1.clear(); d2.clear();
	int size = randint(10, 100);
	int val;
	for (int i = 0; i < size; i++)
	{
		val = randint(-100000, 100000);
		d1.push_back(val); d2.push_back(val);
		d1.push_front(val + 1); d2.push_front(val + 1);
	}
}

template < typename D1, typename D2 >
void randdequestring(D1 &d1, D2 &d2)
{
	d1.clear(); d2.clear();
	int size = randint(10, 100);
	std::string val;
	for (int i = 0; i < size; i++)
	{
		val = randstring(10);
		d1.push_back(val); d2.push_back(val);
		d1.push_front(val + std::string("a")); d2.push_front(val + std::string("a"));
	}
}

template < typename M1, typename M2 >
void randmapint(M1 &m1, M2 &m2)
{
	m1.clear(); m2.clear();
	int size = randint(10, 100);
	int key;
	int val;
	for (int i = 0; i < size; i++)
	{
		key = randint(-100000, 100000);
		val = randint(-100000, 100000);
		m1[key] = val; m2[key] = val;
	}
}

template < typename M1, typename M2 >
void randmapstring(M1 &m1, M2 &m2)
{
	m1.clear(); m2.clear();
	int size = randint(10, 100);
	std::string key;
	std::string val;
	for (int i = 0; i < size; i++)
	{
		key = randstring(10);
		val = randstring(10);
		m1[key] = val; m2[key] = val;
	}
}

template < typename M1, typename M2 >
void randmultimapint(M1 &m1, M2 &m2)
{
	m1.clear(); m2.clear();
	int size = randint(10, 100);
	int key;
	int val;
	for (int i = 0; i < size; i++)
	{
		key = randint(-100000, 100000);
		val = randint(-100000, 100000);
		m1.insert(std::pair<int,int>(key,val));
		m1.insert(std::pair<int,int>(key,val));
		m1.insert(std::pair<int,int>(key,val + key));
		m1.insert(std::pair<int,int>(key,val - key));
		m2.insert(ft::Pair<int,int>(key,val));
		m2.insert(ft::Pair<int,int>(key,val));
		m2.insert(ft::Pair<int,int>(key,val + key));
		m2.insert(ft::Pair<int,int>(key,val - key));
	}
}

template < typename M1, typename M2 >
void randmultimapstring(M1 &m1, M2 &m2)
{
	m1.clear(); m2.clear();
	int size = randint(10, 100);
	std::string key;
	std::string val;
	for (int i = 0; i < size; i++)
	{
		key = randstring(10);
		val = randstring(10);
		m1.insert(std::pair<std::string,std::string>(key,val));
		m1.insert(std::pair<std::string,std::string>(key,val));
		m1.insert(std::pair<std::string,std::string>(key,val + std::string("a")));
		m2.insert(ft::Pair<std::string,std::string>(key,val));
		m2.insert(ft::Pair<std::string,std::string>(key,val));
		m2.insert(ft::Pair<std::string,std::string>(key,val + std::string("a")));
	}
}

template < typename S1, typename S2 >
void randsetint(S1 &s1, S2 &s2)
{
	s1.clear(); s2.clear();
	int size = randint(10, 100);
	int val;
	for (int i = 0; i < size; i++)
	{
		val = randint(-100000, 100000);
		s1.insert(val); s2.insert(val);
	}
}

template < typename S1, typename S2 >
void randsetstring(S1 &s1, S2 &s2)
{
	s1.clear(); s2.clear();
	int size = randint(10, 100);
	std::string val;
	for (int i = 0; i < size; i++)
	{
		val = randstring(10);
		s1.insert(val); s2.insert(val);
	}
}

template < typename S1, typename S2 >
void randmultisetint(S1 &s1, S2 &s2)
{
	s1.clear(); s2.clear();
	int size = randint(10, 100);
	int val;
	for (int i = 0; i < size; i++)
	{
		val = randint(-100000, 100000);
		s1.insert(val); s2.insert(val);
		s1.insert(val); s2.insert(val);
		s1.insert(val + 1); s2.insert(val + 1);
		s1.insert(val + val); s2.insert(val + val);
		s1.insert(val - 1); s2.insert(val - 1);
	}
}

template < typename S1, typename S2 >
void randmultisetstring(S1 &s1, S2 &s2)
{
	s1.clear(); s2.clear();
	int size = randint(10, 100);
	std::string val;
	for (int i = 0; i < size; i++)
	{
		val = randstring(10);
		s1.insert(val); s2.insert(val);
		s1.insert(val); s2.insert(val);
		s1.insert(val + std::string("a")); s2.insert(val + std::string("a"));
	}
}

#endif
