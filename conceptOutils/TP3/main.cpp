#include <iostream>

#include "Fonctions.hpp"

int main(void)
{
	Fonctions *pdfManager = new Fonctions();
	pdfManager->makeA4();
	pdfManager->essaiCercle();
	pdfManager->endDoc();
	return 0;
}
