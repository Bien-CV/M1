/**
*\file Fonctions.hpp
*\brief Fonctions permettant de générer des graphes au format pdf.
*\author Dennis Bordet
*\version 1.0

**/


#ifndef FONTIONS_HPP
#define FONCTIONS_HPP

#include "pdflib.hpp"

/**
*\class Fonctions
*\brief classe intanciant un pdflib nous permettant d'executer des manipulations sur le pdf.
**/

class Fonctions{
	private:
		PDFlib *p;//! utilisé pour creer les pdfs
		TextManager *tm; //! utilisé pour lire les fichiers de données
		std::string filename;
	public:
		Fonctions();
		/**
		*\fn void makeA4()
		*\brief Génère une feuille A4 vierge au format PDF
		*\warning Attention : n'oubliez pas d'appeler endDoc() afin de terminer votre fichier. 
		**/
		void makeA4();
		
		/**
		*\fn void endDoc()
		*\brief Cette fonction doit etre appelée obligatoirement.
		*	Elle sert a terminer le Document pdf.
		*	Sans celle-ci votre document ne fonctionnera pas.
		**/
		void endDoc();
		
		/**
		*\fn void essaiCercle()
		*\brief fait un petit dessin test de cercle au centre du pdf.
		**/
		void essaiCercle();
		
		/**
		*\fn void askFilename()
		*\brief Demande à l'utilisateur une chaine de caractère.
		*	Cette chaine doit représenter le nom du fichier à lire.
		*Modifie l'attribut filename.
		*
		**/
		void askFilename();
		
		
		
		~Fonctions();
	
};



#endif
