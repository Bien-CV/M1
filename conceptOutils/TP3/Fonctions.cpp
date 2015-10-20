using namespace std;

#include "Fonctions.hpp"


Fonctions::Fonctions(){
	p = new PDFlib();
}

Fonctions::~Fonctions(){
		delete(p);
}

void Fonctions::makeA4(){
	p->begin_document("exemple.pdf","");
	p->begin_page_ext(595,842,"");
}

void Fonctions::endDoc(){
	p->end_page_ext("");
	p->end_document("");
}

void Fonctions::essaiCercle(){
	p->translate(595/2,842/2);//centre le dessin
	p->circle(0,0,40);
	p->stroke();		
}

