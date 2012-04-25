#include <iostream.h>
#include <Picture.h>

char *init[] = { "Paris", "in the", "Spring" };

using namespace std;
int main() 
{
	Picture p(init, 3);
	cout << p <<endl;

	Picture q = frame(p);
	cout << q << endl;

	Picture r = p | q;
	cout << r << endl;

	Picture s = q & r; 
	cout << s << endl << frame(s) << endl;

}

