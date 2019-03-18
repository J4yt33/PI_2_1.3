
 #include <stdio.h>
 #include <stdlib.h>

 #define AnzahlFahrzeuge 3

 //struktur fuer die Fahrzeugdaten
   typedef struct {
    char * hersteller;
    char * modell;
    char * seriennummer;
    int leerGewicht;
    int leistung;
    int anzReifen;
   }fahrzeug;


//funktion zum einlesen der Zeichenketten und erweitern des speichers
char* zeichenketteEinlesen(void){
int ZeichenNo=1;          //zählvariable
char * ZeichenKette='NULL';    //pointer auf die Zeichenkette

ZeichenKette=(char *)calloc(ZeichenNo,sizeof(char));  //reserviere Speicher für 1 Zeichen und eins für das String Ende Zeichen und initialisiere direkt mit 0

//pruefe ob Speicher erfolgreich reserviert wurde
if(ZeichenKette=='NULL'){
printf("Der Speicher konnte nicht reserviert werden.\n");
printf("Bitte bestaetigen sie mit der EnterTaste\n");
scanf("%c",&ZeichenNo);
return;
}

//leere tastaturbuffer
fflush(stdin);



//Lese Solange ein bis das letzte eingegebene Zeichen Enter war war
do{
//erweitere Speicher
ZeichenKette=realloc(ZeichenKette,(ZeichenNo+1)*sizeof(char));

//pruefe ob Speicher erfolgreich reserviert wurde
if(ZeichenKette=='NULL'){
printf("Der Speicher konnte nicht reserviert werden.\n");
printf("Bitte bestaetigen sie mit der EnterTaste\n");
scanf("%c",&ZeichenNo);
return;
}

//lese Zeichen ein
ZeichenKette[ZeichenNo-1]= getchar();
//Zaehle ein Zeichen hoch
ZeichenNo++;

//pruefe ob das letzte eingegebene Zeichen Enter war
}while(ZeichenKette[ZeichenNo-2]!='\n'&&ZeichenKette[ZeichenNo-2]!='\r');

//gebe die Adresse der Zeichenkette zurück
return ZeichenKette;
}
