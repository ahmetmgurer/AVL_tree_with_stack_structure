/**
* @file Kisi.cpp
* @description gönderilen verilerle kişi oluşturan sınıf kaynak dosyası.
* @course 1/A
* @assignment 2. Ödev
* @date 26.08.2020
* @author Ahmet Mücahit Gürer
*/

#include "Kisi.h"

using namespace std;

Kisi::Kisi( const string &isim,int dogumTarihi, const string&kilo)
{
	this->isim=isim;
	this->kilo=kilo;
	this->key=false;
	this->dogumTarihi = dogumTarihi;
	this->height=0;
	this->right = nullptr;
	this->left = nullptr;
    this->stack=new Stack;
}


int Kisi::Yas()
{
	
   return 2020-dogumTarihi;
	
}

void Kisi::update_Height(){
	
	old_height=height;
	
}

int Kisi::DogumTarihi(){
return dogumTarihi;
	
}

string Kisi::Isim(){

return isim;
}

string Kisi::Kilo(){
	return kilo;
}

int Kisi::Height(){
	return height;
}

Kisi::~Kisi()
{

stack->~Stack();

}
