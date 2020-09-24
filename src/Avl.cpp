/**
* @file Avl.cpp
* @description gönderilen bilgilere göre kişi oluşturan, avl agaci oluşturan ve yerleştiren, stack işlemlerini yapan ve ekrana pop yaparak yazan kaynak dosyası.
* @course 1/A
* @assignment 2. Ödev
* @date 26.08.2020
* @author Ahmet Mücahit Gürer
*/

#include "Avl.h"
#include "Utils.h"
using namespace std;
Avl::Avl()
{
	root = nullptr;
}


Kisi *Avl::InsertNew(Kisi *&root,const string &isim, int dogumTarihi , const string &kilo)
{
	int yeniKisiYas = 2020 - dogumTarihi;


	if (root == nullptr)
	{
		root = new Kisi(isim,dogumTarihi, kilo);
		root->stack->Push('O');
		yeni = root;
		root->height = 0;
		
		
	}
	
	else if (yeniKisiYas <=	root->Yas())
	{
		root->left = InsertNew(root->left,isim,dogumTarihi, kilo);
		if (Height(root->left) - Height(root->right) == 2)
		{
			if (yeniKisiYas <= root->left->Yas())
			{
				root = singleRightRotate(root);
				
			
			}
			else{
				root = doubleRightRotate(root);
				
				
			}
		}
		

	}
	else if (yeniKisiYas > root->Yas())
	{

		root->right = InsertNew(root->right,isim,dogumTarihi,kilo);
		if (Height(root->right) - Height(root->left) == 2)
		{	
			if (yeniKisiYas > root->right->Yas()){
				root = singleLeftRotate(root);
				
				
				}

			else{
				root = doubleLeftRotate(root);
				
			
			}
		}
		

	}

	root->height = 1+Utils::max(Height(root->left), Height(root->right));
	
	return root;
}


Kisi *Avl::singleRightRotate(Kisi *&t)
{
	Kisi *u = t->left;
	t->left = u->right;
	u->right = t;

	u->key = true;
	t->key = true;

	t->height = Utils::max(Height(t->left), Height(t->right)) + 1;
	u->height = Utils::max(Height(u->left), Height(u->right)) + 1;
	return u;
}

Kisi *Avl::singleLeftRotate(Kisi *&t)
{
	Kisi *u = t->right;
	t->right = u->left;
	u->left = t;



	u->key = true;
	t->key = true;

	t->height = Utils::max(Height(t->left), Height(t->right)) + 1;
	u->height = Utils::max(Height(u->left), Height(u->right)) + 1;
	return u;
}

Kisi *Avl::doubleLeftRotate(Kisi *&t)
{
	t->right = singleRightRotate(t->right);
	return singleLeftRotate(t);
}

Kisi *Avl::doubleRightRotate(Kisi *&t)
{
	t->left = singleLeftRotate(t->left);
	return singleRightRotate(t);
}

int Avl::Height(Kisi *&K)
{
	if (K == NULL)
		return 0;
	return K->Height();
}


void Avl::PostOrder(Kisi *root)
{
	if (root != nullptr)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->Isim() << "," << root->DogumTarihi() << "," << root->Kilo() << "Yigit:" << "\t";
		root->stack->Pop();
		cout << endl;
	}
}

void Avl::updateStack(Kisi *&root)
{

	if (root != nullptr && root != yeni && root->key)
	{
		updateStack(root->left);
		updateStack(root->right);
		if (root->old_height > root->height)
		{
			root->stack->Push('A');
		}
		if (root->old_height < root->height)
		{
			root->stack->Push('Y');
		}

		
	}
	
	
	if (root != nullptr && root != yeni && !root->key)
	{
	/*	if (root->old_height > root->height || )
		{
			root->stack->Push('A');
			updateStack(root->left);
		updateStack(root->right);
		}
		else{*/
		
		root->stack->Push('D');	
		updateStack(root->left);
		updateStack(root->right);
		/*}*/
	}



}

void Avl::resetStackFeatures(Kisi *&root)
{

	if (root != nullptr)
	{
		resetStackFeatures(root->left);
		resetStackFeatures(root->right);
		root->update_Height();
		root->key = false;
	}
}
void Avl::StackOperations(Kisi *&root){
updateStack(root);
resetStackFeatures(root);
}
int Avl::max(int a, int b)
{
	int max = 0;
	(a > b) ? max = a : max = b;
	return max;
}

void Avl::Travel(Kisi *&root)
{
	PostOrder(root);
}

Avl::~Avl()
{
	root->~Kisi();
}
