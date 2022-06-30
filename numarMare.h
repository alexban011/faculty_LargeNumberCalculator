//---------------------------------------------------------------------------

#ifndef numarMareH
#define numarMareH
#include <string>
#include <cstring>
#include <vcl.h>
//---------------------------------------------------------------------------
class numarMare{
	   public:
			int cifreInversate[200];
			String numarString;
			String rezultat;
			numarMare();
			numarMare(String numarString);
			int StringInInt(char s);
            char IntInString(int cifra);
			void numarInString();
			void stringInNumar(String Snumar);

};

#endif
