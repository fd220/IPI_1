#include "fcpp.hh"
#include <string.h> // fuer strlen, Laenge eines C-Strings

using namespace std;
// Definieren Sie hier Ihren Stack und legen Sie eine Instanz als globale
// Variable an
bool error = false;
typedef int element_type;

struct stack_struct{				//create stack
	element_type stack[1000];
	int top = 0;
};

stack_struct s;
// Danach koennen Sie die Funktionen push() und pop() implementieren, die auf dieser
// globalen Variable operieren

void push(element_type e) {			//einfügen
	s.stack[s.top] = e;
	s.top++;
}

element_type pop() {				//herausnehmen
	s.top--;
	if (s.top<0) {cout<<"Nicht genug Zahlen eingegeben!\n"; error=true;}
	return s.stack[s.top];
} 


int main(int argc, char* argv[])
{
  // Setzen Sie hier auf einen leeren Stack

  // fange kein Kommandozeilenargument ab
  if(argc < 2)
  {
    print("Eingabe fÃ¼r den Taschenrechner erwartet!");
    return 1;
  }

  // arg enthaelt die als Eingabe von der Kommandozeile uebergebene Zeichenfolge
  char* arg = argv[1];
	
	bool zahl = false;			//war das letzte eine Zahl?
  // Schleife, die die Zeichen der Eingabe nacheinander ablaeuft
  // strlen gibt die Anzahl der Zeichen in der Zeichenkette
  for (int i = 0; i <= strlen(arg); i = i+1)
  {
    char zeichen = arg[i]; // aktuelles Zeichen
    // Beachten Sie: der Inhalt der Variable zeichen ist der ASCII-Code
    // des entsprechenden Zeichens. Dieser stimmt im Falle der Zeichen '0'..'9'
    // nicht mit der entsprechenden Ziffer Ã¼berein.
    
	if ((int)zeichen==48 || (int)zeichen==49 || (int)zeichen==50 || (int)zeichen==51 || (int)zeichen==52 || (int)zeichen==53 || (int)zeichen==54 || (int)zeichen==55 || (int)zeichen==56 || (int)zeichen==57) {
									//zahlen eingabe
		if (zahl==true)		push(pop()*10+(int)zeichen-48);
		else 				push((int)zeichen-48);
		zahl=true;
	}
	
	else if (zeichen=='*' && arg[i-1]!='/' && arg[i+1]!='/') {		//multiplikation, ohne Kommentare
		push(pop()*pop());
		zahl=false;
	}
	
	else if (zeichen=='/' && arg[i-1]!='*' && arg[i+1]!='*') {		//Division, ohne Kommentare
		push(1/pop()*pop());
		zahl=false;
	}
	
	else if (zeichen=='+') {						//Addition
		push(pop()+pop());
		zahl=false;
	}
	
	else if (zeichen=='-') {						//Subtraktion
		push(-pop()+pop());
		zahl=false;
	}
	
	else {zahl=false;}
    // Fuegen Sie hier Code ein, der das Zeichen verarbeitet, also Ziffern
    // zu Zahlen zusammenfÃ¼gt, Operatoren anwendet und andere Zeichen
    // ignoriert
  }
  if (error==true) {return 1;}
  cout<<"\nDie Lösung ist: "<<pop()<<endl;
  return 0;
}
