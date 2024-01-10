#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <string>

namespace ssuds {
	class ArrayList {
	protected:
		std::string* _data;
		unsigned int _size;
	public:
		ArrayList();
		~ArrayList();
		void Append(std::string s);
		unsigned int Size();

		std::string GetString(unsigned int pos);
	};
}

#endif