//---------------------------------------------------------------------------

#pragma hdrstop

#include "operatii.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

void operatii::adunare(numarMare *nr1, numarMare *nr2, numarMare *rez){
	  int inc = 0;
	  for(int i = 0; i<=199;i++){
			rez->cifreInversate[i]=inc+nr1->cifreInversate[i]+nr2->cifreInversate[i];
			if(rez->cifreInversate[i]>9){
				inc = 1;
				rez->cifreInversate[i] = rez->cifreInversate[i] % 10;
			}else{
				inc = 0;
			}
	  }
}

void operatii::scadere(numarMare *nr1, numarMare *nr2, numarMare *rez){

	  int rezu[200];                                                                           //TODO a > b si a < b
	  for(int i =0; i<=199;i++){
			if(nr1->cifreInversate[i] - nr2->cifreInversate[i] < 0){
				  nr1->cifreInversate[i] += 10;
				  nr1->cifreInversate[i+1] -= 1;

			}
			rez->cifreInversate[i]=nr1->cifreInversate[i] - nr2->cifreInversate[i];
	  }
}

void operatii::inmultire(numarMare *nr1, numarMare *nr2, numarMare *rez){
	int inc=0;
	int rezTemp1[200];
	int rezTemp2[200];
    int primRez = 0;
	for(int j = 0; j <= 199; j++){
		for(int i = 0; i <= 199; i++){
			rezTemp1[i] = inc + nr1->cifreInversate[i] * nr2->cifreInversate[j];
			if(rezTemp1[i] > 9){
				inc = rezTemp1[i] / 10;
				rezTemp1[i] %= 10;
			}
		}

		if(primRez == 0){
			primRez = 1;
		}else{
			for(int m = 198; m <= 1; m--){
				rezTemp1[m] = rezTemp1[m-1];
			}
			rezTemp1[0] = 0;
		}


		  int inc2 = 0;
		  for(int i = 0; i<=199;i++){
				rezTemp2[i] += inc2+rezTemp1[i];
				if(rezTemp2[i]>9){
					inc2 = rezTemp2[i]/10;
					rezTemp2[i] = rezTemp2[i] % 10;
				}else{
					inc2 = 0;
				}
		  }
	}
	for(int i = 0; i <= 199; i++){
		rez->cifreInversate[i] = rezTemp2[i];
	}

}


void operatii::selectareOperatie(int op){
	   switch (op){
			 case 1:
				Numar1 = new numarMare;
				Numar2 = new numarMare;
				Rezultat = new numarMare;

				Numar1->stringInNumar(NumarDinEdit1);
				Numar2->stringInNumar(NumarDinEdit2);
				operatii::adunare(Numar1, Numar2, Rezultat);
			   //	Numar1->numarInString();        //nu mai sunt folosite, nu are sens
			   //	Numar2->numarInString();        //  -||-
				Rezultat->numarInString();
				StringRezultatOperatii=Rezultat->rezultat;

				delete Numar1;
				delete Numar2;
				delete Rezultat;
				break;
			 case 2:
				Numar1 = new numarMare;
				Numar2 = new numarMare;
				Rezultat = new numarMare;

				Numar1->stringInNumar(NumarDinEdit1);
				Numar2->stringInNumar(NumarDinEdit2);
				operatii::scadere(Numar1, Numar2, Rezultat);
			   //	Numar1->numarInString();
			   //	Numar2->numarInString();
				Rezultat->numarInString();
				StringRezultatOperatii=Rezultat->rezultat;

				delete Numar1;
				delete Numar2;
				delete Rezultat;
				break;
			 case 3:
				Numar1 = new numarMare;
				Numar2 = new numarMare;
				Rezultat = new numarMare;

				Numar1->stringInNumar(NumarDinEdit1);
				Numar2->stringInNumar(NumarDinEdit2);
				operatii::inmultire(Numar1, Numar2, Rezultat);
			   //	Numar1->numarInString();
			  //	Numar2->numarInString();
				Rezultat->numarInString();
				StringRezultatOperatii=Rezultat->rezultat;

				delete Numar1;
				delete Numar2;
				delete Rezultat;
				break;
			 case 0:
				Rezultat->rezultat="acest mesaj nu ar fi trebuit sa apara!";
				break;
	   }
}
