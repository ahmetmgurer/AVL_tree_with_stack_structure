/**
* @file Main.cpp
* @description txt dosyanın okunup parçalanarak ilgi metoda gönderildiği kaynak dosyası.
* @course 1/A
* @assignment 2. Ödev
* @date 26.08.2020
* @author Ahmet Mücahit Gürer
*/

#include "Avl.h"
#include <fstream>

int main()
{

	string name;
	int dt;
	string kilo;
	string delimiter = {'#'};
	string token;
	size_t pos = 0;
	ifstream input("Kisiler.txt");
	
	Avl *agac = new Avl;

	if (input.is_open())
	{
		std::string line;
		while (std::getline(input, line))
		{
			bool key=true;
			while ((pos = line.find(delimiter)) != std::string::npos)
			{
				
				token = line.substr(0, pos);
				if(key){name=token;
}
				else {dt=stoi(token);
}			
				line.erase(0, pos + delimiter.length());
				key=false;
			}
			kilo=line;
			agac->root = agac->InsertNew(agac->root, name, dt, kilo);
			agac->StackOperations(agac->root);
			
		}
	}
	input.close();
	
	
	agac->PostOrder(agac->root);
	agac->~Avl();
	return 0;
}
