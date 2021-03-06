/*
das Programm liest fuer 4 Fahrzeuge daten ein und gibt diese wieder aus


*/



#include "head.h"





//eingabe der Daten
void EingabeDaten(fahrzeug * daten){
int FahrzeugNo=0;  //Zählvariable fuer die Fahrzeuge
char temp;  //temp zum leeren des tastaturbuffers
//lese alle Daten fuer jedes Fahrzeug ein
   for(FahrzeugNo=0;FahrzeugNo<AnzahlFahrzeuge;FahrzeugNo++){
   fflush(stdin);

   printf("Fahrzeug No.%i\n\n",FahrzeugNo);
   printf("Bitte geben sie den Hersteller an und bestaetigen sie ihre Eingabe mit der EnterTaste\n");
   (daten+FahrzeugNo)->hersteller=zeichenketteEinlesen();
   printf("Bitte geben sie das modell an und bestaetigen sie ihre Eingabe mit der EnterTaste\n");
   (daten+FahrzeugNo)->modell=zeichenketteEinlesen();
   printf("Bitte geben sie die Seriennummer an und bestaetigen sie ihre Eingabe mit der EnterTaste\n");
   (daten+FahrzeugNo)->seriennummer=zeichenketteEinlesen();

do{
//Eingabeaufforderung
   printf("Bitte geben sie das leerGewiht an und bestaetigen sie ihre Eingabe mit der EnterTaste\n");
//lese Daten ein
  scanf("%i",&(daten+FahrzeugNo)->leerGewicht);
//pruefe auf korrekte Eingabe
if((daten+FahrzeugNo)->leerGewicht<0)printf("Ungueltige Eingabe, muss >0 sein.");
}while((daten+FahrzeugNo)->leerGewicht<0);

do{
//Eingabeaufforderung
   printf("Bitte geben sie die leistung an und bestaetigen sie ihre Eingabe mit der EnterTaste\n");
//lese Daten ein
   scanf("%i",&(daten+FahrzeugNo)->leistung);
//pruefe auf korrekte Eingabe
if((daten+FahrzeugNo)->leistung<0)printf("Ungueltige Eingabe, muss >0 sein.");
}while((daten+FahrzeugNo)->leistung<0);

do{
//Eingabeaufforderung
   printf("Bitte geben sie die AnzahlReifen an und bestaetigen sie ihre Eingabe mit der EnterTaste\n");
//lese Daten ein
   scanf("%i",&(daten+FahrzeugNo)->anzReifen);
//pruefe auf korrekte Eingabe
if((daten+FahrzeugNo)->anzReifen<0)printf("Ungueltige Eingabe, muss >0 sein.");
}while((daten+FahrzeugNo)->anzReifen<0);
//leere tastaturbuffer
temp=getchar();
   }


}

//sortieren der Daten
void fahrzeugSortByID(fahrzeug* daten, int Anzahl){
int FahrzeugNo=0;  //Zählvariable fuer die Fahrzeuge
int Sort=0;         //marker für sortiert ja/nein
fahrzeug temp; //erstelle temporäres strukturarray zum sortieren

//sortiere solange bis alles sortiert ist, d.h. die for schleife läuft durch ohne dass Sort =0 gesetzt wird
do{
//setze marker
Sort=1;
//überprüfe alle Fahrzeuge
for(FahrzeugNo=0;FahrzeugNo<Anzahl-1;FahrzeugNo++){
//schau ob die id des nächsten Fahrzeugs kleiner ist wie die des aktuellen Fahrzeugs (absteigend sortieren)
if(*(daten+FahrzeugNo)->seriennummer<*(daten+FahrzeugNo+1)->seriennummer){
//markiere dass irgendwo noch was unsortiert ist
Sort=0;
//Daten des aktuellen Fahrzeugs zwischenspeichern
temp.hersteller=(daten+FahrzeugNo)->hersteller;
temp.modell=(daten+FahrzeugNo)->modell;
temp.seriennummer=(daten+FahrzeugNo)->seriennummer;
temp.leerGewicht=(daten+FahrzeugNo)->leerGewicht;
temp.leistung=(daten+FahrzeugNo)->leistung;
temp.anzReifen=(daten+FahrzeugNo)->anzReifen;
//überschreibe Daten des Fahrzeug mit dem des nächsten
(daten+FahrzeugNo)->hersteller=(daten+FahrzeugNo+1)->hersteller;
(daten+FahrzeugNo)->modell=(daten+FahrzeugNo+1)->modell;
(daten+FahrzeugNo)->seriennummer=(daten+FahrzeugNo+1)->seriennummer;
(daten+FahrzeugNo)->leerGewicht=(daten+FahrzeugNo+1)->leerGewicht;
(daten+FahrzeugNo)->leistung=(daten+FahrzeugNo+1)->leistung;
(daten+FahrzeugNo)->anzReifen=(daten+FahrzeugNo+1)->anzReifen;
//überschreibe Daten des nächsten Fahrzeugs mit den temporär gespeicherten
(daten+FahrzeugNo+1)->hersteller=temp.hersteller;
(daten+FahrzeugNo+1)->modell=temp.modell;
(daten+FahrzeugNo+1)->seriennummer=temp.seriennummer;
(daten+FahrzeugNo+1)->leerGewicht=temp.leerGewicht;
(daten+FahrzeugNo+1)->leistung=temp.leistung;
(daten+FahrzeugNo+1)->anzReifen=temp.anzReifen;
}

}
}while(Sort==0);






}


   //ausgabe der Daten
void AusgabeDaten(fahrzeug * daten){
   int FahrzeugNo=0;  //Zählvariable fuer die Fahrzeuge

      for(FahrzeugNo=0;FahrzeugNo<AnzahlFahrzeuge;FahrzeugNo++){
        printf("Fahrzeug No%i\n",FahrzeugNo);
        printf("Hersteller:%s\n",(daten+FahrzeugNo)->hersteller);
        printf("modell:%s\n",(daten+FahrzeugNo)->modell);
        printf("seriennummer:%s\n",(daten+FahrzeugNo)->seriennummer);
        printf("leerGewicht:%i\n",(daten+FahrzeugNo)->leerGewicht);
        printf("leistung:%i\n",(daten+FahrzeugNo)->leistung);
        printf("anzReifen:%i\n",(daten+FahrzeugNo)->anzReifen);
        printf("\n\n");
}}


int main()
{
int FahrzeugNo=0;  //Zählvariable fuer die Fahrzeuge

//erstelle (struktur)array das AnzahlFahrzeuge fahrzeuge aufnimmt AnzahlFahrzeuge ist in der head.h defined
   fahrzeug f[AnzahlFahrzeuge];

//Eingabe der Daten
    EingabeDaten(f);

//Sortieren der Daten
    fahrzeugSortByID(f,AnzahlFahrzeuge);


//Ausgabe der Daten
    AusgabeDaten(f);

//gebe speicher wieder frei
      for(FahrzeugNo=0;FahrzeugNo<AnzahlFahrzeuge;FahrzeugNo++){
        free(f[FahrzeugNo].hersteller);
        free(f[FahrzeugNo].modell);
        free(f[FahrzeugNo].seriennummer);
}

    return 0;
}
