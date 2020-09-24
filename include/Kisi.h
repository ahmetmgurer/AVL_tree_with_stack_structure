#include <iostream>
#include <string.h>
#include <Stack.h>

using namespace std;

class Kisi
{
public:
	Kisi *right;
	Kisi *left;
	int height;
	int old_height;
	int Height();
	bool key;
	void update_Height();
	Stack *stack;

	Kisi(const string&,int,const string&);

	int DogumTarihi();
	int Yas();
	string  Isim();
	string  Kilo();	
	
	~Kisi();
	
private:
	string isim;
	int dogumTarihi;
	string kilo;
};
