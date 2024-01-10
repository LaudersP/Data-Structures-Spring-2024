#include <string>

namespace ssuds {
	class ArrayList {
	protected:
		std::string* _data;		// Holds the current DYNAMIC ARRAY
		unsigned int _size;
	public:
		ArrayList();
		~ArrayList();
		void Append(std::string s);
		unsigned int Size();
	};
}