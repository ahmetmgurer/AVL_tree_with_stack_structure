#include "Kisi.h"
using namespace std;
class Avl
{
public:
	Kisi *root;
	Kisi *yeni;
	Avl();
	void Travel(Kisi *&);
	Kisi* InsertNew(Kisi *&, const string&,int, const string&);
	void updateStack(Kisi *&);
	void resetStackFeatures(Kisi *&);
	void PostOrder(Kisi *);
	void StackOperations(Kisi *&);
	int max(int , int );

	~Avl();

private:
int Height(Kisi *&);	
Kisi *singleLeftRotate(Kisi*&y);
Kisi *singleRightRotate(Kisi*&y);
Kisi *doubleLeftRotate(Kisi*&y);
Kisi *doubleRightRotate(Kisi*&y);
};

