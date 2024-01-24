#include <Array_List_v2.hpp>
#include <iostream>

int main() {
	ssuds::ArrayListV2<int> a;
	a.Append(4);
	a.Append(9);
	a.Append(5);
	a.Append(2);

	std::cout << a << std::endl;

	ssuds::ArrayListV2<float> b;
	b.Append(2.678f);
	b.Append(9.4f);
	b.Append(5.1f);
	b.Append(4.0f);

	std::cout << b << std::endl;

	ssuds::ArrayListV2<int> c;

	c.Append(3);

	c = a;

	c.Insert(13, 2);

	std::cout << c << std::endl;
}