#include "test.hpp"

std::vector<std::string> check_av(int ac, char **av)
{
	std::vector<std::string> args;

	if (ac < 2)
	{
		std::cout << "Error: not valid argument number" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 1; av[i]; i++)
	{
		args.push_back(av[i]);
		if (!(args.back() == "list" || args.back() == "vector" || 
			args.back() == "map" || args.back() == "stack" || 
			args.back() == "queue" || args.back() == "all" ||
			args.back() == "deque" || args.back() == "set" || 
			args.back() == "multiset" || args.back() == "multimap" ||
			args.back() == "bonus"))
		{
			std::cout << "Error: arguments not valid" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	return args;
}

void test_vector_int()
{
	std::cout << std::endl << "🙁 [Vector <int> test] ";

	std::cout << "[Constructors] ";
	std::vector<int> v1; ft::Vector<int> v2; test_containers(v1, v2);
	v1 = std::vector<int>(10); v2 = ft::Vector<int>(10); test_containers(v1, v2);
	v1 = std::vector<int>(100, 123); v2 = ft::Vector<int>(100, 123); test_containers(v1, v2);
	std::vector<int> v3(v1.begin(), v1.end()); ft::Vector<int> v4(v2.begin(), v2.end()); test_containers(v3, v4);
	v1 = std::vector<int>(v3); v2 = ft::Vector<int>(v4); test_containers(v1, v2);
	randcontint(v1, v2); v3 = v1; v4 = v2; test_containers(v3, v4);

	std::cout << "[Iterators] ";
	std::vector<int>::iterator it1 = v1.begin(); ft::Vector<int>::iterator it2 = v2.begin(); test_values(*it1, *it2);
	it1 = --v1.end(); it2 = --v2.end(); test_values(*it1, *it2);
	it1--; it2--; test_values(*it1, *it2);
	it1 -= 5; it2 -= 5; test_values(*it1, *it2);
	*it1 = -1234; *it2 = -1234; test_values(*it1, *it2);
	it1 += 2; it2 += 2; test_values(*it1, *it2);
	std::vector<int>::iterator it5 = v1.begin(); ft::Vector<int>::iterator it6 = v2.begin();
	test_values(it1 - it5, it2 - it6); test_values(++it5 - it1++, ++it6 - it2++);
	test_values(it1[1], it2[1]); it1[1] = 5; it2[1] = 5; test_values(*(++it1), *(++it2));
	std::vector<int>::const_iterator it3 = v1.begin(); ft::Vector<int>::const_iterator it4 = v2.begin(); test_values(*it3, *it4);
	std::vector<int> const v5(10, 10); ft::Vector<int> const v6(10, 10);
	it3 = v5.begin(); it4 = v6.begin(); test_values(*it3, *it4);
	it3 = v5.end(); it4 = v6.end(); test_values(*--it3, *--it4);
	test_values(it3[-3], it4[-3]);
	std::vector<int>::reverse_iterator it7 = v1.rbegin(); ft::Vector<int>::reverse_iterator it8 = v2.rbegin();
	test_values(*it7, *it8); test_values(it7 - it7, it8 - it8); test_values(*(it7 + 5), *(it8 + 5));
	test_values(it7[3], it8[3]); it7[3] = 6; it8[3] = 6; test_values(it7[3], it8[3]);
	std::vector<int>::const_reverse_iterator it9(it7); ft::Vector<int>::const_reverse_iterator it10(it8);
	test_values(*it9, *it10); test_values(*it7, *it9); test_values(*(++it9), *(++it10));

	std::cout << "[Capacity] ";
	test_values(v1.size(), v2.size()); test_values(v3.size(), v4.size()); test_values(v5.size(), v6.size());
	v1 = std::vector<int>(); v2 = ft::Vector<int>(); test_values(v1.size(), v2.size());
	v1.push_back(0); v2.push_back(0); test_values(v1.size(), v2.size());
	test_values(v1.max_size(), v2.max_size());
	test_values(std::vector<int>().max_size(), ft::Vector<int>().max_size());
	test_values(std::vector<int>(1000).max_size(), ft::Vector<int>(1000).max_size());
	v1.resize(50); v2.resize(50); test_containers(v1, v2); test_values(v1.size(), v2.size());
	v1.resize(150); v2.resize(150); test_containers(v1, v2); test_values(v1.size(), v2.size());
	v1.resize(200, 222); v2.resize(200, 222); test_containers(v1, v2); test_values(v1.size(), v2.size());
	std::vector<int> v7; ft::Vector<int> v8; test_values(v7.capacity(), v8.capacity());
	v7.insert(v7.begin(), 3, 0); v8.insert(v8.begin(), 3, 0); test_values(v7.capacity(), v8.capacity());
	v7.insert(v7.begin(), 1, 0); v8.insert(v8.begin(), 1, 0); test_values(v7.capacity(), v8.capacity());
	v7.insert(v7.begin(), 1, 0); v8.insert(v8.begin(), 1, 0); test_values(v7.capacity(), v8.capacity());
	test_values(v7.empty(), v8.empty());
	v7 = std::vector<int>(); v8 = ft::Vector<int>(); test_values(v7.empty(), v8.empty());
	v7.reserve(512); v8.reserve(512); test_values(v7.capacity(), v8.capacity());
	
	std::cout << "[Element access] ";
	randcontint(v1, v2); test_values(v1[0], v2[0]);
	v1[0] = 100500; v2[0] = 100500; test_values(v1[0], v2[0]);
	test_values(v1.at(1), v2.at(1));
	std::string e1, e2;
	try { v1.at(-1); } catch(std::exception &e) { e1 = std::string(e.what()); }
	try { v2.at(-1); } catch(std::exception &e) { e2 = std::string(e.what()); }
	if (e1.empty() == false && e2.empty() == false) test_values(e1, e2);
	test_values(v1.front(), v2.front()); test_values(v1.back(), v2.back());
	test_values(v3.front(), v4.front()); test_values(v3.back(), v4.back());

	std::cout << "[Modifiers] ";
	v3.assign(++v1.begin(), --v1.end()); v4.assign(++v2.begin(), --v2.end()); test_containers(v3, v4);
	v3.assign(6, 666); v4.assign(6, 666); test_containers(v3, v4);
	v3.assign(0, 666); v4.assign(0, 666); test_containers(v3, v4);
	v3.push_back(777); v4.push_back(777); test_containers(v3, v4);
	v1.pop_back(); v2.pop_back(); test_containers(v1, v2);
	v1.insert(--v1.end(), 888); v2.insert(--v2.end(), 888); test_containers(v1, v2);
	v1.insert(--v1.end(), 9, 999); v2.insert(--v2.end(), 9, 999); test_containers(v1, v2);
	v3.insert(v3.end(), v1.begin(), v1.end()); v4.insert(v4.end(), v2.begin(), v2.end()); test_containers(v3, v4);
	v3.erase(++v3.begin()); v4.erase(++v4.begin()); test_containers(v3, v4);
	v3.erase(++v3.begin(), ++++v3.begin()); v4.erase(++v4.begin(), ++++v4.begin()); test_containers(v3, v4);
	v1.swap(v3); v2.swap(v4); test_containers(v1, v2); test_containers(v3, v4);
	v3.clear(); v4.clear(); test_containers(v3, v4);

	std::cout << "[Non-member function overloads] ";
	randcontint(v1, v2);
	std::vector<int> v9(v1); ft::Vector<int> v10(v2); test_containers(v9, v10);
	bool r1 = (v1 == v9); bool r2 = (v2 == v10); test_values(r1, r2);
	r1 = (v1 == v3); r2 = (v2 == v4); test_values(r1, r2);
	r1 = (v1 < v3); r2 = (v2 < v4); test_values(r1, r2);
	r1 = (v1 > v3); r2 = (v2 > v4); test_values(r1, r2);
	r1 = (v1 >= v9); r2 = (v2 >= v10); test_values(r1, r2);
	r1 = (v1 <= v3); r2 = (v2 <= v4); test_values(r1, r2);
	ft::swap(v3, v1); ft::swap(v4, v2); test_containers(v3, v4); test_containers(v1, v2);
	std::cout << std::endl;
}

void test_vector_string()
{
	std::cout << std::endl << "🙁 [Vector <std::string> test] ";

	std::cout << "[Constructors] ";
	std::vector<std::string> v1; ft::Vector<std::string> v2; test_containers(v1, v2);
	v1 = std::vector<std::string>(10); v2 = ft::Vector<std::string>(10); test_containers(v1, v2);
	v1 = std::vector<std::string>(10, "abcd"); v2 = ft::Vector<std::string>(10, "abcd"); test_containers(v1, v2);
	std::vector<std::string> v3(v1.begin(), v1.end()); ft::Vector<std::string> v4(v2.begin(), v2.end()); test_containers(v3, v4);
	v1 = std::vector<std::string>(v3); v2 = ft::Vector<std::string>(v4); test_containers(v1, v2);
	randcontstring(v1, v2); v3 = v1; v4 = v2; test_containers(v3, v4);

	std::cout << "[Iterators] ";
	std::vector<std::string>::iterator it1 = v1.begin(); ft::Vector<std::string>::iterator it2 = v2.begin(); test_values(*it1, *it2);
	it1 = --v1.end(); it2 = --v2.end(); test_values(*it1, *it2);
	it1--; it2--; test_values(*it1, *it2);
	it1 -= 5; it2 -= 5; test_values(*it1, *it2);
	*it1 = "-1234"; *it2 = "-1234"; test_values(*it1, *it2);
	it1 += 2; it2 += 2; test_values(*it1, *it2);
	std::vector<std::string>::iterator it5 = v1.begin(); ft::Vector<std::string>::iterator it6 = v2.begin();
	test_values(it1 - it5, it2 - it6); test_values(++it5 - it1++, ++it6 - it2++);
	test_values(it1[1], it2[1]); it1[1] = "5"; it2[1] = "5"; test_values(*(++it1), *(++it2));
	std::vector<std::string>::const_iterator it3 = v1.begin(); ft::Vector<std::string>::const_iterator it4 = v2.begin(); test_values(*it3, *it4);
	std::vector<std::string> const v5(10, "10"); ft::Vector<std::string> const v6(10, "10");
	it3 = v5.begin(); it4 = v6.begin(); test_values(*it3, *it4);
	it3 = v5.end(); it4 = v6.end(); test_values(*--it3, *--it4);
	test_values(it3[-2], it4[-2]);
	std::vector<std::string>::reverse_iterator it7 = v1.rbegin(); ft::Vector<std::string>::reverse_iterator it8 = v2.rbegin();
	test_values(*it7, *it8); test_values(it7 - it7, it8 - it8); test_values(*(it7 + 5), *(it8 + 5));
	test_values(it7[3], it8[3]); it7[3] = "6"; it8[3] = "6"; test_values(it7[3], it8[3]);
	std::vector<std::string>::const_reverse_iterator it9(it7); ft::Vector<std::string>::const_reverse_iterator it10(it8);
	test_values(*it9, *it10); test_values(*it7, *it9); test_values(*(++it9), *(++it10));

	std::cout << "[Capacity] ";
	test_values(v1.size(), v2.size()); test_values(v3.size(), v4.size()); test_values(v5.size(), v6.size());
	v1 = std::vector<std::string>(); v2 = ft::Vector<std::string>(); test_values(v1.size(), v2.size());
	v1.push_back("0"); v2.push_back("0"); test_values(v1.size(), v2.size());
	test_values(v1.max_size(), v2.max_size());
	test_values(std::vector<std::string>().max_size(), ft::Vector<std::string>().max_size());
	test_values(std::vector<std::string>(1000).max_size(), ft::Vector<std::string>(1000).max_size());
	v1.resize(50); v2.resize(50); test_containers(v1, v2); test_values(v1.size(), v2.size());
	v1.resize(150); v2.resize(150); test_containers(v1, v2); test_values(v1.size(), v2.size());
	v1.resize(200, "222"); v2.resize(200, "222"); test_containers(v1, v2); test_values(v1.size(), v2.size());
	std::vector<std::string> v7; ft::Vector<std::string> v8; test_values(v7.capacity(), v8.capacity());
	v7.insert(v7.begin(), 3, "0"); v8.insert(v8.begin(), 3, "0"); test_values(v7.capacity(), v8.capacity());
	v7.insert(v7.begin(), 1, "0"); v8.insert(v8.begin(), 1, "0"); test_values(v7.capacity(), v8.capacity());
	v7.insert(v7.begin(), 1, "0"); v8.insert(v8.begin(), 1, "0"); test_values(v7.capacity(), v8.capacity());
	test_values(v7.empty(), v8.empty());
	v7 = std::vector<std::string>(); v8 = ft::Vector<std::string>(); test_values(v7.empty(), v8.empty());
	v7.reserve(512); v8.reserve(512); test_values(v7.capacity(), v8.capacity());
	
	std::cout << "[Element access] ";
	randcontstring(v1, v2); test_values(v1[0], v2[0]);
	v1[0] = "100500"; v2[0] = "100500"; test_values(v1[0], v2[0]);
	test_values(v1.at(1), v2.at(1));
	std::string e1, e2;
	try { v1.at(-1); } catch(std::exception &e) { e1 = std::string(e.what()); }
	try { v2.at(-1); } catch(std::exception &e) { e2 = std::string(e.what()); }
	if (e1.empty() == false && e2.empty() == false) test_values(e1, e2);
	test_values(v1.front(), v2.front()); test_values(v1.back(), v2.back());
	test_values(v3.front(), v4.front()); test_values(v3.back(), v4.back());

	std::cout << "[Modifiers] ";
	v3.assign(++v1.begin(), --v1.end()); v4.assign(++v2.begin(), --v2.end()); test_containers(v3, v4);
	v3.assign(6, "666"); v4.assign(6, "666"); test_containers(v3, v4);
	v3.assign(0, "666"); v4.assign(0, "666"); test_containers(v3, v4);
	v3.push_back("777"); v4.push_back("777"); test_containers(v3, v4);
	v1.pop_back(); v2.pop_back(); test_containers(v1, v2);
	v1.insert(--v1.end(), "888"); v2.insert(--v2.end(), "888"); test_containers(v1, v2);
	v1.insert(--v1.end(), 9, "999"); v2.insert(--v2.end(), 9, "999"); test_containers(v1, v2);
	v3.insert(v3.end(), v1.begin(), v1.end()); v4.insert(v4.end(), v2.begin(), v2.end()); test_containers(v3, v4);
	v3.erase(++v3.begin()); v4.erase(++v4.begin()); test_containers(v3, v4);
	v3.erase(++v3.begin(), ++++v3.begin()); v4.erase(++v4.begin(), ++++v4.begin()); test_containers(v3, v4);
	v1.swap(v3); v2.swap(v4); test_containers(v1, v2); test_containers(v3, v4);
	v3.clear(); v4.clear(); test_containers(v3, v4);

	std::cout << "[Non-member function overloads] ";
	randcontstring(v1, v2);
	std::vector<std::string> v9(v1); ft::Vector<std::string> v10(v2); test_containers(v9, v10);
	bool r1 = (v1 == v9); bool r2 = (v2 == v10); test_values(r1, r2);
	r1 = (v1 == v3); r2 = (v2 == v4); test_values(r1, r2);
	r1 = (v1 < v3); r2 = (v2 < v4); test_values(r1, r2);
	r1 = (v1 > v3); r2 = (v2 > v4); test_values(r1, r2);
	r1 = (v1 >= v9); r2 = (v2 >= v10); test_values(r1, r2);
	r1 = (v1 <= v3); r2 = (v2 <= v4); test_values(r1, r2);
	ft::swap(v3, v1); ft::swap(v4, v2); test_containers(v3, v4); test_containers(v1, v2);
	std::cout << std::endl;
}

void test_list_int()
{
	std::cout << std::endl << "😟 [List <int> test] ";

	std::cout << "[Constructors] ";
	std::list<int> v1; ft::List<int> v2; test_containers(v1, v2);
	v1 = std::list<int>(10); v2 = ft::List<int>(10); test_containers(v1, v2);
	v1 = std::list<int>(100, 123); v2 = ft::List<int>(100, 123); test_containers(v1, v2);
	std::list<int> v3(v1.begin(), v1.end()); ft::List<int> v4(v2.begin(), v2.end()); test_containers(v3, v4);
	v1 = std::list<int>(v3); v2 = ft::List<int>(v4); test_containers(v1, v2);
	randcontint(v1, v2); v3 = v1; v4 = v2; test_containers(v3, v4);

	std::cout << "[Iterators] ";
	std::list<int>::iterator it1 = v1.begin(); ft::List<int>::iterator it2 = v2.begin(); test_values(*it1, *it2);
	it1 = --v1.end(); it2 = --v2.end(); test_values(*it1, *it2);
	it1--; it2--; test_values(*it1, *it2);
	*it1 = -1234; *it2 = -1234; test_values(*it1, *it2);
	std::list<int>::iterator it5 = v1.begin(); ft::List<int>::iterator it6 = v2.begin(); (void)it5; (void)it6;
	std::list<int>::const_iterator it3 = v1.begin(); ft::List<int>::const_iterator it4 = v2.begin(); test_values(*it3, *it4);
	std::list<int> const v5(10, 10); ft::List<int> const v6(10, 10);
	it3 = v5.begin(); it4 = v6.begin(); test_values(*it3, *it4);
	it3 = v5.end(); it4 = v6.end(); test_values(*--it3, *--it4);
	std::list<int>::reverse_iterator it7 = v1.rbegin(); ft::List<int>::reverse_iterator it8 = v2.rbegin();
	test_values(*it7, *it8);
	std::list<int>::const_reverse_iterator it9(it7); ft::List<int>::const_reverse_iterator it10(it8);
	test_values(*it9, *it10); test_values(*it7, *it9); test_values(*(++it9), *(++it10));

	std::cout << "[Capacity] ";
	test_values(v1.size(), v2.size()); test_values(v3.size(), v4.size()); test_values(v5.size(), v6.size());
	v1 = std::list<int>(); v2 = ft::List<int>(); test_values(v1.size(), v2.size());
	v1.push_back(0); v2.push_back(0); test_values(v1.size(), v2.size());
	test_values(v1.max_size(), v2.max_size());
	test_values(std::list<int>().max_size(), ft::List<int>().max_size());
	test_values(std::list<int>(1000).max_size(), ft::List<int>(1000).max_size());
	test_values(v1.empty(), v2.empty());
	v3 = std::list<int>(); v4 = ft::List<int>(); test_values(v3.empty(), v4.empty());
	
	std::cout << "[Element access] ";
	randcontint(v1, v2); randcontint(v3, v4);
	test_values(v1.front(), v2.front()); test_values(v1.back(), v2.back());
	test_values(v3.front(), v4.front()); test_values(v3.back(), v4.back());

	std::cout << "[Modifiers] ";
	v3.assign(++v1.begin(), --v1.end()); v4.assign(++v2.begin(), --v2.end()); test_containers(v3, v4);
	v3.assign(6, 666); v4.assign(6, 666); test_containers(v3, v4);
	v3.assign(0, 666); v4.assign(0, 666); test_containers(v3, v4);
	v3.push_front(777); v4.push_front(777); test_containers(v3, v4);
	v1.pop_front(); v2.pop_front(); test_containers(v1, v2);
	v3.push_back(777); v4.push_back(777); test_containers(v3, v4);
	v1.pop_back(); v2.pop_back(); test_containers(v1, v2);
	v1.insert(--v1.end(), 888); v2.insert(--v2.end(), 888); test_containers(v1, v2);
	v1.insert(--v1.end(), 9, 999); v2.insert(--v2.end(), 9, 999); test_containers(v1, v2);
	v3.insert(v3.end(), v1.begin(), v1.end()); v4.insert(v4.end(), v2.begin(), v2.end()); test_containers(v3, v4);
	v3.erase(++v3.begin()); v4.erase(++v4.begin()); test_containers(v3, v4);
	v3.erase(++v3.begin(), ++++v3.begin()); v4.erase(++v4.begin(), ++++v4.begin()); test_containers(v3, v4);
	v1.swap(v3); v2.swap(v4); test_containers(v1, v2); test_containers(v3, v4);
	v1.resize(50); v2.resize(50); test_containers(v1, v2);
	v1.resize(75); v2.resize(75); test_containers(v1, v2);
	v1.resize(100, 50); v2.resize(100, 50); test_containers(v1, v2);
	v3.clear(); v4.clear(); test_containers(v3, v4);

	std::cout << "[Operations] ";
	randcontint(v1, v2); randcontint(v3, v4);
	v1.splice(++v1.begin(), v3); v2.splice(++v2.begin(), v4); test_containers(v1, v2); test_containers(v3, v4);
	v1.splice(v1.begin(), v1, v1.end()); v2.splice(v2.begin(), v2, v2.end()); test_containers(v1, v2);
	randcontint(v3, v4);
	v1.splice(--v1.end(), v3, ++v3.begin(), --v3.end()); v2.splice(--v2.end(), v4, ++v4.begin(), --v4.end());
	test_containers(v1, v2); test_containers(v3, v4);
	v1.push_front(5); v1.push_front(0); v1.push_back(5); v1.push_back(0);
	v2.push_front(5); v2.push_front(0); v2.push_back(5); v2.push_back(0);
	v1.remove(5); v2.remove(5); test_containers(v1, v2);
	v1.remove_if(int_predicate); v2.remove_if(int_predicate); test_containers(v1, v2);
	v3 = std::list<int>(6, 6); v4 = ft::List<int>(6, 6);
	v1.push_front(4); v2.push_front(4); v1.push_back(4); v2.push_back(4);
	v1.unique(); v2.unique(); test_containers(v1, v2);
	randcontint(v1, v2); randcontint(v3, v4);
	v1.unique(int_binary_predicate); v2.unique(int_binary_predicate); test_containers(v1, v2);
	v1.merge(v3); v2.merge(v4); test_containers(v1, v2); test_containers(v3, v4);
	randcontint(v3, v4);
	v1.merge(v3, int_binary_predicate); v2.merge(v4, int_binary_predicate);
	test_containers(v1, v2); test_containers(v3, v4);
	randcontint(v3, v4); v1.sort(); v2.sort(); v3.sort(int_binary_predicate); v4.sort(int_binary_predicate);
	test_containers(v1, v2); test_containers(v3, v4);
	v1.reverse(); v2.reverse(); test_containers(v1, v2);

	std::cout << "[Non-member function overloads] ";
	randcontint(v1, v2);
	std::list<int> v9(v1); ft::List<int> v10(v2); test_containers(v9, v10);
	bool r1 = (v1 == v9); bool r2 = (v2 == v10); test_values(r1, r2);
	r1 = (v1 == v3); r2 = (v2 == v4); test_values(r1, r2);
	r1 = (v1 < v3); r2 = (v2 < v4); test_values(r1, r2);
	r1 = (v1 > v3); r2 = (v2 > v4); test_values(r1, r2);
	r1 = (v1 >= v9); r2 = (v2 >= v10); test_values(r1, r2);
	r1 = (v1 <= v3); r2 = (v2 <= v4); test_values(r1, r2);
	ft::swap(v3, v1); ft::swap(v4, v2); test_containers(v3, v4); test_containers(v1, v2);
	std::cout << std::endl;
}

void test_list_string()
{
	std::cout << std::endl << "😟 [List <std::string> test] ";

	std::cout << "[Constructors] ";
	std::list<std::string> v1; ft::List<std::string> v2; test_containers(v1, v2);
	v1 = std::list<std::string>(10); v2 = ft::List<std::string>(10); test_containers(v1, v2);
	v1 = std::list<std::string>(100, "123"); v2 = ft::List<std::string>(100, "123"); test_containers(v1, v2);
	std::list<std::string> v3(v1.begin(), v1.end()); ft::List<std::string> v4(v2.begin(), v2.end()); test_containers(v3, v4);
	v1 = std::list<std::string>(v3); v2 = ft::List<std::string>(v4); test_containers(v1, v2);
	randcontstring(v1, v2); v3 = v1; v4 = v2; test_containers(v3, v4);

	std::cout << "[Iterators] ";
	std::list<std::string>::iterator it1 = v1.begin(); ft::List<std::string>::iterator it2 = v2.begin(); test_values(*it1, *it2);
	it1 = --v1.end(); it2 = --v2.end(); test_values(*it1, *it2);
	it1--; it2--; test_values(*it1, *it2);
	*it1 = "-1234"; *it2 = "-1234"; test_values(*it1, *it2);
	std::list<std::string>::iterator it5 = v1.begin(); ft::List<std::string>::iterator it6 = v2.begin(); (void)it5; (void)it6;
	std::list<std::string>::const_iterator it3 = v1.begin(); ft::List<std::string>::const_iterator it4 = v2.begin(); test_values(*it3, *it4);
	std::list<std::string> const v5(10, "10"); ft::List<std::string> const v6(10, "10");
	it3 = v5.begin(); it4 = v6.begin(); test_values(*it3, *it4);
	it3 = v5.end(); it4 = v6.end(); test_values(*--it3, *--it4);
	std::list<std::string>::reverse_iterator it7 = v1.rbegin(); ft::List<std::string>::reverse_iterator it8 = v2.rbegin();
	test_values(*it7, *it8);
	std::list<std::string>::const_reverse_iterator it9(it7); ft::List<std::string>::const_reverse_iterator it10(it8);
	test_values(*it9, *it10); test_values(*it7, *it9); test_values(*(++it9), *(++it10));

	std::cout << "[Capacity] ";
	test_values(v1.size(), v2.size()); test_values(v3.size(), v4.size()); test_values(v5.size(), v6.size());
	v1 = std::list<std::string>(); v2 = ft::List<std::string>(); test_values(v1.size(), v2.size());
	v1.push_back("0"); v2.push_back("0"); test_values(v1.size(), v2.size());
	test_values(v1.max_size(), v2.max_size());
	test_values(std::list<std::string>().max_size(), ft::List<std::string>().max_size());
	test_values(std::list<std::string>(1000).max_size(), ft::List<std::string>(1000).max_size());
	test_values(v1.empty(), v2.empty());
	v3 = std::list<std::string>(); v4 = ft::List<std::string>(); test_values(v3.empty(), v4.empty());
	
	std::cout << "[Element access] ";
	randcontstring(v1, v2); randcontstring(v3, v4);
	test_values(v1.front(), v2.front()); test_values(v1.back(), v2.back());
	test_values(v3.front(), v4.front()); test_values(v3.back(), v4.back());

	std::cout << "[Modifiers] ";
	v3.assign(++v1.begin(), --v1.end()); v4.assign(++v2.begin(), --v2.end()); test_containers(v3, v4);
	v3.assign(6, "666"); v4.assign(6, "666"); test_containers(v3, v4);
	v3.assign(0, "666"); v4.assign(0, "666"); test_containers(v3, v4);
	v3.push_front("777"); v4.push_front("777"); test_containers(v3, v4);
	v1.pop_front(); v2.pop_front(); test_containers(v1, v2);
	v3.push_back("777"); v4.push_back("777"); test_containers(v3, v4);
	v1.pop_back(); v2.pop_back(); test_containers(v1, v2);
	v1.insert(--v1.end(), "888"); v2.insert(--v2.end(), "888"); test_containers(v1, v2);
	v1.insert(--v1.end(), 9, "999"); v2.insert(--v2.end(), 9, "999"); test_containers(v1, v2);
	v3.insert(v3.end(), v1.begin(), v1.end()); v4.insert(v4.end(), v2.begin(), v2.end()); test_containers(v3, v4);
	v3.erase(++v3.begin()); v4.erase(++v4.begin()); test_containers(v3, v4);
	v3.erase(++v3.begin(), ++++v3.begin()); v4.erase(++v4.begin(), ++++v4.begin()); test_containers(v3, v4);
	v1.swap(v3); v2.swap(v4); test_containers(v1, v2); test_containers(v3, v4);
	v1.resize(50); v2.resize(50); test_containers(v1, v2);
	v1.resize(75); v2.resize(75); test_containers(v1, v2);
	v1.resize(100, "50"); v2.resize(100, "50"); test_containers(v1, v2);
	v3.clear(); v4.clear(); test_containers(v3, v4);

	std::cout << "[Operations] ";
	randcontstring(v1, v2); randcontstring(v3, v4);
	v1.splice(++v1.begin(), v3); v2.splice(++v2.begin(), v4); test_containers(v1, v2); test_containers(v3, v4);
	v1.splice(v1.begin(), v1, v1.end()); v2.splice(v2.begin(), v2, v2.end()); test_containers(v1, v2);
	randcontstring(v3, v4);
	v1.splice(--v1.end(), v3, ++v3.begin(), --v3.end()); v2.splice(--v2.end(), v4, ++v4.begin(), --v4.end());
	test_containers(v1, v2); test_containers(v3, v4);
	v1.push_front("5"); v1.push_front("0"); v1.push_back("5"); v1.push_back("0");
	v2.push_front("5"); v2.push_front("0"); v2.push_back("5"); v2.push_back("0");
	v1.remove("5"); v2.remove("5"); test_containers(v1, v2);
	v1.remove_if(string_predicate); v2.remove_if(string_predicate); test_containers(v1, v2);
	v3 = std::list<std::string>(6, "6"); v4 = ft::List<std::string>(6, "6");
	v1.push_front("4"); v2.push_front("4"); v1.push_back("4"); v2.push_back("4");
	v1.unique(); v2.unique(); test_containers(v1, v2);
	randcontstring(v1, v2); randcontstring(v3, v4);
	v1.unique(string_binary_predicate); v2.unique(string_binary_predicate); test_containers(v1, v2);
	v1.merge(v3); v2.merge(v4); test_containers(v1, v2); test_containers(v3, v4);
	randcontstring(v3, v4);
	v1.merge(v3, string_binary_predicate); v2.merge(v4, string_binary_predicate);
	test_containers(v1, v2); test_containers(v3, v4);
	randcontstring(v3, v4); v1.sort(); v2.sort(); v3.sort(string_binary_predicate); v4.sort(string_binary_predicate);
	test_containers(v1, v2); test_containers(v3, v4);
	v1.reverse(); v2.reverse(); test_containers(v1, v2);

	std::cout << "[Non-member function overloads] ";
	randcontstring(v1, v2);
	std::list<std::string> v9(v1); ft::List<std::string> v10(v2); test_containers(v9, v10);
	bool r1 = (v1 == v9); bool r2 = (v2 == v10); test_values(r1, r2);
	r1 = (v1 == v3); r2 = (v2 == v4); test_values(r1, r2);
	r1 = (v1 < v3); r2 = (v2 < v4); test_values(r1, r2);
	r1 = (v1 > v3); r2 = (v2 > v4); test_values(r1, r2);
	r1 = (v1 >= v9); r2 = (v2 >= v10); test_values(r1, r2);
	r1 = (v1 <= v3); r2 = (v2 <= v4); test_values(r1, r2);
	ft::swap(v3, v1); ft::swap(v4, v2); test_containers(v3, v4); test_containers(v1, v2);
	std::cout << std::endl;
}

void test_stack_int()
{
	std::cout << std::endl << "😨 [Stack <int> test] ";

	std::cout << "[Constructors] ";
	std::stack<int, std::vector<int> > s1; ft::Stack<int> s2; test_stacks(s1, s2);
	std::vector<int> v1; ft::Vector<int> v2; randcontint(v1, v2);
	std::stack<int, std::vector<int> > s3(v1); ft::Stack<int> s4(v2); test_stacks(s3, s4);

	std::cout << "[empty] ";
	test_values(s1.empty(), s2.empty());
	test_values(s3.empty(), s4.empty());
	test_values(std::stack<int, std::vector<int> >().empty(), ft::Stack<int>().empty());

	std::cout << "[size] ";
	test_values(s1.size(), s2.size());
	test_values(s3.size(), s4.size());
	test_values(std::stack<int, std::vector<int> >().size(), ft::Stack<int>().size());

	std::cout << "[top] ";
	test_values(s3.top(), s4.top());
	randcontint(v1, v2);
	s1 = std::stack<int, std::vector<int> >(v1); s2 = ft::Stack<int>(v2);
	test_values(s1.top(), s2.top()); test_values(s3.top(), s4.top());

	std::cout << "[push] ";
	s1.push(5); s2.push(5); s1.push(1); s2.push(1);
	s3.push(10); s4.push(10); s3.push(100); s4.push(100);
	test_values(s2.top(), 1); test_values(s4.top(), 100);
	test_values(s1.top(), s2.top()); test_values(s3.top(), s4.top());

	std::cout << "[pop] ";
	s1.pop(); s2.pop(); s3.pop(); s4.pop();
	test_values(s2.top(), 5); test_values(s4.top(), 10);
	test_values(s1.top(), s2.top()); test_values(s3.top(), s4.top());
	s1.pop(); s2.pop(); s3.pop(); s4.pop();
	s1.pop(); s2.pop(); s3.pop(); s4.pop();
	s1.pop(); s2.pop(); s3.pop(); s4.pop();
	test_values(s1.top(), s2.top()); test_values(s3.top(), s4.top());

	std::cout << "[Operators] ";
	std::stack<int, std::vector<int> > s5(s1); ft::Stack<int> s6(s2);
	bool r1, r2;
	r1 = (s1 == s5); r2 = (s2 == s6); test_values(r1, r2);
	r1 = (s3 == s5); r2 = (s4 == s6); test_values(r1, r2);
	r1 = (s3 != s5); r2 = (s4 != s6); test_values(r1, r2);
	r1 = (s3 != s5); r2 = (s4 != s6); test_values(r1, r2);
	r1 = (s3 < s5); r2 = (s4 < s6); test_values(r1, r2);
	r1 = (s1 > s5); r2 = (s2 > s6); test_values(r1, r2);
	r1 = (s1 <= s5); r2 = (s2 <= s6); test_values(r1, r2);
	r1 = (s3 >= s5); r2 = (s4 >= s6); test_values(r1, r2);

	std::cout << std::endl;
}

void test_stack_string()
{
	std::cout << std::endl << "😨 [Stack <std::string> test] ";

	std::cout << "[Constructors] ";
	std::stack<std::string, std::vector<std::string> > s1; ft::Stack<std::string> s2; test_stacks(s1, s2);
	std::vector<std::string> v1; ft::Vector<std::string> v2; randcontstring(v1, v2);
	std::stack<std::string, std::vector<std::string> > s3(v1); ft::Stack<std::string> s4(v2); test_stacks(s3, s4);

	std::cout << "[empty] ";
	test_values(s1.empty(), s2.empty());
	test_values(s3.empty(), s4.empty());
	test_values(std::stack<std::string, std::vector<std::string> >().empty(), ft::Stack<std::string>().empty());

	std::cout << "[size] ";
	test_values(s1.size(), s2.size());
	test_values(s3.size(), s4.size());
	test_values(std::stack<std::string, std::vector<std::string> >().size(), ft::Stack<std::string>().size());

	std::cout << "[top] ";
	test_values(s3.top(), s4.top());
	randcontstring(v1, v2);
	s1 = std::stack<std::string, std::vector<std::string> >(v1); s2 = ft::Stack<std::string>(v2);
	test_values(s1.top(), s2.top()); test_values(s3.top(), s4.top());

	std::cout << "[push] ";
	s1.push("5"); s2.push("5"); s1.push("1"); s2.push("1");
	s3.push("10"); s4.push("10"); s3.push("100"); s4.push("100");
	test_values(s2.top(), std::string("1")); test_values(s4.top(), std::string("100"));
	test_values(s1.top(), s2.top()); test_values(s3.top(), s4.top());

	std::cout << "[pop] ";
	s1.pop(); s2.pop(); s3.pop(); s4.pop();
	test_values(s2.top(), std::string("5")); test_values(s4.top(), std::string("10"));
	test_values(s1.top(), s2.top()); test_values(s3.top(), s4.top());
	s1.pop(); s2.pop(); s3.pop(); s4.pop();
	s1.pop(); s2.pop(); s3.pop(); s4.pop();
	s1.pop(); s2.pop(); s3.pop(); s4.pop();
	test_values(s1.top(), s2.top()); test_values(s3.top(), s4.top());

	std::cout << "[Operators] ";
	std::stack<std::string, std::vector<std::string> > s5(s1); ft::Stack<std::string> s6(s2);
	bool r1, r2;
	r1 = (s1 == s5); r2 = (s2 == s6); test_values(r1, r2);
	r1 = (s3 == s5); r2 = (s4 == s6); test_values(r1, r2);
	r1 = (s3 != s5); r2 = (s4 != s6); test_values(r1, r2);
	r1 = (s3 != s5); r2 = (s4 != s6); test_values(r1, r2);
	r1 = (s3 < s5); r2 = (s4 < s6); test_values(r1, r2);
	r1 = (s1 > s5); r2 = (s2 > s6); test_values(r1, r2);
	r1 = (s1 <= s5); r2 = (s2 <= s6); test_values(r1, r2);
	r1 = (s3 >= s5); r2 = (s4 >= s6); test_values(r1, r2);

	std::cout << std::endl;
}

void test_queue_int()
{
	std::cout << std::endl << "😰 [Queue <int> test] ";

	std::cout << "[Constructors] ";
	std::queue<int, std::list<int> > s1; ft::Queue<int> s2; test_queues(s1, s2);
	std::list<int> v1; ft::List<int> v2; randcontint(v1, v2);
	std::queue<int, std::list<int> > s3(v1); ft::Queue<int> s4(v2); test_queues(s3, s4);

	std::cout << "[empty] ";
	test_values(s1.empty(), s2.empty());
	test_values(s3.empty(), s4.empty());
	test_values(std::queue<int, std::list<int> >().empty(), ft::Queue<int>().empty());

	std::cout << "[size] ";
	test_values(s1.size(), s2.size());
	test_values(s3.size(), s4.size());
	test_values(std::queue<int, std::list<int> >().size(), ft::Queue<int>().size());

	std::cout << "[front] ";
	test_values(s3.front(), s4.front());
	randcontint(v1, v2);
	s1 = std::queue<int, std::list<int> >(v1); s2 = ft::Queue<int>(v2);
	test_values(s1.front(), s2.front()); test_values(s3.front(), s4.front());

	std::cout << "[back] ";
	test_values(s3.back(), s4.back());
	randcontint(v1, v2);
	s1 = std::queue<int, std::list<int> >(v1); s2 = ft::Queue<int>(v2);
	test_values(s1.back(), s2.back()); test_values(s3.back(), s4.back());

	std::cout << "[push] ";
	s1 = std::queue<int, std::list<int> >(); s2 = ft::Queue<int>();
	s1.push(5); s2.push(5); s1.push(1); s2.push(1);
	s3.push(10); s4.push(10); s3.push(100); s4.push(100);
	test_values(s2.front(), 5); test_values(s2.back(), 1); test_values(s4.back(), 100);
	test_values(s1.front(), s2.front()); test_values(s3.front(), s4.front());
	test_values(s1.back(), s2.back()); test_values(s3.back(), s4.back());

	std::cout << "[pop] ";
	s1.pop(); s2.pop(); s3.pop(); s4.pop();
	test_values(s2.back(), 1); test_values(s4.back(), 100);
	test_values(s1.front(), s2.front()); test_values(s3.front(), s4.front());
	test_values(s1.back(), s2.back()); test_values(s3.back(), s4.back());

	std::cout << "[Operators] ";
	std::queue<int, std::list<int> > s5(s1); ft::Queue<int> s6(s2);
	bool r1, r2;
	r1 = (s1 == s5); r2 = (s2 == s6); test_values(r1, r2);
	r1 = (s3 == s5); r2 = (s4 == s6); test_values(r1, r2);
	r1 = (s3 != s5); r2 = (s4 != s6); test_values(r1, r2);
	r1 = (s3 != s5); r2 = (s4 != s6); test_values(r1, r2);
	r1 = (s3 < s5); r2 = (s4 < s6); test_values(r1, r2);
	r1 = (s1 > s5); r2 = (s2 > s6); test_values(r1, r2);
	r1 = (s1 <= s5); r2 = (s2 <= s6); test_values(r1, r2);
	r1 = (s3 >= s5); r2 = (s4 >= s6); test_values(r1, r2);

	std::cout << std::endl;
}

void test_queue_string()
{
	std::cout << std::endl << "😰 [Queue <std::string> test] ";

	std::cout << "[Constructors] ";
	std::queue<std::string, std::list<std::string> > s1; ft::Queue<std::string> s2; test_queues(s1, s2);
	std::list<std::string> v1; ft::List<std::string> v2; randcontstring(v1, v2);
	std::queue<std::string, std::list<std::string> > s3(v1); ft::Queue<std::string> s4(v2); test_queues(s3, s4);

	std::cout << "[empty] ";
	test_values(s1.empty(), s2.empty());
	test_values(s3.empty(), s4.empty());
	test_values(std::queue<std::string, std::list<std::string> >().empty(), ft::Queue<std::string>().empty());

	std::cout << "[size] ";
	test_values(s1.size(), s2.size());
	test_values(s3.size(), s4.size());
	test_values(std::queue<std::string, std::list<std::string> >().size(), ft::Queue<std::string>().size());

	std::cout << "[front] ";
	test_values(s3.front(), s4.front());
	randcontstring(v1, v2);
	s1 = std::queue<std::string, std::list<std::string> >(v1); s2 = ft::Queue<std::string>(v2);
	test_values(s1.front(), s2.front()); test_values(s3.front(), s4.front());

	std::cout << "[back] ";
	test_values(s3.back(), s4.back());
	randcontstring(v1, v2);
	s1 = std::queue<std::string, std::list<std::string> >(v1); s2 = ft::Queue<std::string>(v2);
	test_values(s1.back(), s2.back()); test_values(s3.back(), s4.back());

	std::cout << "[push] ";
	s1 = std::queue<std::string, std::list<std::string> >(); s2 = ft::Queue<std::string>();
	s1.push("5"); s2.push("5"); s1.push("1"); s2.push("1");
	s3.push("10"); s4.push("10"); s3.push("100"); s4.push("100");
	test_values(s2.front(), std::string("5")); test_values(s2.back(), std::string("1")); test_values(s4.back(), std::string("100"));
	test_values(s1.front(), s2.front()); test_values(s3.front(), s4.front());
	test_values(s1.back(), s2.back()); test_values(s3.back(), s4.back());

	std::cout << "[pop] ";
	s1.pop(); s2.pop(); s3.pop(); s4.pop();
	test_values(s2.back(), std::string("1")); test_values(s4.back(), std::string("100"));
	test_values(s1.front(), s2.front()); test_values(s3.front(), s4.front());
	test_values(s1.back(), s2.back()); test_values(s3.back(), s4.back());

	std::cout << "[Operators] ";
	std::queue<std::string, std::list<std::string> > s5(s1); ft::Queue<std::string> s6(s2);
	bool r1, r2;
	r1 = (s1 == s5); r2 = (s2 == s6); test_values(r1, r2);
	r1 = (s3 == s5); r2 = (s4 == s6); test_values(r1, r2);
	r1 = (s3 != s5); r2 = (s4 != s6); test_values(r1, r2);
	r1 = (s3 != s5); r2 = (s4 != s6); test_values(r1, r2);
	r1 = (s3 < s5); r2 = (s4 < s6); test_values(r1, r2);
	r1 = (s1 > s5); r2 = (s2 > s6); test_values(r1, r2);
	r1 = (s1 <= s5); r2 = (s2 <= s6); test_values(r1, r2);
	r1 = (s3 >= s5); r2 = (s4 >= s6); test_values(r1, r2);

	std::cout << std::endl;
}

void test_map_int()
{
	std::cout << std::endl << "😱 [Map <int> test] ";

	std::cout << "[Constructors (and operator[])] ";
	std::map<int,int> m1; ft::Map<int,int> m2; test_maps(m1, m2);
	randmapint(m1,m2);
	std::map<int,int> m3(m1.begin(), m1.end()); ft::Map<int,int> m4(m2.begin(), m2.end()); test_maps(m3, m4);
	m3 = std::map<int,int>(++m1.begin(), --m1.end()); m4 = ft::Map<int,int>(++m2.begin(), --m2.end()); test_maps(m3, m4);
	m3 = std::map<int,int>(m1.end(), m1.end()); m4 = ft::Map<int,int>(m2.end(), m2.end()); test_maps(m3, m4);
	m3 = std::map<int,int>(m1); m4 = ft::Map<int,int>(m2); test_maps(m3, m4);

	std::cout << "[Iterators] ";
	randmapint(m1,m2);
	std::map<int,int>::iterator it1 = m1.begin(); ft::Map<int,int>::iterator it2 = m2.begin();
	test_values(it1->first, it2->first); test_values(it1->second, it2->second);
	test_values((++it1)->first, (++it2)->first); test_values((it1++)->second, (it2++)->second);
	std::map<int,int>::iterator it3 = --m1.end(); ft::Map<int,int>::iterator it4 = --m2.end();
	test_values(it1->first, it2->first); test_values(it1->second, it2->second);
	bool r1 = (it1 == it3); bool r2 = (it2 == it4); test_values(r1, r2);
	it3 = it1; it4 = it2;
	r1 = (it1 != it3); r2 = (it2 != it4); test_values(r1, r2);
	std::map<int,int>::const_iterator it5 = m1.begin(); ft::Map<int,int>::const_iterator it6 = m2.begin();
	test_values(it5->first, it6->first); test_values(it5->second, it6->second);
	test_values((++++it5)->first, (++++it6)->first); test_values((it5++++)->second, (it6++++)->second);
	test_values((--it5)->second, (--it6)->second);
	std::map<int,int>::reverse_iterator it7(m1.rbegin()); ft::Map<int,int>::reverse_iterator it8(m2.rbegin());
	test_values(it7->first, it8->first); test_values(it7->second, it8->second);
	test_values((++++it7)->first, (++++it8)->first); test_values((it7++++)->second, (it8++++)->second);
	test_values((--it7)->second, (--it8)->second);
	std::map<int,int>::const_reverse_iterator it9 = ++m1.rend(); ft::Map<int,int>::const_reverse_iterator it10 = ++m2.rend();
	test_values(it9->first, it10->first); test_values(it9->second, it10->second);
	test_values((++++it9)->first, (++++it10)->first); test_values((it9++++)->second, (it10++++)->second);
	test_values((--it9)->second, (--it10)->second);

	std::cout << "[Capacity] ";
	randmapint(m1,m2); m3 = std::map<int,int>(); m4 = ft::Map<int,int>();
	test_values(m1.empty(), m2.empty()); test_values(m3.empty(), m4.empty());
	test_values(m1.size(), m2.size()); test_values(m3.size(), m4.size());
	test_values(m1.max_size(), m2.max_size()); test_values(m3.max_size(), m4.max_size());

	std::cout << "[Element access] ";
	test_values(m1[5], m2[5]); test_values(m3[5], m4[5]);
	test_values(m1[5], m2[5]); test_values(m3[5], m4[5]);
	m1[5] = 123; m2[5] = 123; m3[5] = 123; m4[5] = 123;
	test_values(m1[5], m2[5]); test_values(m3[5], m4[5]);

	std::cout << "[Modifiers] ";
	m1.insert(std::pair<int,int>(123, 456)); m2.insert(ft::Pair<int,int>(123, 456)); test_maps(m1, m2);
	m1.insert(std::pair<int,int>(123, 789)); m2.insert(ft::Pair<int,int>(123, 789)); test_maps(m1, m2);
	m1.insert(++++m1.begin(), std::pair<int,int>(345, 789)); m2.insert(++++m2.begin(), ft::Pair<int,int>(345, 789)); test_maps(m1, m2);
	m3.insert(++m1.begin(), --m1.end()); m4.insert(++m2.begin(), --m2.end()); test_maps(m3, m4);
	m3.insert(++m1.begin(), --m1.end()); m4.insert(++m2.begin(), --m2.end()); test_maps(m3, m4);
	m1.erase(++m1.begin()); m2.erase(++m2.begin()); test_maps(m1, m2);
	int r3 = m1.erase(123); int r4 = m2.erase(123); test_maps(m1, m2); test_values(r3, r4);
	r3 = m1.erase(123); r4 = m2.erase(123); test_maps(m1, m2); test_values(r3, r4);
	m1.erase(++m1.begin(), ----m1.end()); m2.erase(++m2.begin(), ----m2.end()); test_maps(m1, m2);
	m1.swap(m3); m2.swap(m4); test_maps(m1, m2); test_maps(m3, m4);
	m1.clear(); m2.clear(); test_maps(m1, m2); test_maps(m3, m4);

	std::cout << "[Observers] ";
	test_values(m3.key_comp()(4,6), m4.key_comp()(4,6));
	test_values(m3.key_comp()(6,6), m4.key_comp()(6,6));
	test_values(m3.value_comp()(*m3.begin(), *(++m3.begin())), m4.value_comp()(*m4.begin(), *(++m4.begin())));
	test_values(m3.value_comp()(*(--m3.end()), *(++m3.begin())), m4.value_comp()(*(--m4.end()), *(++m4.begin())));

	std::cout << "[Operators] ";
	randmapint(m1,m2); m1[123] = 456; m2[123] = 456;
	it1 = m1.find(124); it2 = m2.find(124); test_values(it1->second, it2->second);
	it1 = m1.find(123); it2 = m2.find(123);
	test_values(it1->first, it2->first); test_values(it1->second, it2->second);
	r3 = m1.count(124); r4 = m2.count(124); test_values(r3, r4);
	r3 = m1.count(123); r4 = m2.count(123); test_values(r3, r4);
	it1 = m1.lower_bound(11111); it2 = m2.lower_bound(11111); test_values(it1->second, it2->second);
	it1 = m1.lower_bound(-11111); it2 = m2.lower_bound(-11111); test_values(it1->second, it2->second);
	it1 = m1.upper_bound(11111); it2 = m2.upper_bound(11111); test_values(it1->second, it2->second);
	it1 = m1.upper_bound(-11111); it2 = m2.upper_bound(-11111); test_values(it1->second, it2->second);
	test_values(m1.equal_range(10000).first->second, m2.equal_range(10000).first->second);
	test_values(m1.equal_range(0).first->second, m2.equal_range(0).first->second);
	test_values(m1.equal_range(-10000).first->second, m2.equal_range(-10000).first->second);
	m3 = std::map<int,int>(); m4 = ft::Map<int,int>();
	it1 = m3.lower_bound(11111); it2 = m4.lower_bound(11111); test_values(it1->second, it2->second);
	it1 = m3.upper_bound(-11111); it2 = m4.upper_bound(-11111); test_values(it1->second, it2->second);
	test_values(m3.equal_range(0).first->second, m4.equal_range(0).first->second);

	std::cout << std::endl;
}

void test_map_string()
{
	std::cout << std::endl << "😱 [Map <std::string> test] ";

	std::cout << "[Constructors (and operator[])] ";
	std::map<std::string,std::string> m1; ft::Map<std::string,std::string> m2; test_maps(m1, m2);
	randmapstring(m1,m2);
	std::map<std::string,std::string> m3(m1.begin(), m1.end()); ft::Map<std::string,std::string> m4(m2.begin(), m2.end()); test_maps(m3, m4);
	m3 = std::map<std::string,std::string>(++m1.begin(), --m1.end()); m4 = ft::Map<std::string,std::string>(++m2.begin(), --m2.end()); test_maps(m3, m4);
	m3 = std::map<std::string,std::string>(m1.end(), m1.end()); m4 = ft::Map<std::string,std::string>(m2.end(), m2.end()); test_maps(m3, m4);
	m3 = std::map<std::string,std::string>(m1); m4 = ft::Map<std::string,std::string>(m2); test_maps(m3, m4);

	std::cout << "[Iterators] ";
	randmapstring(m1,m2);
	std::map<std::string,std::string>::iterator it1 = m1.begin(); ft::Map<std::string,std::string>::iterator it2 = m2.begin();
	test_values(it1->first, it2->first); test_values(it1->second, it2->second);
	test_values((++it1)->first, (++it2)->first); test_values((it1++)->second, (it2++)->second);
	std::map<std::string,std::string>::iterator it3 = --m1.end(); ft::Map<std::string,std::string>::iterator it4 = --m2.end();
	test_values(it1->first, it2->first); test_values(it1->second, it2->second);
	bool r1 = (it1 == it3); bool r2 = (it2 == it4); test_values(r1, r2);
	it3 = it1; it4 = it2;
	r1 = (it1 != it3); r2 = (it2 != it4); test_values(r1, r2);
	std::map<std::string,std::string>::const_iterator it5 = m1.begin(); ft::Map<std::string,std::string>::const_iterator it6 = m2.begin();
	test_values(it5->first, it6->first); test_values(it5->second, it6->second);
	test_values((++++it5)->first, (++++it6)->first); test_values((it5++++)->second, (it6++++)->second);
	test_values((--it5)->second, (--it6)->second);
	std::map<std::string,std::string>::reverse_iterator it7(m1.rbegin()); ft::Map<std::string,std::string>::reverse_iterator it8(m2.rbegin());
	test_values(it7->first, it8->first); test_values(it7->second, it8->second);
	test_values((++++it7)->first, (++++it8)->first); test_values((it7++++)->second, (it8++++)->second);
	test_values((--it7)->second, (--it8)->second);
	std::map<std::string,std::string>::const_reverse_iterator it9 = ++m1.rend(); ft::Map<std::string,std::string>::const_reverse_iterator it10 = ++m2.rend();
	test_values(it9->first, it10->first); test_values(it9->second, it10->second);
	test_values((++++it9)->first, (++++it10)->first); test_values((it9++++)->second, (it10++++)->second);
	test_values((--it9)->second, (--it10)->second);

	std::cout << "[Capacity] ";
	randmapstring(m1,m2); m3 = std::map<std::string,std::string>(); m4 = ft::Map<std::string,std::string>();
	test_values(m1.empty(), m2.empty()); test_values(m3.empty(), m4.empty());
	test_values(m1.size(), m2.size()); test_values(m3.size(), m4.size());
	test_values(m1.max_size(), m2.max_size()); test_values(m3.max_size(), m4.max_size());

	std::cout << "[Element access] ";
	test_values(m1["5"], m2["5"]); test_values(m3["5"], m4["5"]);
	test_values(m1["5"], m2["5"]); test_values(m3["5"], m4["5"]);
	m1["5"] = 123; m2["5"] = 123; m3["5"] = 123; m4["5"] = 123;
	test_values(m1["5"], m2["5"]); test_values(m3["5"], m4["5"]);

	std::cout << "[Modifiers] ";
	m1.insert(std::pair<std::string,std::string>("123", "456")); m2.insert(ft::Pair<std::string,std::string>("123", "456")); test_maps(m1, m2);
	m1.insert(std::pair<std::string,std::string>("123", "789")); m2.insert(ft::Pair<std::string,std::string>("123", "789")); test_maps(m1, m2);
	m1.insert(++++m1.begin(), std::pair<std::string,std::string>("345", "789")); m2.insert(++++m2.begin(), ft::Pair<std::string,std::string>("345", "789")); test_maps(m1, m2);
	m3.insert(++m1.begin(), --m1.end()); m4.insert(++m2.begin(), --m2.end()); test_maps(m3, m4);
	m3.insert(++m1.begin(), --m1.end()); m4.insert(++m2.begin(), --m2.end()); test_maps(m3, m4);
	m1.erase(++m1.begin()); m2.erase(++m2.begin()); test_maps(m1, m2);
	int r3 = m1.erase("123"); int r4 = m2.erase("123"); test_maps(m1, m2); test_values(r3, r4);
	r3 = m1.erase("123"); r4 = m2.erase("123"); test_maps(m1, m2); test_values(r3, r4);
	m1.erase(++m1.begin(), ----m1.end()); m2.erase(++m2.begin(), ----m2.end()); test_maps(m1, m2);
	m1.swap(m3); m2.swap(m4); test_maps(m1, m2); test_maps(m3, m4);
	m1.clear(); m2.clear(); test_maps(m1, m2); test_maps(m3, m4);

	std::cout << "[Observers] ";
	test_values(m3.key_comp()("4","6"), m4.key_comp()("4","6"));
	test_values(m3.key_comp()("6","6"), m4.key_comp()("6","6"));
	test_values(m3.value_comp()(*m3.begin(), *(++m3.begin())), m4.value_comp()(*m4.begin(), *(++m4.begin())));
	test_values(m3.value_comp()(*(--m3.end()), *(++m3.begin())), m4.value_comp()(*(--m4.end()), *(++m4.begin())));

	std::cout << "[Operators] ";
	randmapstring(m1,m2); m1["123"] = "456"; m2["123"] = "456";
	it1 = m1.find("123"); it2 = m2.find("123");
	test_values(it1->first, it2->first); test_values(it1->second, it2->second);
	r3 = m1.count("124"); r4 = m2.count("124"); test_values(r3, r4);
	r3 = m1.count("123"); r4 = m2.count("123"); test_values(r3, r4);
	it1 = m1.lower_bound("11111"); it2 = m2.lower_bound("11111"); test_values(it1->second, it2->second);
	it1 = m1.lower_bound("-11111"); it2 = m2.lower_bound("-11111"); test_values(it1->second, it2->second);
	it1 = m1.upper_bound("11111"); it2 = m2.upper_bound("11111"); test_values(it1->second, it2->second);
	it1 = m1.upper_bound("-11111"); it2 = m2.upper_bound("-11111"); test_values(it1->second, it2->second);
	test_values(m1.equal_range("10000").first->second, m2.equal_range("10000").first->second);
	test_values(m1.equal_range("0").first->second, m2.equal_range("0").first->second);
	test_values(m1.equal_range("-10000").first->second, m2.equal_range("-10000").first->second);

	std::cout << std::endl;
}

void test_deque_int()
{
	std::cout << std::endl << "😤 [Deque <int> test] ";

	std::cout << "[Constructors] ";
	std::deque<int> v1; ft::Deque<int> v2; test_deques(v1, v2);
	v1 = std::deque<int>(10); v2 = ft::Deque<int>(10); test_deques(v1, v2);
	v1 = std::deque<int>(100, 123); v2 = ft::Deque<int>(100, 123); test_deques(v1, v2);
	std::deque<int> v3(v1.begin(), v1.end()); ft::Deque<int> v4(v2.begin(), v2.end()); test_deques(v3, v4);
	v1 = std::deque<int>(v3); v2 = ft::Deque<int>(v4); test_deques(v1, v2);
	randdequeint(v1, v2); v3 = v1; v4 = v2; test_deques(v3, v4);

	std::cout << "[Iterators] ";
	std::deque<int>::iterator it1 = v1.begin(); ft::Deque<int>::iterator it2 = v2.begin(); test_values(*it1, *it2);
	it1 = --v1.end(); it2 = --v2.end(); test_values(*it1, *it2);
	it1--; it2--; test_values(*it1, *it2);
	it1 -= 5; it2 -= 5; test_values(*it1, *it2);
	*it1 = -1234; *it2 = -1234; test_values(*it1, *it2);
	it1 += 2; it2 += 2; test_values(*it1, *it2);
	std::deque<int>::iterator it5 = v1.begin(); ft::Deque<int>::iterator it6 = v2.begin();
	test_values(it1 - it5, it2 - it6); test_values(++it5 - it1++, ++it6 - it2++);
	test_values(it1[1], it2[1]); it1[1] = 5; it2[1] = 5; test_values(*(++it1), *(++it2));
	std::deque<int>::const_iterator it3 = v1.begin(); ft::Deque<int>::const_iterator it4 = v2.begin(); test_values(*it3, *it4);
	std::deque<int> const v5(10, 10); ft::Deque<int> const v6(10, 10);
	it3 = v5.begin(); it4 = v6.begin(); test_values(*it3, *it4);
	it3 = v5.end(); it4 = v6.end(); test_values(*--it3, *--it4);
	test_values(it3[-3], it4[-3]);
	std::deque<int>::reverse_iterator it7(v1.rbegin()); ft::Deque<int>::reverse_iterator it8(v2.rbegin());
	test_values(*it7, *it8); test_values(it7 - it7, it8 - it8); test_values(*(it7 + 5), *(it8 + 5));
	test_values(it7[3], it8[3]); it7[3] = 6; it8[3] = 6; test_values(it7[3], it8[3]);
	std::deque<int>::const_reverse_iterator it9 = it7; ft::Deque<int>::const_reverse_iterator it10 = it8;
	test_values(*it9, *it10); test_values(*it7, *it9); test_values(*(++it9), *(++it10));

	std::cout << "[Capacity] ";
	test_values(v1.size(), v2.size()); test_values(v3.size(), v4.size()); test_values(v5.size(), v6.size());
	v1 = std::deque<int>(); v2 = ft::Deque<int>(); test_values(v1.size(), v2.size());
	v1.push_back(0); v2.push_back(0); test_values(v1.size(), v2.size());
	test_values(v1.max_size(), v2.max_size());
	test_values(std::deque<int>().max_size(), ft::Deque<int>().max_size());
	test_values(std::deque<int>(1000).max_size(), ft::Deque<int>(1000).max_size());
	v1.resize(50); v2.resize(50); test_deques(v1, v2); test_values(v1.size(), v2.size());
	v1.resize(150); v2.resize(150); test_deques(v1, v2); test_values(v1.size(), v2.size());
	v1.resize(200, 222); v2.resize(200, 222); test_deques(v1, v2); test_values(v1.size(), v2.size());
	std::deque<int> v7(100, 100); ft::Deque<int> v8(100, 100); test_values(v7.empty(), v8.empty());
	v7 = std::deque<int>(); v8 = ft::Deque<int>(); test_values(v7.empty(), v8.empty());
	
	std::cout << "[Element access] ";
	randdequeint(v1, v2); test_values(v1[0], v2[0]);
	v1[0] = 100500; v2[0] = 100500; test_values(v1[0], v2[0]);
	test_values(v1.at(1), v2.at(1));
	std::string e1, e2;
	try { v1.at(-1); } catch(std::exception &e) { e1 = std::string(e.what()); }
	try { v2.at(-1); } catch(std::exception &e) { e2 = std::string(e.what()); }
	if (e1.empty() == false && e2.empty() == false) test_values(e1, e2);
	test_values(v1.front(), v2.front()); test_values(v1.back(), v2.back());
	test_values(v3.front(), v4.front()); test_values(v3.back(), v4.back());

	std::cout << "[Modifiers] ";
	v3.assign(++v1.begin(), --v1.end()); v4.assign(++v2.begin(), --v2.end()); test_deques(v3, v4);
	v3.assign(6, 666); v4.assign(6, 666); test_deques(v3, v4);
	v3.assign(0, 666); v4.assign(0, 666); test_deques(v3, v4);
	v3.push_back(777); v4.push_back(777); test_deques(v3, v4);
	v1.pop_back(); v2.pop_back(); test_deques(v1, v2);
	v3.push_front(777); v4.push_front(777); test_deques(v3, v4);
	v1.pop_front(); v2.pop_front(); test_deques(v1, v2);
	v1.insert(--v1.end(), 888); v2.insert(--v2.end(), 888); test_deques(v1, v2);
	v1.insert(--v1.end(), 9, 999); v2.insert(--v2.end(), 9, 999); test_deques(v1, v2);
	v3.insert(v3.end(), v1.begin(), v1.end()); v4.insert(v4.end(), v2.begin(), v2.end()); test_deques(v3, v4);
	v3.erase(++v3.begin()); v4.erase(++v4.begin()); test_deques(v3, v4);
	v3.erase(++v3.begin(), ++++v3.begin()); v4.erase(++v4.begin(), ++++v4.begin()); test_deques(v3, v4);
	v1.swap(v3); v2.swap(v4); test_deques(v1, v2); test_deques(v3, v4);
	v3.clear(); v4.clear(); test_deques(v3, v4);

	std::cout << "[Non-member function overloads] ";
	randdequeint(v1, v2);
	std::deque<int> v9(v1); ft::Deque<int> v10(v2); test_deques(v9, v10);
	bool r1 = (v1 == v9); bool r2 = (v2 == v10); test_values(r1, r2);
	r1 = (v1 == v3); r2 = (v2 == v4); test_values(r1, r2);
	r1 = (v1 < v3); r2 = (v2 < v4); test_values(r1, r2);
	r1 = (v1 > v3); r2 = (v2 > v4); test_values(r1, r2);
	r1 = (v1 >= v9); r2 = (v2 >= v10); test_values(r1, r2);
	r1 = (v1 <= v3); r2 = (v2 <= v4); test_values(r1, r2);
	ft::swap(v3, v1); ft::swap(v4, v2); test_deques(v3, v4); test_deques(v1, v2);

	std::cout << std::endl;
}

void test_deque_string()
{
	std::cout << std::endl << "😤 [Deque <std::string> test] ";

	std::cout << "[Constructors] ";
	std::deque<std::string> v1; ft::Deque<std::string> v2; test_deques(v1, v2);
	v1 = std::deque<std::string>(10); v2 = ft::Deque<std::string>(10); test_deques(v1, v2);
	v1 = std::deque<std::string>(100, "123"); v2 = ft::Deque<std::string>(100, "123"); test_deques(v1, v2);
	std::deque<std::string> v3(v1.begin(), v1.end()); ft::Deque<std::string> v4(v2.begin(), v2.end()); test_deques(v3, v4);
	v1 = std::deque<std::string>(v3); v2 = ft::Deque<std::string>(v4); test_deques(v1, v2);
	randdequestring(v1, v2); v3 = v1; v4 = v2; test_deques(v3, v4);

	std::cout << "[Iterators] ";
	std::deque<std::string>::iterator it1 = v1.begin(); ft::Deque<std::string>::iterator it2 = v2.begin(); test_values(*it1, *it2);
	it1 = --v1.end(); it2 = --v2.end(); test_values(*it1, *it2);
	it1--; it2--; test_values(*it1, *it2);
	it1 -= 5; it2 -= 5; test_values(*it1, *it2);
	*it1 = "-1234"; *it2 = "-1234"; test_values(*it1, *it2);
	it1 += 2; it2 += 2; test_values(*it1, *it2);
	std::deque<std::string>::iterator it5 = v1.begin(); ft::Deque<std::string>::iterator it6 = v2.begin();
	test_values(it1 - it5, it2 - it6); test_values(++it5 - it1++, ++it6 - it2++);
	test_values(it1[1], it2[1]); it1[1] = 5; it2[1] = 5; test_values(*(++it1), *(++it2));
	std::deque<std::string>::const_iterator it3 = v1.begin(); ft::Deque<std::string>::const_iterator it4 = v2.begin(); test_values(*it3, *it4);
	std::deque<std::string> const v5(10, "10"); ft::Deque<std::string> const v6(10, "10");
	it3 = v5.begin(); it4 = v6.begin(); test_values(*it3, *it4);
	it3 = v5.end(); it4 = v6.end(); test_values(*--it3, *--it4);
	test_values(it3[-3], it4[-3]);
	std::deque<std::string>::reverse_iterator it7(v1.rbegin()); ft::Deque<std::string>::reverse_iterator it8(v2.rbegin());
	test_values(*it7, *it8); test_values(it7 - it7, it8 - it8); test_values(*(it7 + 5), *(it8 + 5));
	test_values(it7[3], it8[3]); it7[3] = "6"; it8[3] = "6"; test_values(it7[3], it8[3]);
	std::deque<std::string>::const_reverse_iterator it9 = it7; ft::Deque<std::string>::const_reverse_iterator it10 = it8;
	test_values(*it9, *it10); test_values(*it7, *it9); test_values(*(++it9), *(++it10));

	std::cout << "[Capacity] ";
	test_values(v1.size(), v2.size()); test_values(v3.size(), v4.size()); test_values(v5.size(), v6.size());
	v1 = std::deque<std::string>(); v2 = ft::Deque<std::string>(); test_values(v1.size(), v2.size());
	v1.push_back("0"); v2.push_back("0"); test_values(v1.size(), v2.size());
	test_values(v1.max_size(), v2.max_size());
	test_values(std::deque<std::string>().max_size(), ft::Deque<std::string>().max_size());
	test_values(std::deque<std::string>(1000).max_size(), ft::Deque<std::string>(1000).max_size());
	v1.resize(50); v2.resize(50); test_deques(v1, v2); test_values(v1.size(), v2.size());
	v1.resize(150); v2.resize(150); test_deques(v1, v2); test_values(v1.size(), v2.size());
	v1.resize(200, "222"); v2.resize(200, "222"); test_deques(v1, v2); test_values(v1.size(), v2.size());
	std::deque<std::string> v7(100, "100"); ft::Deque<std::string> v8(100, "100"); test_values(v7.empty(), v8.empty());
	v7 = std::deque<std::string>(); v8 = ft::Deque<std::string>(); test_values(v7.empty(), v8.empty());
	
	std::cout << "[Element access] ";
	randdequestring(v1, v2); test_values(v1[0], v2[0]);
	v1[0] = "100500"; v2[0] = "100500"; test_values(v1[0], v2[0]);
	test_values(v1.at(1), v2.at(1));
	std::string e1, e2;
	try { v1.at(-1); } catch(std::exception &e) { e1 = std::string(e.what()); }
	try { v2.at(-1); } catch(std::exception &e) { e2 = std::string(e.what()); }
	if (e1.empty() == false && e2.empty() == false) test_values(e1, e2);
	test_values(v1.front(), v2.front()); test_values(v1.back(), v2.back());
	test_values(v3.front(), v4.front()); test_values(v3.back(), v4.back());

	std::cout << "[Modifiers] ";
	v3.assign(++v1.begin(), --v1.end()); v4.assign(++v2.begin(), --v2.end()); test_deques(v3, v4);
	v3.assign(6, "666"); v4.assign(6, "666"); test_deques(v3, v4);
	v3.assign(0, "666"); v4.assign(0, "666"); test_deques(v3, v4);
	v3.push_back("777"); v4.push_back("777"); test_deques(v3, v4);
	v1.pop_back(); v2.pop_back(); test_deques(v1, v2);
	v3.push_front("777"); v4.push_front("777"); test_deques(v3, v4);
	v1.pop_front(); v2.pop_front(); test_deques(v1, v2);
	v1.insert(--v1.end(), "888"); v2.insert(--v2.end(), "888"); test_deques(v1, v2);
	v1.insert(--v1.end(), 9, "999"); v2.insert(--v2.end(), 9, "999"); test_deques(v1, v2);
	v3.insert(v3.end(), v1.begin(), v1.end()); v4.insert(v4.end(), v2.begin(), v2.end()); test_deques(v3, v4);
	v3.erase(++v3.begin()); v4.erase(++v4.begin()); test_deques(v3, v4);
	v3.erase(++v3.begin(), ++++v3.begin()); v4.erase(++v4.begin(), ++++v4.begin()); test_deques(v3, v4);
	v1.swap(v3); v2.swap(v4); test_deques(v1, v2); test_deques(v3, v4);
	v3.clear(); v4.clear(); test_deques(v3, v4);

	std::cout << "[Non-member function overloads] ";
	randdequestring(v1, v2);
	std::deque<std::string> v9(v1); ft::Deque<std::string> v10(v2); test_deques(v9, v10);
	bool r1 = (v1 == v9); bool r2 = (v2 == v10); test_values(r1, r2);
	r1 = (v1 == v3); r2 = (v2 == v4); test_values(r1, r2);
	r1 = (v1 < v3); r2 = (v2 < v4); test_values(r1, r2);
	r1 = (v1 > v3); r2 = (v2 > v4); test_values(r1, r2);
	r1 = (v1 >= v9); r2 = (v2 >= v10); test_values(r1, r2);
	r1 = (v1 <= v3); r2 = (v2 <= v4); test_values(r1, r2);
	ft::swap(v3, v1); ft::swap(v4, v2); test_deques(v3, v4); test_deques(v1, v2);

	std::cout << std::endl;
}

void test_set_int()
{
	std::cout << std::endl << "😠 [Set <int> test] ";

	std::cout << "[Constructors] ";
	std::set<int> m1; ft::Set<int> m2; test_sets(m1, m2);
	randsetint(m1,m2);
	std::set<int> m3(m1.begin(), m1.end()); ft::Set<int> m4(m2.begin(), m2.end()); test_sets(m3, m4);
	m3 = std::set<int>(++m1.begin(), --m1.end()); m4 = ft::Set<int>(++m2.begin(), --m2.end()); test_sets(m3, m4);
	m3 = std::set<int>(m1.end(), m1.end()); m4 = ft::Set<int>(m2.end(), m2.end()); test_sets(m3, m4);
	m3 = std::set<int>(m1); m4 = ft::Set<int>(m2); test_sets(m3, m4);

	std::cout << "[Iterators] ";
	randsetint(m1,m2);
	std::set<int>::iterator it1 = m1.begin(); ft::Set<int>::iterator it2 = m2.begin();
	test_values(*it1, *it2);
	test_values(*(++it1), *(++it2)); test_values(*(it1++), *(it2++));
	std::set<int>::iterator it3 = --m1.end(); ft::Set<int>::iterator it4 = --m2.end();
	test_values(*it1, *it2);
	bool r1 = (it1 == it3); bool r2 = (it2 == it4); test_values(r1, r2);
	it3 = it1; it4 = it2;
	r1 = (it1 != it3); r2 = (it2 != it4); test_values(r1, r2);
	std::set<int>::const_iterator it5 = m1.begin(); ft::Set<int>::const_iterator it6 = m2.begin();
	test_values(*it5, *it6);
	test_values(*(++++it5), *(++++it6)); test_values(*(it5++++), *(it6++++));
	test_values(*(--it5), *(--it6));
	std::set<int>::reverse_iterator it7(m1.rbegin()); ft::Set<int>::reverse_iterator it8(m2.rbegin());
	test_values(*it7, *it8);
	test_values(*(++++it7), *(++++it8)); test_values(*(it7++++), *(it8++++));
	test_values(*(--it7), *(--it8));
	std::set<int>::const_reverse_iterator it9 = ++m1.rend(); ft::Set<int>::const_reverse_iterator it10 = ++m2.rend();
	test_values(*it9, *it10);
	test_values(*(++++it9), *(++++it10)); test_values(*(it9++++), *(it10++++));
	test_values(*(--it9), *(--it10));

	std::cout << "[Capacity] ";
	randsetint(m1,m2); m3 = std::set<int>(); m4 = ft::Set<int>();
	test_values(m1.empty(), m2.empty()); test_values(m3.empty(), m4.empty());
	test_values(m1.size(), m2.size()); test_values(m3.size(), m4.size());
	test_values(m1.max_size(), m2.max_size()); test_values(m3.max_size(), m4.max_size());

	std::cout << "[Modifiers] ";
	m1 = std::set<int>(); m2 = ft::Set<int>();
	m3 = std::set<int>(); m4 = ft::Set<int>();
	m1.insert(123); m2.insert(123); test_sets(m1, m2);
	m1.insert(123); m2.insert(123); test_sets(m1, m2);
	m1.insert(456); m2.insert(456); test_sets(m1, m2);
	m1.insert(m1.begin(), 345); m2.insert(m2.begin(), 345); test_sets(m1, m2);
	m3.insert(m1.begin(), --m1.end()); m4.insert(m2.begin(), --m2.end()); test_sets(m3, m4);
	m1.erase(m1.begin()); m2.erase(m2.begin()); test_sets(m1, m2);
	int r3, r4;
	r3 = m1.erase(123); r4 = m2.erase(123); test_sets(m1, m2); test_values(r3, r4);
	r3 = m1.erase(123); r4 = m2.erase(123); test_sets(m1, m2); test_values(r3, r4);
	m1.erase(m1.begin(), ++m1.begin()); m2.erase(m2.begin(), ++m2.begin()); test_sets(m1, m2);
	m1.swap(m3); m2.swap(m4); test_sets(m1, m2); test_sets(m3, m4);
	m1.clear(); m2.clear(); test_sets(m1, m2); test_sets(m3, m4);

	std::cout << "[Observers] ";
	test_values(m3.key_comp()(4,6), m4.key_comp()(4,6));
	test_values(m3.key_comp()(6,6), m4.key_comp()(6,6));
	test_values(m3.value_comp()(4,6), m4.value_comp()(4,6));
	test_values(m3.value_comp()(6,6), m4.value_comp()(6,6));

	std::cout << "[Operators] ";
	randsetint(m1,m2); m1.insert(123); m2.insert(123);
	it1 = m1.find(123); it2 = m2.find(123); test_values(*it1, *it2);
	r3 = m1.count(124); r4 = m2.count(124); test_values(r3, r4);
	r3 = m1.count(123); r4 = m2.count(123); test_values(r3, r4);
	m1.insert(100000); m2.insert(100000); m1.insert(100010); m2.insert(100010);
	it1 = m1.lower_bound(100005); it2 = m2.lower_bound(100005); test_values(*it1, *it2);
	it1 = m1.lower_bound(*(++m1.begin())); it2 = m2.lower_bound(*(++m2.begin())); test_values(*it1, *it2);
	it1 = m1.lower_bound(*(--m1.end())); it2 = m2.lower_bound(*(--m2.end())); test_values(*it1, *it2);
	it1 = m1.upper_bound(100005); it2 = m2.upper_bound(100005); test_values(*it1, *it2);
	it1 = m1.upper_bound(*(++m1.begin())); it2 = m2.upper_bound(*(++m2.begin())); test_values(*it1, *it2);
	test_values(*m1.equal_range(*(++++m1.begin())).first, *m2.equal_range(*(++++m2.begin())).first);
	test_values(*m1.equal_range(*(++++m1.begin())).second, *m2.equal_range(*(++++m2.begin())).second);

	std::cout << std::endl;
}

void test_set_string()
{
	std::cout << std::endl << "😠 [Set <std::string> test] ";

	std::cout << "[Constructors] ";
	std::set<std::string> m1; ft::Set<std::string> m2; test_sets(m1, m2);
	randsetstring(m1,m2);
	std::set<std::string> m3(m1.begin(), m1.end()); ft::Set<std::string> m4(m2.begin(), m2.end()); test_sets(m3, m4);
	m3 = std::set<std::string>(++m1.begin(), --m1.end()); m4 = ft::Set<std::string>(++m2.begin(), --m2.end()); test_sets(m3, m4);
	m3 = std::set<std::string>(m1.end(), m1.end()); m4 = ft::Set<std::string>(m2.end(), m2.end()); test_sets(m3, m4);
	m3 = std::set<std::string>(m1); m4 = ft::Set<std::string>(m2); test_sets(m3, m4);

	std::cout << "[Iterators] ";
	randsetstring(m1,m2);
	std::set<std::string>::iterator it1 = m1.begin(); ft::Set<std::string>::iterator it2 = m2.begin();
	test_values(*it1, *it2);
	test_values(*(++it1), *(++it2)); test_values(*(it1++), *(it2++));
	std::set<std::string>::iterator it3 = --m1.end(); ft::Set<std::string>::iterator it4 = --m2.end();
	test_values(*it1, *it2);
	bool r1 = (it1 == it3); bool r2 = (it2 == it4); test_values(r1, r2);
	it3 = it1; it4 = it2;
	r1 = (it1 != it3); r2 = (it2 != it4); test_values(r1, r2);
	std::set<std::string>::const_iterator it5 = m1.begin(); ft::Set<std::string>::const_iterator it6 = m2.begin();
	test_values(*it5, *it6);
	test_values(*(++++it5), *(++++it6)); test_values(*(it5++++), *(it6++++));
	test_values(*(--it5), *(--it6));
	std::set<std::string>::reverse_iterator it7(m1.rbegin()); ft::Set<std::string>::reverse_iterator it8(m2.rbegin());
	test_values(*it7, *it8);
	test_values(*(++++it7), *(++++it8)); test_values(*(it7++++), *(it8++++));
	test_values(*(--it7), *(--it8));
	std::set<std::string>::const_reverse_iterator it9 = ++m1.rend(); ft::Set<std::string>::const_reverse_iterator it10 = ++m2.rend();
	test_values(*it9, *it10);
	test_values(*(++++it9), *(++++it10)); test_values(*(it9++++), *(it10++++));
	test_values(*(--it9), *(--it10));

	std::cout << "[Capacity] ";
	randsetstring(m1,m2); m3 = std::set<std::string>(); m4 = ft::Set<std::string>();
	test_values(m1.empty(), m2.empty()); test_values(m3.empty(), m4.empty());
	test_values(m1.size(), m2.size()); test_values(m3.size(), m4.size());
	test_values(m1.max_size(), m2.max_size()); test_values(m3.max_size(), m4.max_size());

	std::cout << "[Modifiers] ";
	m1 = std::set<std::string>(); m2 = ft::Set<std::string>();
	m3 = std::set<std::string>(); m4 = ft::Set<std::string>();
	m1.insert("123"); m2.insert("123"); test_sets(m1, m2);
	m1.insert("123"); m2.insert("123"); test_sets(m1, m2);
	m1.insert("456"); m2.insert("456"); test_sets(m1, m2);
	m1.insert(m1.begin(), "345"); m2.insert(m2.begin(), "345"); test_sets(m1, m2);
	m3.insert(m1.begin(), --m1.end()); m4.insert(m2.begin(), --m2.end()); test_sets(m3, m4);
	m1.erase(m1.begin()); m2.erase(m2.begin()); test_sets(m1, m2);
	int r3, r4;
	r3 = m1.erase("123"); r4 = m2.erase("123"); test_sets(m1, m2); test_values(r3, r4);
	r3 = m1.erase("123"); r4 = m2.erase("123"); test_sets(m1, m2); test_values(r3, r4);
	m1.erase(m1.begin(), ++m1.begin()); m2.erase(m2.begin(), ++m2.begin()); test_sets(m1, m2);
	m1.swap(m3); m2.swap(m4); test_sets(m1, m2); test_sets(m3, m4);
	m1.clear(); m2.clear(); test_sets(m1, m2); test_sets(m3, m4);

	std::cout << "[Observers] ";
	randsetstring(m1,m2);
	test_values(m3.key_comp()("4","6"), m4.key_comp()("4","6"));
	test_values(m3.key_comp()("6","6"), m4.key_comp()("6","6"));
	test_values(m3.value_comp()("4","6"), m4.value_comp()("4","6"));
	test_values(m3.value_comp()("6","6"), m4.value_comp()("6","6"));

	std::cout << "[Operators] ";
	randsetstring(m1,m2); m1.insert("123"); m2.insert("123");
	it1 = m1.find("123"); it2 = m2.find("123"); test_values(*it1, *it2);
	r3 = m1.count("124"); r4 = m2.count("124"); test_values(r3, r4);
	r3 = m1.count("123"); r4 = m2.count("123"); test_values(r3, r4);
	m1.insert("100000"); m2.insert("100000"); m1.insert("100010"); m2.insert("100010");
	it1 = m1.lower_bound("100005"); it2 = m2.lower_bound("100005"); test_values(*it1, *it2);
	it1 = m1.lower_bound(*(++m1.begin())); it2 = m2.lower_bound(*(++m2.begin())); test_values(*it1, *it2);
	it1 = m1.lower_bound(*(--m1.end())); it2 = m2.lower_bound(*(--m2.end())); test_values(*it1, *it2);
	it1 = m1.upper_bound("100005"); it2 = m2.upper_bound("100005"); test_values(*it1, *it2);
	it1 = m1.upper_bound(*(++m1.begin())); it2 = m2.upper_bound(*(++m2.begin())); test_values(*it1, *it2);
	test_values(*m1.equal_range(*(++++m1.begin())).first, *m2.equal_range(*(++++m2.begin())).first);
	test_values(*m1.equal_range(*(++++m1.begin())).second, *m2.equal_range(*(++++m2.begin())).second);

	std::cout << std::endl;
}

void test_multiset_int()
{
	std::cout << std::endl << "😡 [Multiset <int> test] ";

	std::cout << "[Constructors] ";
	std::multiset<int> m1; ft::Multiset<int> m2; test_sets(m1, m2);
	randmultisetint(m1,m2);
	std::multiset<int> m3(m1.begin(), m1.end()); ft::Multiset<int> m4(m2.begin(), m2.end()); test_sets(m3, m4);
	m3 = std::multiset<int>(++m1.begin(), --m1.end()); m4 = ft::Multiset<int>(++m2.begin(), --m2.end()); test_sets(m3, m4);
	m3 = std::multiset<int>(m1.end(), m1.end()); m4 = ft::Multiset<int>(m2.end(), m2.end()); test_sets(m3, m4);
	m3 = std::multiset<int>(m1); m4 = ft::Multiset<int>(m2); test_sets(m3, m4);

	std::cout << "[Iterators] ";
	randmultisetint(m1,m2);
	std::multiset<int>::iterator it1 = m1.begin(); ft::Multiset<int>::iterator it2 = m2.begin();
	test_values(*it1, *it2);
	test_values(*(++it1), *(++it2)); test_values(*(it1++), *(it2++));
	std::multiset<int>::iterator it3 = --m1.end(); ft::Multiset<int>::iterator it4 = --m2.end();
	test_values(*it1, *it2);
	bool r1 = (it1 == it3); bool r2 = (it2 == it4); test_values(r1, r2);
	it3 = it1; it4 = it2;
	r1 = (it1 != it3); r2 = (it2 != it4); test_values(r1, r2);
	std::multiset<int>::const_iterator it5 = m1.begin(); ft::Multiset<int>::const_iterator it6 = m2.begin();
	test_values(*it5, *it6);
	test_values(*(++++it5), *(++++it6)); test_values(*(it5++++), *(it6++++));
	test_values(*(--it5), *(--it6));
	std::multiset<int>::reverse_iterator it7(m1.rbegin()); ft::Multiset<int>::reverse_iterator it8(m2.rbegin());
	test_values(*it7, *it8);
	test_values(*(++++it7), *(++++it8)); test_values(*(it7++++), *(it8++++));
	test_values(*(--it7), *(--it8));
	std::multiset<int>::const_reverse_iterator it9 = ++m1.rend(); ft::Multiset<int>::const_reverse_iterator it10 = ++m2.rend();
	test_values(*it9, *it10);
	test_values(*(++++it9), *(++++it10)); test_values(*(it9++++), *(it10++++));
	test_values(*(--it9), *(--it10));

	std::cout << "[Capacity] ";
	randmultisetint(m1,m2); m3 = std::multiset<int>(); m4 = ft::Multiset<int>();
	test_values(m1.empty(), m2.empty()); test_values(m3.empty(), m4.empty());
	test_values(m1.size(), m2.size()); test_values(m3.size(), m4.size());
	test_values(m1.max_size(), m2.max_size()); test_values(m3.max_size(), m4.max_size());

	std::cout << "[Modifiers] ";
	m1 = std::multiset<int>(); m2 = ft::Multiset<int>();
	m3 = std::multiset<int>(); m4 = ft::Multiset<int>();
	m1.insert(123); m2.insert(123); test_sets(m1, m2);
	m1.insert(123); m2.insert(123); test_sets(m1, m2);
	m1.insert(456); m2.insert(456); test_sets(m1, m2);
	m1.insert(m1.begin(), 345); m2.insert(m2.begin(), 345); test_sets(m1, m2);
	m3.insert(m1.begin(), --m1.end()); m4.insert(m2.begin(), --m2.end()); test_sets(m3, m4);
	m1.erase(m1.begin()); m2.erase(m2.begin()); test_sets(m1, m2);
	int r3, r4;
	r3 = m1.erase(123); r4 = m2.erase(123); test_sets(m1, m2); test_values(r3, r4);
	r3 = m1.erase(123); r4 = m2.erase(123); test_sets(m1, m2); test_values(r3, r4);
	m1.erase(m1.begin(), ++m1.begin()); m2.erase(m2.begin(), ++m2.begin()); test_sets(m1, m2);
	m1.swap(m3); m2.swap(m4); test_sets(m1, m2); test_sets(m3, m4);
	m1.clear(); m2.clear(); test_sets(m1, m2); test_sets(m3, m4);

	std::cout << "[Observers] ";
	test_values(m3.key_comp()(4,6), m4.key_comp()(4,6));
	test_values(m3.key_comp()(6,6), m4.key_comp()(6,6));
	test_values(m3.value_comp()(4,6), m4.value_comp()(4,6));
	test_values(m3.value_comp()(6,6), m4.value_comp()(6,6));

	std::cout << "[Operators] ";
	randmultisetint(m1, m2);
	m1.insert(123); m2.insert(123); m1.insert(123); m2.insert(123);
	it1 = m1.find(123); it2 = m2.find(123); test_values(*it1, *it2);
	r3 = m1.count(124); r4 = m2.count(124); test_values(r3, r4);
	r3 = m1.count(123); r4 = m2.count(123); test_values(r3, r4);
	m1.insert(100000); m2.insert(100000); m1.insert(100010); m2.insert(100010);
	it1 = m1.lower_bound(100005); it2 = m2.lower_bound(100005); test_values(*it1, *it2);
	it1 = m1.lower_bound(*(++m1.begin())); it2 = m2.lower_bound(*(++m2.begin())); test_values(*it1, *it2);
	it1 = m1.lower_bound(*(--m1.end())); it2 = m2.lower_bound(*(--m2.end())); test_values(*it1, *it2);
	it1 = m1.upper_bound(100005); it2 = m2.upper_bound(100005); test_values(*it1, *it2);
	it1 = m1.upper_bound(*(++m1.begin())); it2 = m2.upper_bound(*(++m2.begin())); test_values(*it1, *it2);
	test_values(*m1.equal_range(*(++++m1.begin())).first, *m2.equal_range(*(++++m2.begin())).first);
	test_values(*m1.equal_range(*(++++m1.begin())).second, *m2.equal_range(*(++++m2.begin())).second);

	std::cout << std::endl;
}

void test_multiset_string()
{
	std::cout << std::endl << "😡 [Multiset <std::string> test] ";

	std::cout << "[Constructors] ";
	std::multiset<std::string> m1; ft::Multiset<std::string> m2; test_sets(m1, m2);
	randmultisetstring(m1,m2);
	std::multiset<std::string> m3(m1.begin(), m1.end()); ft::Multiset<std::string> m4(m2.begin(), m2.end()); test_sets(m3, m4);
	m3 = std::multiset<std::string>(++m1.begin(), --m1.end()); m4 = ft::Multiset<std::string>(++m2.begin(), --m2.end()); test_sets(m3, m4);
	m3 = std::multiset<std::string>(m1.end(), m1.end()); m4 = ft::Multiset<std::string>(m2.end(), m2.end()); test_sets(m3, m4);
	m3 = std::multiset<std::string>(m1); m4 = ft::Multiset<std::string>(m2); test_sets(m3, m4);

	std::cout << "[Iterators] ";
	randmultisetstring(m1,m2);
	std::multiset<std::string>::iterator it1 = m1.begin(); ft::Multiset<std::string>::iterator it2 = m2.begin();
	test_values(*it1, *it2);
	test_values(*(++it1), *(++it2)); test_values(*(it1++), *(it2++));
	std::multiset<std::string>::iterator it3 = --m1.end(); ft::Multiset<std::string>::iterator it4 = --m2.end();
	test_values(*it1, *it2);
	bool r1 = (it1 == it3); bool r2 = (it2 == it4); test_values(r1, r2);
	it3 = it1; it4 = it2;
	r1 = (it1 != it3); r2 = (it2 != it4); test_values(r1, r2);
	std::multiset<std::string>::const_iterator it5 = m1.begin(); ft::Multiset<std::string>::const_iterator it6 = m2.begin();
	test_values(*it5, *it6);
	test_values(*(++++it5), *(++++it6)); test_values(*(it5++++), *(it6++++));
	test_values(*(--it5), *(--it6));
	std::multiset<std::string>::reverse_iterator it7(m1.rbegin()); ft::Multiset<std::string>::reverse_iterator it8(m2.rbegin());
	test_values(*it7, *it8);
	test_values(*(++++it7), *(++++it8)); test_values(*(it7++++), *(it8++++));
	test_values(*(--it7), *(--it8));
	std::multiset<std::string>::const_reverse_iterator it9 = ++m1.rend(); ft::Multiset<std::string>::const_reverse_iterator it10 = ++m2.rend();
	test_values(*it9, *it10);
	test_values(*(++++it9), *(++++it10)); test_values(*(it9++++), *(it10++++));
	test_values(*(--it9), *(--it10));

	std::cout << "[Capacity] ";
	randmultisetstring(m1,m2); m3 = std::multiset<std::string>(); m4 = ft::Multiset<std::string>();
	test_values(m1.empty(), m2.empty()); test_values(m3.empty(), m4.empty());
	test_values(m1.size(), m2.size()); test_values(m3.size(), m4.size());
	test_values(m1.max_size(), m2.max_size()); test_values(m3.max_size(), m4.max_size());

	std::cout << "[Modifiers] ";
	m1 = std::multiset<std::string>(); m2 = ft::Multiset<std::string>();
	m3 = std::multiset<std::string>(); m4 = ft::Multiset<std::string>();
	m1.insert("123"); m2.insert("123"); test_sets(m1, m2);
	m1.insert("123"); m2.insert("123"); test_sets(m1, m2);
	m1.insert("456"); m2.insert("456"); test_sets(m1, m2);
	m1.insert(m1.begin(), "345"); m2.insert(m2.begin(), "345"); test_sets(m1, m2);
	m3.insert(m1.begin(), --m1.end()); m4.insert(m2.begin(), --m2.end()); test_sets(m3, m4);
	m1.erase(m1.begin()); m2.erase(m2.begin()); test_sets(m1, m2);
	int r3, r4;
	r3 = m1.erase("123"); r4 = m2.erase("123"); test_sets(m1, m2); test_values(r3, r4);
	r3 = m1.erase("123"); r4 = m2.erase("123"); test_sets(m1, m2); test_values(r3, r4);
	m1.erase(m1.begin(), ++m1.begin()); m2.erase(m2.begin(), ++m2.begin()); test_sets(m1, m2);
	m1.swap(m3); m2.swap(m4); test_sets(m1, m2); test_sets(m3, m4);
	m1.clear(); m2.clear(); test_sets(m1, m2); test_sets(m3, m4);

	std::cout << "[Observers] ";
	test_values(m3.key_comp()("4","6"), m4.key_comp()("4","6"));
	test_values(m3.key_comp()("6","6"), m4.key_comp()("6","6"));
	test_values(m3.value_comp()("4","6"), m4.value_comp()("4","6"));
	test_values(m3.value_comp()("6","6"), m4.value_comp()("6","6"));

	std::cout << "[Operators] ";
	randmultisetstring(m1,m2); m1.insert("123"); m2.insert("123");
	it1 = m1.find("123"); it2 = m2.find("123"); test_values(*it1, *it2);
	r3 = m1.count("124"); r4 = m2.count("124"); test_values(r3, r4);
	r3 = m1.count("123"); r4 = m2.count("123"); test_values(r3, r4);
	m1.insert("100000"); m2.insert("100000"); m1.insert("100010"); m2.insert("100010");
	it1 = m1.lower_bound("100005"); it2 = m2.lower_bound("100005"); test_values(*it1, *it2);
	it1 = m1.lower_bound(*(++m1.begin())); it2 = m2.lower_bound(*(++m2.begin())); test_values(*it1, *it2);
	it1 = m1.lower_bound(*(--m1.end())); it2 = m2.lower_bound(*(--m2.end())); test_values(*it1, *it2);
	it1 = m1.upper_bound("100005"); it2 = m2.upper_bound("100005"); test_values(*it1, *it2);
	it1 = m1.upper_bound(*(++m1.begin())); it2 = m2.upper_bound(*(++m2.begin())); test_values(*it1, *it2);
	test_values(*m1.equal_range(*(++++m1.begin())).first, *m2.equal_range(*(++++m2.begin())).first);
	test_values(*m1.equal_range(*(++++m1.begin())).second, *m2.equal_range(*(++++m2.begin())).second);

	std::cout << std::endl;
}

void test_multimap_int()
{
	std::cout << std::endl << "🤬 [Multimap <int> test] ";

	std::cout << "[Constructors] ";
	std::multimap<int,int> m1; ft::Multimap<int,int> m2; test_maps(m1, m2);
	randmultimapint(m1,m2); test_maps(m1, m2);
	std::multimap<int,int> m3(m1.begin(), m1.end()); ft::Multimap<int,int> m4(m2.begin(), m2.end()); test_maps(m3, m4);
	m3 = std::multimap<int,int>(++m1.begin(), --m1.end()); m4 = ft::Multimap<int,int>(++m2.begin(), --m2.end()); test_maps(m3, m4);
	m3 = std::multimap<int,int>(m1.end(), m1.end()); m4 = ft::Multimap<int,int>(m2.end(), m2.end()); test_maps(m3, m4);
	m3 = std::multimap<int,int>(m1); m4 = ft::Multimap<int,int>(m2); test_maps(m3, m4);

	std::cout << "[Iterators] ";
	randmultimapint(m1,m2);
	std::multimap<int,int>::iterator it1 = m1.begin(); ft::Multimap<int,int>::iterator it2 = m2.begin();
	test_values(it1->first, it2->first); test_values(it1->second, it2->second);
	test_values((++it1)->first, (++it2)->first); test_values((it1++)->second, (it2++)->second);
	std::multimap<int,int>::iterator it3 = --m1.end(); ft::Multimap<int,int>::iterator it4 = --m2.end();
	test_values(it1->first, it2->first); test_values(it1->second, it2->second);
	bool r1 = (it1 == it3); bool r2 = (it2 == it4); test_values(r1, r2);
	it3 = it1; it4 = it2;
	r1 = (it1 != it3); r2 = (it2 != it4); test_values(r1, r2);
	std::multimap<int,int>::const_iterator it5 = m1.begin(); ft::Multimap<int,int>::const_iterator it6 = m2.begin();
	test_values(it5->first, it6->first); test_values(it5->second, it6->second);
	test_values((++++it5)->first, (++++it6)->first); test_values((it5++++)->second, (it6++++)->second);
	test_values((--it5)->second, (--it6)->second);
	std::multimap<int,int>::reverse_iterator it7(m1.rbegin()); ft::Multimap<int,int>::reverse_iterator it8(m2.rbegin());
	test_values(it7->first, it8->first); test_values(it7->second, it8->second);
	test_values((++++it7)->first, (++++it8)->first); test_values((it7++++)->second, (it8++++)->second);
	test_values((--it7)->second, (--it8)->second);
	std::multimap<int,int>::const_reverse_iterator it9 = ++m1.rend(); ft::Multimap<int,int>::const_reverse_iterator it10 = ++m2.rend();
	test_values(it9->first, it10->first); test_values(it9->second, it10->second);
	test_values((++++it9)->first, (++++it10)->first); test_values((it9++++)->second, (it10++++)->second);
	test_values((--it9)->second, (--it10)->second);

	std::cout << "[Capacity] ";
	randmultimapint(m1,m2); m3 = std::multimap<int,int>(); m4 = ft::Multimap<int,int>();
	test_values(m1.empty(), m2.empty()); test_values(m3.empty(), m4.empty());
	test_values(m1.size(), m2.size()); test_values(m3.size(), m4.size());
	test_values(m1.max_size(), m2.max_size()); test_values(m3.max_size(), m4.max_size());

	std::cout << "[Modifiers] ";
	m1.insert(std::pair<int,int>(123, 456)); m2.insert(ft::Pair<int,int>(123, 456)); test_maps(m1, m2);
	m1.insert(std::pair<int,int>(123, 789)); m2.insert(ft::Pair<int,int>(123, 789)); test_maps(m1, m2);
	m1.insert(++++m1.begin(), std::pair<int,int>(345, 789)); m2.insert(++++m2.begin(), ft::Pair<int,int>(345, 789)); test_maps(m1, m2);
	m3.insert(++m1.begin(), --m1.end()); m4.insert(++m2.begin(), --m2.end()); test_maps(m3, m4);
	m3.insert(++m1.begin(), --m1.end()); m4.insert(++m2.begin(), --m2.end()); test_maps(m3, m4);
	int r3 = m1.erase(124); int r4 = m2.erase(124); test_maps(m1, m2); test_values(r3, r4);
	r3 = m1.erase(123); r4 = m2.erase(123); test_maps(m1, m2); test_values(r3, r4);
	r3 = m1.erase(123); r4 = m2.erase(123); test_maps(m1, m2); test_values(r3, r4);
	m1.erase(++m1.begin(), ----m1.end()); m2.erase(++m2.begin(), ----m2.end()); test_maps(m1, m2);
	m1.swap(m3); m2.swap(m4); test_maps(m1, m2); test_maps(m3, m4);
	m1.clear(); m2.clear(); test_maps(m1, m2); test_maps(m3, m4);

	std::cout << "[Observers] ";
	test_values(m3.key_comp()(4,6), m4.key_comp()(4,6));
	test_values(m3.key_comp()(6,6), m4.key_comp()(6,6));
	test_values(m3.value_comp()(*m3.begin(), *(++m3.begin())), m4.value_comp()(*m4.begin(), *(++m4.begin())));
	test_values(m3.value_comp()(*(--m3.end()), *(++m3.begin())), m4.value_comp()(*(--m4.end()), *(++m4.begin())));

	std::cout << "[Operators] ";
	randmultimapint(m1,m2);
	m1.insert(std::pair<int,int>(123, 456)); m2.insert(ft::Pair<int,int>(123, 456));
	m1.insert(std::pair<int,int>(123, 456)); m2.insert(ft::Pair<int,int>(123, 456));
	m1.insert(std::pair<int,int>(123, 455)); m2.insert(ft::Pair<int,int>(123, 455));
	it1 = m1.find(124); it2 = m2.find(124); test_values(it1->second, it2->second);
	it1 = m1.find(123); it2 = m2.find(123);
	test_values(it1->first, it2->first); test_values(it1->second, it2->second);
	r3 = m1.count(124); r4 = m2.count(124); test_values(r3, r4);
	r3 = m1.count(123); r4 = m2.count(123); test_values(r3, r4);
	it1 = m1.lower_bound(11111); it2 = m2.lower_bound(11111); test_values(it1->second, it2->second);
	it1 = m1.lower_bound(-11111); it2 = m2.lower_bound(-11111); test_values(it1->second, it2->second);
	it1 = m1.upper_bound(11111); it2 = m2.upper_bound(11111); test_values(it1->second, it2->second);
	it1 = m1.upper_bound(-11111); it2 = m2.upper_bound(-11111); test_values(it1->second, it2->second);
	test_values(m1.equal_range(10000).first->second, m2.equal_range(10000).first->second);
	test_values(m1.equal_range(0).first->second, m2.equal_range(0).first->second);
	test_values(m1.equal_range(-10000).first->second, m2.equal_range(-10000).first->second);
	m3 = std::multimap<int,int>(); m4 = ft::Multimap<int,int>();
	it1 = m3.lower_bound(11111); it2 = m4.lower_bound(11111); test_values(it1->second, it2->second);
	it1 = m3.upper_bound(-11111); it2 = m4.upper_bound(-11111); test_values(it1->second, it2->second);
	test_values(m3.equal_range(0).first->second, m4.equal_range(0).first->second);

	std::cout << std::endl;
}

void test_multimap_string()
{
	std::cout << std::endl << "🤬 [Multimap <std::string> test] ";

	std::cout << "[Constructors (and operator[])] ";
	std::multimap<std::string,std::string> m1; ft::Multimap<std::string,std::string> m2; test_maps(m1, m2);
	randmultimapstring(m1,m2); test_maps(m1, m2);
	std::multimap<std::string,std::string> m3(m1.begin(), m1.end()); ft::Multimap<std::string,std::string> m4(m2.begin(), m2.end()); test_maps(m3, m4);
	m3 = std::multimap<std::string,std::string>(++m1.begin(), --m1.end()); m4 = ft::Multimap<std::string,std::string>(++m2.begin(), --m2.end()); test_maps(m3, m4);
	m3 = std::multimap<std::string,std::string>(m1.end(), m1.end()); m4 = ft::Multimap<std::string,std::string>(m2.end(), m2.end()); test_maps(m3, m4);
	m3 = std::multimap<std::string,std::string>(m1); m4 = ft::Multimap<std::string,std::string>(m2); test_maps(m3, m4);

	std::cout << "[Iterators] ";
	randmultimapstring(m1,m2);
	std::multimap<std::string,std::string>::iterator it1 = m1.begin(); ft::Multimap<std::string,std::string>::iterator it2 = m2.begin();
	test_values(it1->first, it2->first); test_values(it1->second, it2->second);
	test_values((++it1)->first, (++it2)->first); test_values((it1++)->second, (it2++)->second);
	std::multimap<std::string,std::string>::iterator it3 = --m1.end(); ft::Multimap<std::string,std::string>::iterator it4 = --m2.end();
	test_values(it1->first, it2->first); test_values(it1->second, it2->second);
	bool r1 = (it1 == it3); bool r2 = (it2 == it4); test_values(r1, r2);
	it3 = it1; it4 = it2;
	r1 = (it1 != it3); r2 = (it2 != it4); test_values(r1, r2);
	std::multimap<std::string,std::string>::const_iterator it5 = m1.begin(); ft::Multimap<std::string,std::string>::const_iterator it6 = m2.begin();
	test_values(it5->first, it6->first); test_values(it5->second, it6->second);
	test_values((++++it5)->first, (++++it6)->first); test_values((it5++++)->second, (it6++++)->second);
	test_values((--it5)->second, (--it6)->second);
	std::multimap<std::string,std::string>::reverse_iterator it7(m1.rbegin()); ft::Multimap<std::string,std::string>::reverse_iterator it8(m2.rbegin());
	test_values(it7->first, it8->first); test_values(it7->second, it8->second);
	test_values((++++it7)->first, (++++it8)->first); test_values((it7++++)->second, (it8++++)->second);
	test_values((--it7)->second, (--it8)->second);
	std::multimap<std::string,std::string>::const_reverse_iterator it9 = ++m1.rend(); ft::Multimap<std::string,std::string>::const_reverse_iterator it10 = ++m2.rend();
	test_values(it9->first, it10->first); test_values(it9->second, it10->second);
	test_values((++++it9)->first, (++++it10)->first); test_values((it9++++)->second, (it10++++)->second);
	test_values((--it9)->second, (--it10)->second);

	std::cout << "[Capacity] ";
	randmultimapstring(m1,m2); m3 = std::multimap<std::string,std::string>(); m4 = ft::Multimap<std::string,std::string>();
	test_values(m1.empty(), m2.empty()); test_values(m3.empty(), m4.empty());
	test_values(m1.size(), m2.size()); test_values(m3.size(), m4.size());
	test_values(m1.max_size(), m2.max_size()); test_values(m3.max_size(), m4.max_size());

	std::cout << "[Modifiers] ";
	m1.insert(std::pair<std::string,std::string>("123", "456")); m2.insert(ft::Pair<std::string,std::string>("123", "456")); test_maps(m1, m2);
	m1.insert(std::pair<std::string,std::string>("123", "789")); m2.insert(ft::Pair<std::string,std::string>("123", "789")); test_maps(m1, m2);
	m1.insert(++++m1.begin(), std::pair<std::string,std::string>("345", "789")); m2.insert(++++m2.begin(), ft::Pair<std::string,std::string>("345", "789")); test_maps(m1, m2);
	m3.insert(++m1.begin(), --m1.end()); m4.insert(++m2.begin(), --m2.end()); test_maps(m3, m4);
	m3.insert(++m1.begin(), --m1.end()); m4.insert(++m2.begin(), --m2.end()); test_maps(m3, m4);
	int r3 = m1.erase("124"); int r4 = m2.erase("124"); test_maps(m1, m2); test_values(r3, r4);
	r3 = m1.erase("123"); r4 = m2.erase("123"); test_maps(m1, m2); test_values(r3, r4);
	r3 = m1.erase("123"); r4 = m2.erase("123"); test_maps(m1, m2); test_values(r3, r4);
	m1.swap(m3); m2.swap(m4); test_maps(m1, m2); test_maps(m3, m4);
	m1.clear(); m2.clear(); test_maps(m1, m2); test_maps(m3, m4);

	std::cout << "[Observers] ";
	test_values(m3.key_comp()("4","6"), m4.key_comp()("4","6"));
	test_values(m3.key_comp()("6","6"), m4.key_comp()("6","6"));
	test_values(m3.value_comp()(*m3.begin(), *(++m3.begin())), m4.value_comp()(*m4.begin(), *(++m4.begin())));
	test_values(m3.value_comp()(*(--m3.end()), *(++m3.begin())), m4.value_comp()(*(--m4.end()), *(++m4.begin())));

	std::cout << "[Operators] ";
	randmultimapstring(m1,m2);
	m1.insert(std::pair<std::string,std::string>("123", "456")); m2.insert(ft::Pair<std::string,std::string>("123", "456"));
	m1.insert(std::pair<std::string,std::string>("123", "456")); m2.insert(ft::Pair<std::string,std::string>("123", "456"));
	m1.insert(std::pair<std::string,std::string>("123", "455")); m2.insert(ft::Pair<std::string,std::string>("123", "455"));
	it1 = m1.find("123"); it2 = m2.find("123");
	test_values(it1->first, it2->first); test_values(it1->second, it2->second);
	r3 = m1.count("124"); r4 = m2.count("124"); test_values(r3, r4);
	r3 = m1.count("123"); r4 = m2.count("123"); test_values(r3, r4);
	it1 = m1.lower_bound("11111"); it2 = m2.lower_bound("11111"); test_values(it1->second, it2->second);
	it1 = m1.lower_bound("-11111"); it2 = m2.lower_bound("-11111"); test_values(it1->second, it2->second);
	it1 = m1.upper_bound("11111"); it2 = m2.upper_bound("11111"); test_values(it1->second, it2->second);
	it1 = m1.upper_bound("-11111"); it2 = m2.upper_bound("-11111"); test_values(it1->second, it2->second);
	test_values(m1.equal_range("10000").first->second, m2.equal_range("10000").first->second);
	test_values(m1.equal_range("0").first->second, m2.equal_range("0").first->second);
	test_values(m1.equal_range("-10000").first->second, m2.equal_range("-10000").first->second);

	std::cout << std::endl;
}

void test_all()
{
	test_vector_int();
	test_vector_string();
	test_list_int();
	test_list_string();
	test_stack_int();
	test_stack_string();
	test_queue_int();
	test_queue_string();
	test_map_int();
	test_map_string();
}

void test_bonus()
{
	test_deque_int();
	test_deque_string();
	test_set_int();
	test_set_string();
	test_multiset_int();
	test_multiset_string();
	test_multimap_int();
	test_multimap_string();
}

int main(int ac, char **av)
{
	std::vector<std::string> args = check_av(ac, av);
	std::srand(std::time(NULL));
	std::vector<std::string>::const_iterator it = args.begin();
	std::vector<std::string>::const_iterator ite = args.end();
	for (bool ret = false; it != ite;)
	{
		if (*it == "all")
		{
			ret = true;
			test_all();
		}
		else if (*it == "bonus")
		{
			ret = true;
			test_bonus();
		}
		if (++it == ite && ret == true)
			return EXIT_SUCCESS;
	}
	it = args.begin();
	for (; it != ite; ++it)
	{
		if (*it == "vector")
		{
			test_vector_int();
			test_vector_string();
		}
		else if (*it == "list")
		{
			test_list_int();
			test_list_string();
		}
		else if (*it == "stack")
		{
			test_stack_int();
			test_stack_string();
		}
		else if (*it == "queue")
		{
			test_queue_int();
			test_queue_string();
		}
		else if (*it == "map")
		{
			test_map_int();
			test_map_string();
		}
		else if (*it == "deque")
		{
			test_deque_int();
			test_deque_string();
		}
		else if (*it == "set")
		{
			test_set_int();
			test_set_string();
		}
		else if (*it == "multiset")
		{
			test_multiset_int();
			test_multiset_string();
		}
		else if (*it == "multimap")
		{
			test_multimap_int();
			test_multimap_string();
		}
	}
	return EXIT_SUCCESS;
}
