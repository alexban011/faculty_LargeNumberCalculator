//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "operatii.h"
#include "numarMare.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
operatii *obiectOperatii = new operatii;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TForm2::exitClick(TObject *Sender)
{
    delete obiectOperatii;
	Application -> Terminate();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::calculeazaNumarulClick(TObject *Sender)
{
      rezultat->Caption = "";
	  //String numarStringUnit2 = AnsiString(numar1->Text).c_str();

	  obiectOperatii->NumarDinEdit1 = AnsiString(numar1->Text).c_str();
	  obiectOperatii->NumarDinEdit2 = AnsiString(numar2->Text).c_str();     // acm am numerele in obiectul de operatii

	  if(obiectOperatii->selectieOperatie != 0){
		   obiectOperatii->selectareOperatie(obiectOperatii->selectieOperatie);  //calculeaza daca s a selectat operatia
		   rezultat->Caption = obiectOperatii->StringRezultatOperatii;
	  }else{
          rezultat->Caption = "Nu s-a selectat operatia!";
      }

			  //pune rezultatul


}

//---------------------------------------------------------------------------

void __fastcall TForm2::plusClick(TObject *Sender)
{
	obiectOperatii->selectieOperatie=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::minusClick(TObject *Sender)
{
	obiectOperatii->selectieOperatie=2;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::oriClick(TObject *Sender)
{
	obiectOperatii->selectieOperatie=3;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::numar1Change(TObject *Sender)
{
	//obiectOperatii->NumarDinEdit1 = numar1->Text;
}
//---------------------------------------------------------------------------

