#include <Array_List_v2.hpp>
#include <iostream>

int main() {
	ssuds::ArrayListV2<int> a;
	a.Append(4);
	a.Append(9);
	a.Append(5);
	a.Append(2);

	for (unsigned int i = 0; i < a.Size(); i++) {
		if (i == 0) {
			std::cout << "[" << a.Get(i) << ", ";
		}
		else if (i == (a.Size() - 1)) {
			std::cout << a.Get(i) << "]" << std::endl;
		}
		else {
			std::cout << a.Get(i) << ", ";
		}
	}

	ssuds::ArrayListV2<float> b;
	b.Append(2.678);
	b.Append(9.4);
	b.Append(5.1f);
	b.Append(4.0);

	for (unsigned int i = 0; i < b.Size(); i++) {
		if (i == 0) {
			std::cout << "[" << b.Get(i) << ", ";
		}
		else if (i == (b.Size() - 1)) {
			std::cout << b.Get(i) << "]" << std::endl;
		}
		else {
			std::cout << b.Get(i) << ", ";
		}
	}
}