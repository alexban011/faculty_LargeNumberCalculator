//---------------------------------------------------------------------------

#ifndef operatiiH
#define operatiiH
#include "numarMare.h"
#include <vcl.h>

class operatii{
	public:
		//variabile
		numarMare *Rezultat;
		numarMare *Numar1;
		numarMare *Numar2;

		String NumarDinEdit1;
		String NumarDinEdit2;

		String StringRezultatOperatii;
        int selectieOperatie=0;
		//functii pentru program
		void adunare(numarMare *nr1, numarMare *nr2, numarMare *rez);
		void scadere(numarMare *nr1, numarMare *nr2, numarMare *rez);
		void inmultire(numarMare *nr1, numarMare *nr2, numarMare *rez);
		//void impartire();
		//void radical();
		//void invers();
        void selectareOperatie(int op);

		//functii pt afisarea rezultatelor

};
//---------------------------------------------------------------------------
#endif

