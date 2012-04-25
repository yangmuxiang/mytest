#include <iostream.h>

class Picture {
public:
	Picture();
	Picture(const char* const*, int);
	Picture(const Picture&);
	~Picture();
	
	Picture& operator=(const Picture&);
};

ostream& operator<<(ostream&, const Picture&);
Picture frame(const Picture&);
Picture operator&(const Picture&, const Picture&);
Picture operator|(const Picture&, const Picture&);

