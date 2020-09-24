/**
* @file Stack.cpp
* @description her düğümde bulunması gereken yığıt yapısı, düğümün hareketlerini tutan kaynak dosyası.
* @course 1/A
* @assignment 2. Ödev
* @date 26.08.2020
* @author Ahmet Mücahit Gürer
*/
#include "Stack.h"
	Stack::Stack(){
		
		stack_top=0;
		stack=(char * )malloc(250*sizeof(char));
		
		
	}
	void Stack::Pop(){

		while(stack_top>0){
			cout<<stack[--stack_top]<<" ";
		}
		
		
		
	}
	void Stack::Push(char character){
		
		stack[stack_top]=character;
		stack_top++;
		
	}
	Stack::~Stack(){
		
		free(stack);
		
	}


