
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

class zaidejas
{
  private:
    int carrier, battleship, cruiser, submarine, destroyer, skaicius, laivo_ilgis, indeksas=0; //laivu pavadinimai , laivo statymo koordinaciu skaicius, laivo ilgiui isiminti, laivo statymo koordinaciu raide(indeksas)
    string laivas;  //kuriuos laivus reikia spausdinti
    char kryptis, raide;  //kuria kryptimi stayti laivus ir laivo statymo koordinaciu raide
  public:
  string lentele[12][12]; //lenteles uzpildymui
    void zaidejo_lentele()  //zaidejo lenteles uzpildymas
    {
      for(int a=1; a<=10; a++)
      {
        for(int b=1; b<=10; b++)
        {
          lentele[a][b]="{ }";
        }
      }
    }

    void zaidejo_lenteles_spausdinimas()  //zaidejo lenteles spausdinimas
    {
      cout<<"            JUSU LENTA: "<<endl;
      cout<<"   A  B  C  D  E  F  G  H  I  J"<<endl;
      for(int a=1; a<=10; a++)
      {
        cout<<setw(2)<<a;
        for(int b=1; b<=10; b++)
        {
          cout<<lentele[a][b];
        }
        cout<<endl;
      }
    }

    void laivu_ivedimas()  //zaidejo laivu ivedimas
    {
      carrier=1;
      battleship=1;
      cruiser=1;
      submarine=1;
      destroyer=1;
    }

    void laivu_uzpildymas()  //laivu uzpildymas zaidejo lenteleje
    {
      zaidejo_lentele();
      laivu_ivedimas();
      zaidejo_lenteles_spausdinimas();
      while(tikrinimas())
      {
        laivu_spausdinimas();
        laivu_uzimtumas();
        laivu_kryptis();
        laivu_koordinates();
        system("cls");
        zaidejo_lenteles_spausdinimas();
      }
      system("cls");
      isvalyti_kliutis();
      zaidejo_lenteles_spausdinimas();
    }

    void laivu_spausdinimas()
    {
      cout<<"Jusu turimi laivai: "<<endl;
      if(carrier==1) cout<<"carrier (5 langeliu)"<<endl;
      if(battleship==1) cout<<"battleship (4 langeliu)"<<endl;
      if(cruiser==1) cout<<"cruiser (3 langeliu)"<<endl;
      if(submarine==1) cout<<"submarine (3 langeliu)"<<endl;
      if(destroyer==1) cout<<"destroyer (2 langeliu)"<<endl;
    }

    bool laivu_uzimtumas()  //tikrinti kurie laivai yra laisvi
    {
      cout<<"Pasirinkite kuri laiva norite statyti:  ";
      cin>>laivas;
      if(laivas=="carrier")
      {
        if(carrier==1)
        {
          carrier--;
          laivo_ilgis=5;
          return true;
        }
        else {
          cout<<"Laivas jau pastatytas, bandykite dar karta!"<<endl;
          laivu_uzimtumas();
        }
      }

      else if(laivas=="battleship")
      {
        if(battleship==1)
        {
          battleship--;
          laivo_ilgis=4;
          return true;
        }
        else {
          cout<<"Laivas jau pastatytas, bandykite dar karta!"<<endl;
          laivu_uzimtumas();
        }
      }

      else if(laivas=="cruiser")
      {
        if(cruiser==1)
        {
          cruiser--;
          laivo_ilgis=3;
          return true;
        }
        else {
          cout<<"Laivas jau pastatytas, bandykite dar karta!"<<endl;
          laivu_uzimtumas();
        }
      }

      else if(laivas=="submarine")
      {
        if(submarine==1)
        {
          submarine--;
          laivo_ilgis=3;
          return true;
        }
        else {
          cout<<"Laivas jau pastatytas, bandykite dar karta!"<<endl;
          laivu_uzimtumas();
        }
      } 

      else if(laivas=="destroyer")
      {
        if(destroyer==1)
        {
          destroyer--;
          laivo_ilgis=2;
          return true;
        }
        else {
          cout<<"Laivas jau pastatytas, bandykite dar karta!"<<endl;
          laivu_uzimtumas();
        }
      }
      else if(laivas!="carrier" && laivas!="battleship" && laivas!="cruiser" && laivas!="submarine" && laivas!="destroyer")
      {
        cout<<"Blogai ivedete laivo pavadinima! pabandykite ivesti is naujo!"<<endl;
        laivu_uzimtumas();

      }
     return false;
    }

    bool tikrinimas() //tikrina ar visi laivai yra pastatyti
    {
      if(carrier+battleship+cruiser+submarine+destroyer>0) return true;
        else return false;
    }

    void laivu_kryptis() //krypties nustatymas ir uzpildymas leneteleje
    {
      cout<<"Issirinkite ar statysite laiva vertikaliai ar horizontaliai (v, h):  ";
      cin>>kryptis;
      if(kryptis!='v' && kryptis!='h') {
        cout<<"blogai ivedete krypti! pabandykite dar karta!"<<endl;
        laivu_kryptis();
      }
    }

    void laivu_koordinates()
    {
      cout<<"Issirinkite koordinates ivesdami skaiciu tuomet raide kur jusu laivas stoves:  ";
      cin>>skaicius>>raide;
      if(skaicius>10 || skaicius<1) {
          cout<<"blogai ivedete koordinaciu skaiciu! pabandykite dar karta!"<<endl;
          laivu_koordinates();
      }
      if(raide=='a' || raide=='A') indeksas=1;
        else if(raide=='b' || raide=='B') indeksas=2;
          else if(raide=='c' || raide=='C') indeksas=3;
            else if(raide=='d' || raide=='D') indeksas=4;
              else if(raide=='e' || raide=='E') indeksas=5;
                else if(raide=='f' || raide=='F') indeksas=6;
                  else if(raide=='g' || raide=='G') indeksas=7;
                    else if(raide=='h' || raide=='H') indeksas=8;
                      else if(raide=='i' || raide=='I') indeksas=9;
                        else if(raide=='j' || raide=='J') indeksas=10;
                          else if(indeksas==0) {
        cout<<"Blogai ivede koordinates raide! pabandykite is naujo!"<<endl;
        laivu_koordinates();
      }
      if(kryptis=='v') {
        if(skaicius-laivo_ilgis>=0) {
          for(int a=0; a<laivo_ilgis; a++) {                                          //tikrina ar kertasi laivai
           if(lentele[skaicius-a][indeksas]=="{$}" || lentele[skaicius-a][indeksas]=="{*}" || lentele[skaicius+1][indeksas]=="{$}") {
            cout<<"blogos koordinates, laivas negali kirsti kito laivo koordinaciu! pabandykite dar karta!"<<endl;
            laivu_koordinates();
            break;
            }
         }
         lentele[skaicius+1][indeksas]="{*}";              //uzpildo kliutimis
         lentele[skaicius-laivo_ilgis][indeksas]="{*}";
         for(int a=skaicius; a>skaicius-laivo_ilgis; a--) {                   //uzpildo lentele pastatytus laivus
            lentele[a][indeksas]="{$}";
         }
         for(int a=skaicius+1; a>=skaicius-laivo_ilgis; a--) {  //uzpildo kliutimis
           lentele[a][indeksas-1]="{*}";
         }
         for(int a=skaicius+1; a>=skaicius-laivo_ilgis; a--) {  //uzpildo kliutimis
           lentele[a][indeksas+1]="{*}";
         }
        }
        else {
          cout<<"blogos koordinates, laivas yra uz lenteles rybu! pabandykite dar karta!"<<endl;
          laivu_koordinates();
        }
      }
      if(kryptis=='h') {
        if(indeksas+laivo_ilgis-1<=10) {
          for(int a=0; a<laivo_ilgis; a++) {
            if(lentele[skaicius][indeksas+a]=="{$}" || lentele[skaicius][indeksas+a]=="{*}"|| lentele[skaicius][indeksas-1]=="{$}") {
              cout<<"Blogos koordinates, laivas negali kirsti kito laivo koordinaciu! pabandykite dar karta!"<<endl;
              laivu_koordinates();
              break;
            } 
          }
         lentele[skaicius][indeksas-1]="{*}";              //uzpildo kliutimis
         lentele[skaicius][indeksas+laivo_ilgis]="{*}";
         for(int a=indeksas; a<indeksas+laivo_ilgis; a++) {
            lentele[skaicius][a]="{$}";
          }
          for(int a=indeksas-1; a<=indeksas+laivo_ilgis; a++) {
            lentele[skaicius+1][a]="{*}";                                           //uzpildo kliutimis
            lentele[skaicius-1][a]="{*}";
          }
        }
        else {
          cout<<"blogos koordinates, laivas yra uz lenteles rybu! pabandykite dar karta!"<<endl;
          laivu_koordinates();
        }
      }
    }
    void isvalyti_kliutis()
    {
      for(int a=1; a<=10; a++)
      {
        for(int b=1; b<=10; b++)
        {
          if(lentele[a][b]=="{*}") lentele[a][b]="{ }";
        }
      }
    }
};

class kompiuteris : public zaidejas{
  private:
    int kompiuterio_laivo_ilgis, kompiuterio_kryptis, kompiuterio_statymo_skaicius, kompiuterio_statymo_raide, kompiuterio_indeksas=0;          //laivo ilgiui saugoti, ar statys vertikaliai ar horizontaliai, kurioj eilutej statyti laiva, kuriam stulpeli statyti laiva
    string kompiuterio_laivo_pav;         //laivo pavadinimui saugoti
  public:
  string kompiuterio_lentele[11][11], atsargine[11][11];           //lenteles uzpildymui ir atsargini lentele
  void kompiuterio_lentele_ivedimas()              //kompiuterio lenteles uzpildymas
  {
    for(int a=1; a<=10; a++)
      {
        for(int b=1; b<=10; b++)
        {
          kompiuterio_lentele[a][b]="{ }";
          atsargine[a][b]="{ }";
        }
      }
  }
  void kompiuterio_lenteles_spausdinimas()  //kompiuterio lenteles spausdinimas
    {
      cout<<"   A  B  C  D  E  F  G  H  I  J"<<endl;
      for(int a=1; a<=10; a++)
      {
        cout<<setw(2)<<a;
        for(int b=1; b<=10; b++)
        {
          cout<<kompiuterio_lentele[a][b];
        }
        cout<<endl;
      }
    }
  void kompiuterio_laivu_uzpildymas()                    //suvedamos visos funkcijos kompiuterio laivams lenteleje uzpildyti
  {
    srand(time(NULL));
    kompiuterio_lentele_ivedimas();
    carrier_pastatymas();
    battleship_pastatymas();
    cruiser_pastatymas();
    submarine_pastatymas();
    destroyer_pastatymas();
    isvalyti_kompiuterio_kliutis();
    kompiuterio_lenteles_spausdinimas();
    atsargines_spausdinimas();
  }
  void carrier_pastatymas()                             //laivo carrier pastatymas
  {
    kompiuterio_laivo_pav="carrier";
    kompiuterio_laivo_ilgis=5;
    kompiuterio_kryptis=(rand()%2);
    kompiuterio_laivu_statymas();
  }
  void battleship_pastatymas()                         //laivo battleship pastatymas
  {
    kompiuterio_laivo_pav="battleship";
    kompiuterio_laivo_ilgis=4;
    kompiuterio_kryptis=(rand()%2);
    kompiuterio_laivu_statymas();
  }
  void cruiser_pastatymas()                             //laivo cruiser pastatymas
  {
    kompiuterio_laivo_pav="cruiser";
    kompiuterio_laivo_ilgis=3;
    kompiuterio_kryptis=(rand()%2);
    kompiuterio_laivu_statymas();
  }
  void submarine_pastatymas()                           //laivo submarine pastatymas
  {
    kompiuterio_laivo_pav="submarine";
    kompiuterio_laivo_ilgis=3;
    kompiuterio_kryptis=(rand()%2);
    kompiuterio_laivu_statymas();
  }
  void destroyer_pastatymas()                           //laivo destroyer pastatymas
  {
    kompiuterio_laivo_pav="destroyer";
    kompiuterio_laivo_ilgis=2;
    kompiuterio_kryptis=(rand()%2);
    kompiuterio_laivu_statymas();
  }
  void kompiuterio_laivu_statymas()                     //laivu irasimas i lentele
  {
    kompiuterio_statymo_skaicius=(rand()%10)+1;
    if(kompiuterio_statymo_skaicius>10 || kompiuterio_statymo_skaicius<1) kompiuterio_laivu_statymas();
    kompiuterio_statymo_raide=(rand()%10)+1;
    if(kompiuterio_statymo_raide==1) kompiuterio_indeksas=1;
        else if(kompiuterio_statymo_raide==2) kompiuterio_indeksas=2;
          else if(kompiuterio_statymo_raide==3) kompiuterio_indeksas=3;
            else if(kompiuterio_statymo_raide==4) kompiuterio_indeksas=4;
              else if(kompiuterio_statymo_raide==5) kompiuterio_indeksas=5;
                else if(kompiuterio_statymo_raide==6) kompiuterio_indeksas=6;
                  else if(kompiuterio_statymo_raide==7) kompiuterio_indeksas=7;
                    else if(kompiuterio_statymo_raide==8) kompiuterio_indeksas=8;
                      else if(kompiuterio_statymo_raide==9) kompiuterio_indeksas=9;
                        else if(kompiuterio_statymo_raide==10) kompiuterio_indeksas=10;
                          else if(kompiuterio_indeksas==0) kompiuterio_laivu_statymas();
    if(kompiuterio_kryptis==0) {
      laivo_statymas_vertikaliai();
    }
      else {
        laivo_statymas_horizontaliai();
      }
  }
  void laivo_statymas_vertikaliai()
  {
    if(kompiuterio_statymo_skaicius-kompiuterio_laivo_ilgis<1) kompiuterio_laivu_statymas();
      else {
        for(int a=0; a<kompiuterio_laivo_ilgis; a++) {                                          //tikrina ar kertasi laivai
           if(kompiuterio_lentele[kompiuterio_statymo_skaicius-a][kompiuterio_indeksas]=="{$}" || kompiuterio_lentele[kompiuterio_statymo_skaicius-a][kompiuterio_indeksas]=="{*}" || kompiuterio_lentele[kompiuterio_statymo_skaicius+1][kompiuterio_indeksas]=="{$}") {
             kompiuterio_laivu_statymas();
             break;
            }
         }
       kompiuterio_lentele[kompiuterio_statymo_skaicius+1][kompiuterio_indeksas]="{*}";              //uzpildo kliutimis
       kompiuterio_lentele[kompiuterio_statymo_skaicius-kompiuterio_laivo_ilgis][kompiuterio_indeksas]="{*}";
        for(int a=kompiuterio_statymo_skaicius; a>kompiuterio_statymo_skaicius-kompiuterio_laivo_ilgis; a--) {
            kompiuterio_lentele[a][kompiuterio_indeksas]="{$}";
          }
      for(int a=kompiuterio_statymo_skaicius+1; a>=kompiuterio_statymo_skaicius-kompiuterio_laivo_ilgis; a--) {
          kompiuterio_lentele[kompiuterio_statymo_skaicius][kompiuterio_indeksas+1]="{*}";
          kompiuterio_lentele[kompiuterio_statymo_skaicius][kompiuterio_indeksas-1]="{*}";
        }
      }
  }
  void laivo_statymas_horizontaliai()
  {
    if(kompiuterio_indeksas+kompiuterio_laivo_ilgis-1>10) kompiuterio_laivu_statymas();
        else {
          for(int a=0; a<kompiuterio_laivo_ilgis; a++) {                                    //tikrina ar kertasi laivai
            if(kompiuterio_lentele[kompiuterio_statymo_skaicius][kompiuterio_indeksas+a]=="{$}" || kompiuterio_lentele[kompiuterio_statymo_skaicius][kompiuterio_indeksas+a]=="{*}" || kompiuterio_lentele[kompiuterio_statymo_skaicius][kompiuterio_indeksas-1]=="{$}") {
              kompiuterio_laivu_statymas();
              break;
            } 
          }
         kompiuterio_lentele[kompiuterio_statymo_skaicius][kompiuterio_indeksas-1]="{*}";              //uzpildo kliutimis
         kompiuterio_lentele[kompiuterio_statymo_skaicius][kompiuterio_indeksas+kompiuterio_laivo_ilgis]="{*}"; 
          for(int a=kompiuterio_indeksas; a<kompiuterio_indeksas+kompiuterio_laivo_ilgis; a++) {
            kompiuterio_lentele[kompiuterio_statymo_skaicius][a]="{$}";
          }
          for(int a=kompiuterio_indeksas; a<=kompiuterio_indeksas+kompiuterio_laivo_ilgis; a++) {
            kompiuterio_lentele[kompiuterio_statymo_skaicius+1][a]="{*}";
            kompiuterio_lentele[kompiuterio_statymo_skaicius-1][a]="{*}";
          }
        }
  }
  void isvalyti_kompiuterio_kliutis()
    {
      for(int a=1; a<=10; a++)
      {
        for(int b=1; b<=10; b++)
        {
          if(kompiuterio_lentele[a][b]=="{*}") kompiuterio_lentele[a][b]="{ }";
        }
      }
    }
    void atsargines_spausdinimas()                                //atsargines lenteles kuria matys zaidejas
    {
      cout<<"       KOMPIUTERIO LENTA:"<<endl;
      cout<<"   A  B  C  D  E  F  G  H  I  J"<<endl;
      for(int a=1; a<=10; a++)
      {
        cout<<setw(2)<<a;
        for(int b=1; b<=10; b++)
        {
          cout<<atsargine[a][b];
        }
        cout<<endl;
      }
    }
};

class zaidimas : public kompiuteris
{
  private:
  int kas_pirmas, koord_skaicius, zaidimo_indeksas=0; //kas pirmas prades ejima
  int zaidejo_kiek, kompiuterio_kiek, kompiuterio_puolimo_sk, kompiuterio_puolimo_raide, kompiuterio_puolimo_indeksas=0;
  int kompiuterio_laivas_nuskendo, jus_pataikete, jus_nepataikete, zaidejo_laivas_nuskendo, kompiuteris_pataike, kompiuteris_nepataike;
  char koord_raide;
  int kompiuterio_puolimo_rodiklis=0, random, kaire=0, desine=0, apacia=0, virsus=0, kompiuterio_puolimo_kiek=1;
  int isiminti_puolimo_sk, isiminti_puolimo_indeksa;
  public:
  void zaidejo_ejimas()
  {
    cout<<"issirinkite koordinates kuriomis atakuosite priesininka, pirmai ivesdami skaiciu tuomet raide:  ";
    cin>>koord_skaicius>>koord_raide;
    if(koord_skaicius>10 || koord_skaicius<1) {
      cout<<"blogai ivedete koordinaciu skaiciu! pabandykite dar karta!"<<endl;
      zaidejo_ejimas();
    }
    if(koord_raide=='a' || koord_raide=='A') zaidimo_indeksas=1;
        else if(koord_raide=='b' || koord_raide=='B') zaidimo_indeksas=2;
          else if(koord_raide=='c' || koord_raide=='C') zaidimo_indeksas=3;
            else if(koord_raide=='d' || koord_raide=='D') zaidimo_indeksas=4;
              else if(koord_raide=='e' || koord_raide=='E') zaidimo_indeksas=5;
                else if(koord_raide=='f' || koord_raide=='F') zaidimo_indeksas=6;
                  else if(koord_raide=='g' || koord_raide=='G') zaidimo_indeksas=7;
                    else if(koord_raide=='h' || koord_raide=='H') zaidimo_indeksas=8;
                      else if(koord_raide=='i' || koord_raide=='I') zaidimo_indeksas=9;
                        else if(koord_raide=='j' || koord_raide=='J') zaidimo_indeksas=10;
                          else if(zaidimo_indeksas==0) {
        cout<<"Blogai ivede koordinates raide! pabandykite dar karta!"<<endl;
        zaidejo_ejimas();
      }
      zaidejo_puolimas();
  }
  void kompiuterio_ejimas()
  {
    if(kompiuterio_puolimo_rodiklis==0) {
    kompiuterio_puolimo_sk=(rand()%10)+1;
    if(kompiuterio_puolimo_sk>10 || kompiuterio_puolimo_sk<1) kompiuterio_ejimas();
    kompiuterio_puolimo_raide=(rand()%10)+1;
    if(kompiuterio_puolimo_raide==1) kompiuterio_puolimo_indeksas=1;
        else if(kompiuterio_puolimo_raide==2) kompiuterio_puolimo_indeksas=2;
          else if(kompiuterio_puolimo_raide==3) kompiuterio_puolimo_indeksas=3;
            else if(kompiuterio_puolimo_raide==4) kompiuterio_puolimo_indeksas=4;
              else if(kompiuterio_puolimo_raide==5) kompiuterio_puolimo_indeksas=5;
                else if(kompiuterio_puolimo_raide==6) kompiuterio_puolimo_indeksas=6;
                  else if(kompiuterio_puolimo_raide==7) kompiuterio_puolimo_indeksas=7;
                    else if(kompiuterio_puolimo_raide==8) kompiuterio_puolimo_indeksas=8;
                      else if(kompiuterio_puolimo_raide==9) kompiuterio_puolimo_indeksas=9;
                        else if(kompiuterio_puolimo_raide==10) kompiuterio_puolimo_indeksas=10;
                          else if(kompiuterio_puolimo_indeksas==0) kompiuterio_ejimas();
    kompiuterio_puolimas();
    }
      else if(kompiuterio_puolimo_rodiklis==1) kompiuterio_puolimas_vienas();
        else if(kompiuterio_puolimo_rodiklis==2) kompiuterio_puolimas_du();
          else if(kompiuterio_puolimo_rodiklis==3) kompiuterio_puolimas_trys();
            else if(kompiuterio_puolimo_rodiklis==4) kompiuterio_puolimas_keturi();
  }
  void zaidimo_eiga()
  {
    while(zaidimo_tikrinimas())
    {
      zaidejo_ejimas();
      kompiuterio_ejimas();
      system("cls");
      zaidejo_lenteles_spausdinimas();
      kompiuterio_lenteles_spausdinimas();
      atsargines_spausdinimas();
      if(kompiuterio_laivas_nuskendo==1) cout<<"Jus nuskandinote priesininko laiva!"<<endl;
        else if(jus_pataikete==1) cout<<"Jus pataikete!"<<endl;
          else if(jus_nepataikete==1) cout<<"Jus nepataikete!"<<endl;
      if(kompiuteris_pataike==1) cout<<"Kompiuteris pataike i jusu laiva!"<<endl;
        else if(kompiuteris_nepataike==1) cout<<"Kompiuteris nepataike!"<<endl;
          else if(zaidejo_laivas_nuskendo==1) cout<<"Kompiuteris nuskandino jusu laiva!"<<endl;
    }
    kas_laimejo();
  }
  bool zaidimo_tikrinimas()
  {
    zaidejo_kiek=0, kompiuterio_kiek=0;
    for(int a=1; a<=10; a++)
      {
        for(int b=1; b<=10; b++)
        {
          if(lentele[a][b]=="{$}") zaidejo_kiek++;
          if(kompiuterio_lentele[a][b]=="{$}") kompiuterio_kiek++;
        }
      }
      if(zaidejo_kiek>0 && kompiuterio_kiek>0) return true;
        else return false;
  }
  void zaidejo_puolimas()
  {
    kompiuterio_laivas_nuskendo=0, jus_pataikete=0, jus_nepataikete=0;
    if(atsargine[koord_skaicius][zaidimo_indeksas]=="{+}") {
      cout<<"I sia koordinate jau sovete! pabandykite dar karta!"<<endl;
      zaidejo_ejimas();
    }
      else {
    if(kompiuterio_lentele[koord_skaicius][zaidimo_indeksas]=="{$}")
    {
      if(kompiuterio_lentele[koord_skaicius+1][zaidimo_indeksas]=="{$}" || kompiuterio_lentele[koord_skaicius-1][zaidimo_indeksas]=="{$}" || kompiuterio_lentele[koord_skaicius][zaidimo_indeksas+1]=="{$}" || kompiuterio_lentele[koord_skaicius][zaidimo_indeksas-1]=="{$}")
      {
         atsargine[koord_skaicius][zaidimo_indeksas]="{+}";
      kompiuterio_lentele[koord_skaicius][zaidimo_indeksas]="{!}";
      jus_pataikete++;
      }
        else{
          atsargine[koord_skaicius][zaidimo_indeksas]="{+}";
      kompiuterio_lentele[koord_skaicius][zaidimo_indeksas]="{!}";
      kompiuterio_laivas_nuskendo++;
        }
    }
      else {
        atsargine[koord_skaicius][zaidimo_indeksas]="{.}";
        jus_nepataikete++;
      }
    }
  }
  void kompiuterio_puolimas(){
    zaidejo_laivas_nuskendo=0, kompiuteris_pataike=0, kompiuteris_nepataike=0;
    if(lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas]=="{$}")
    {
      lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_raide]="{!}";
      kompiuteris_pataike++;
      kompiuterio_puolimo_rodiklis=1;
    }
      else if(lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas]=="{!}" || lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas]=="{.}") kompiuterio_ejimas();
      else {
        lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas]="{.}";
        kompiuteris_nepataike++;
      }
  }
  void kompiuterio_puolimas_vienas()
  {
    zaidejo_laivas_nuskendo=0, kompiuteris_pataike=0, kompiuteris_nepataike=0;
    random=(rand()%4)+1;
    if(random==1) {
      if(kaire==1) kompiuterio_puolimas_vienas();
        else if(kaire==0) kaire++;
    }
      else if(random==2) {
        if(desine==1) kompiuterio_puolimas_vienas();
          else if(desine==0) desine++;
      }
        else if(random==3){
          if(apacia==1) kompiuterio_puolimas_vienas();
            else if(apacia==0) apacia++;
        }
          else if(random==4) {
            if(virsus==1) kompiuterio_puolimas_vienas();
              else if(virsus==0) virsus++;
          }
    if(kaire==1) {
      if(lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas-1]=="{$}" && lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas+1]=="{$}") {
        kompiuteris_pataike++;
        kompiuterio_puolimo_rodiklis=3;
        isiminti_puolimo_sk=kompiuterio_puolimo_sk;
        isiminti_puolimo_indeksa=kompiuterio_puolimo_indeksas;
        kompiuterio_puolimo_kiek++;
        lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas-1]="{!}";
        kaire=5;
      }
        else if(lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas-1]=="{$}") {
          if(lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas-2]=="{$}") {
            kompiuteris_pataike++;
            kompiuterio_puolimo_rodiklis=2;
            kompiuterio_puolimo_kiek++;
            lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas-1]="{!}";
            kaire=20;
          }
            else if(lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas-1]!="{$}") {
              lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas-1]="{.}";
              kaire=2;
            }
            else {
              zaidejo_laivas_nuskendo++;
              kompiuterio_puolimo_rodiklis=0;
              kompiuterio_puolimo_kiek=1;
              kaire=0;
            }
        }
    }
    else if(desine==1) {
      if(lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas+1]=="{$}" && lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas-1]=="{$}") {
        kompiuteris_pataike++;
        kompiuterio_puolimo_rodiklis=3;
        isiminti_puolimo_sk=kompiuterio_puolimo_sk;
        isiminti_puolimo_indeksa=kompiuterio_puolimo_indeksas;
        kompiuterio_puolimo_kiek++;
        lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas+1]="{!}";
        desine=5;
      }
        else if(lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas+1]=="{$}") {
          if(lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas+2]=="{$}") {
            kompiuteris_pataike++;
            kompiuterio_puolimo_rodiklis=2;
            kompiuterio_puolimo_kiek++;
            lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas+1]="{!}";
            desine=20;
          }
          else if(lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas+1]!="{$}") {
              lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas+1]="{.}";
              desine=2;
            }
            else {
              zaidejo_laivas_nuskendo++;
              kompiuterio_puolimo_rodiklis=0;
              kompiuterio_puolimo_kiek=1;
              desine=0;
            }
        }
    }
    else if(apacia==1) {
      if(lentele[kompiuterio_puolimo_sk+1][kompiuterio_puolimo_indeksas]=="{$}" && lentele[kompiuterio_puolimo_sk-1][kompiuterio_puolimo_indeksas]=="{$}") {
        kompiuteris_pataike++;
        kompiuterio_puolimo_rodiklis=3;
        isiminti_puolimo_sk=kompiuterio_puolimo_sk;
        isiminti_puolimo_indeksa=kompiuterio_puolimo_indeksas;
        kompiuterio_puolimo_kiek++;
        lentele[kompiuterio_puolimo_sk+1][kompiuterio_puolimo_indeksas]="{!}";
        apacia=5;
      }
        else if(lentele[kompiuterio_puolimo_sk+1][kompiuterio_puolimo_indeksas]=="{$}") {
          if(lentele[kompiuterio_puolimo_sk+2][kompiuterio_puolimo_indeksas]=="{$}") {
            kompiuteris_pataike++;
            kompiuterio_puolimo_rodiklis=2;
            kompiuterio_puolimo_kiek++;
            lentele[kompiuterio_puolimo_sk+1][kompiuterio_puolimo_indeksas]="{!}";
            apacia=20;
          }
          else if(lentele[kompiuterio_puolimo_sk+1][kompiuterio_puolimo_indeksas]!="{$}") {
              lentele[kompiuterio_puolimo_sk+1][kompiuterio_puolimo_indeksas]="{.}";
              apacia=2;
            }
            else {
              zaidejo_laivas_nuskendo++;
              kompiuterio_puolimo_rodiklis=0;
              kompiuterio_puolimo_kiek=1;
              apacia=0;
            }
        }
    }
    else if(virsus==1) {
      if(lentele[kompiuterio_puolimo_sk-1][kompiuterio_puolimo_indeksas]=="{$}" && lentele[kompiuterio_puolimo_sk+1][kompiuterio_puolimo_indeksas]=="{$}") {
        kompiuteris_pataike++;
        kompiuterio_puolimo_rodiklis=3;
        isiminti_puolimo_sk=kompiuterio_puolimo_sk;
        isiminti_puolimo_indeksa=kompiuterio_puolimo_indeksas;
        kompiuterio_puolimo_kiek++;
        lentele[kompiuterio_puolimo_sk-1][kompiuterio_puolimo_indeksas]="{!}";
        virsus=5;
      }
        else if(lentele[kompiuterio_puolimo_sk-1][kompiuterio_puolimo_indeksas]=="{$}") {
          if(lentele[kompiuterio_puolimo_sk-2][kompiuterio_puolimo_indeksas]=="{$}") {
            kompiuteris_pataike++;
            kompiuterio_puolimo_rodiklis=2;
            kompiuterio_puolimo_kiek++;
            lentele[kompiuterio_puolimo_sk-1][kompiuterio_puolimo_indeksas]="{!}";
            virsus=20;
          }
          else if(lentele[kompiuterio_puolimo_sk-1][kompiuterio_puolimo_indeksas]!="{$}") {
              lentele[kompiuterio_puolimo_sk-1][kompiuterio_puolimo_indeksas]="{.}";
              virsus=2;
            }
            else {
              zaidejo_laivas_nuskendo++;
              kompiuterio_puolimo_rodiklis=0;
              kompiuterio_puolimo_kiek=1;
              virsus=0;
            }
        }
    }
  }
  void kompiuterio_puolimas_du()
  {
    zaidejo_laivas_nuskendo=0, kompiuteris_pataike=0, kompiuteris_nepataike=0;
    if(kaire==20) {
      if(lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas-kompiuterio_puolimo_kiek-1]=="{$}") {
        kompiuteris_pataike++;
        lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas-kompiuterio_puolimo_kiek]="{!}";
        kompiuterio_puolimo_kiek++;
      }
        else {
          zaidejo_laivas_nuskendo++;
          lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas-kompiuterio_puolimo_kiek]="{!}";
          kompiuterio_puolimo_kiek=1;
          kompiuterio_puolimo_rodiklis=0;
          kaire=0;
        }
    }
     else if(desine==20) {
      if(lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas+kompiuterio_puolimo_kiek+1]=="{$}") {
        kompiuteris_pataike++;
        lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas+kompiuterio_puolimo_kiek]="{!}";
        kompiuterio_puolimo_kiek++;
      }
        else {
          zaidejo_laivas_nuskendo++;
          lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas+kompiuterio_puolimo_kiek]="{!}";
          kompiuterio_puolimo_kiek=1;
          kompiuterio_puolimo_rodiklis=0;
          desine=0;
        }
    }
    else if(apacia==20) {
      if(lentele[kompiuterio_puolimo_sk+kompiuterio_puolimo_kiek+1][kompiuterio_puolimo_indeksas]=="{$}") {
        kompiuteris_pataike++;
        lentele[kompiuterio_puolimo_sk+kompiuterio_puolimo_kiek][kompiuterio_puolimo_indeksas]="{!}";
        kompiuterio_puolimo_kiek++;
      }
        else {
          zaidejo_laivas_nuskendo++;
          lentele[kompiuterio_puolimo_sk+kompiuterio_puolimo_kiek][kompiuterio_puolimo_indeksas]="{!}";
          kompiuterio_puolimo_kiek=1;
          kompiuterio_puolimo_rodiklis=0;
          apacia=0;
        }
    }
     else if(virsus==20) {
      if(lentele[kompiuterio_puolimo_sk-kompiuterio_puolimo_kiek-1][kompiuterio_puolimo_indeksas]=="{$}") {
        kompiuteris_pataike++;
        lentele[kompiuterio_puolimo_sk-kompiuterio_puolimo_kiek][kompiuterio_puolimo_indeksas]="{!}";
        kompiuterio_puolimo_kiek++;
      }
        else {
          zaidejo_laivas_nuskendo++;
          lentele[kompiuterio_puolimo_sk-kompiuterio_puolimo_kiek][kompiuterio_puolimo_indeksas]="{!}";
          kompiuterio_puolimo_kiek=1;
          kompiuterio_puolimo_rodiklis=0;
          virsus=0;
        }
    }
  }
  void kompiuterio_puolimas_trys()
  {
    zaidejo_laivas_nuskendo=0, kompiuteris_pataike=0, kompiuteris_nepataike=0;
    if(kaire==5) {
      if(lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas-kompiuterio_puolimo_kiek]=="{$}") {
        kompiuteris_pataike++;
        lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas-kompiuterio_puolimo_kiek]="{!}";
        kompiuterio_puolimo_kiek++;
      }
        else {
          kompiuteris_nepataike++;
          lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas-kompiuterio_puolimo_kiek]="{.}";
          kompiuterio_puolimo_kiek=1;
          kompiuterio_puolimo_rodiklis=4;
        }
    }
    else if(desine==5) {
      if(lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas+kompiuterio_puolimo_kiek]=="{$}") {
        kompiuteris_pataike++;
        lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas+kompiuterio_puolimo_kiek]="{!}";
        kompiuterio_puolimo_kiek++;
      }
        else {
          kompiuteris_nepataike++;
          lentele[kompiuterio_puolimo_sk][kompiuterio_puolimo_indeksas+kompiuterio_puolimo_kiek]="{.}";
          kompiuterio_puolimo_kiek=1;
          kompiuterio_puolimo_rodiklis=4;
        }
    }
    else if(apacia==5) {
      if(lentele[kompiuterio_puolimo_sk+kompiuterio_puolimo_kiek][kompiuterio_puolimo_indeksas]=="{$}") {
        kompiuteris_pataike++;
        lentele[kompiuterio_puolimo_sk+kompiuterio_puolimo_kiek][kompiuterio_puolimo_indeksas]="{!}";
        kompiuterio_puolimo_kiek++;
      }
        else {
          kompiuteris_nepataike++;
          lentele[kompiuterio_puolimo_sk+kompiuterio_puolimo_kiek][kompiuterio_puolimo_indeksas]="{.}";
          kompiuterio_puolimo_kiek=1;
          kompiuterio_puolimo_rodiklis=4;
        }
    }
    else if(virsus==5) {
      if(lentele[kompiuterio_puolimo_sk-kompiuterio_puolimo_kiek][kompiuterio_puolimo_indeksas]=="{$}") {
        kompiuteris_pataike++;
        lentele[kompiuterio_puolimo_sk-kompiuterio_puolimo_kiek][kompiuterio_puolimo_indeksas]="{!}";
        kompiuterio_puolimo_kiek++;
      }
        else {
          kompiuteris_nepataike++;
          lentele[kompiuterio_puolimo_sk-kompiuterio_puolimo_kiek][kompiuterio_puolimo_indeksas]="{.}";
          kompiuterio_puolimo_kiek=1;
          kompiuterio_puolimo_rodiklis=4;
        }
    }
  }
  void kompiuterio_puolimas_keturi()
  {
   zaidejo_laivas_nuskendo=0, kompiuteris_pataike=0, kompiuteris_nepataike=0;
   if(kaire==5) {
     if(lentele[isiminti_puolimo_sk][isiminti_puolimo_indeksa+kompiuterio_puolimo_kiek+1]=="{$}") {
       kompiuteris_pataike++;
       lentele[isiminti_puolimo_sk][isiminti_puolimo_indeksa+kompiuterio_puolimo_kiek]="{!}";
       kompiuterio_puolimo_kiek++;
     }
      else {
        zaidejo_laivas_nuskendo++;
        lentele[isiminti_puolimo_sk][isiminti_puolimo_indeksa+kompiuterio_puolimo_kiek]="{!}";
        kompiuterio_puolimo_kiek=1;
        kompiuterio_puolimo_rodiklis=0;
      }
   } 
    else if(desine==5) {
     if(lentele[isiminti_puolimo_sk][isiminti_puolimo_indeksa-kompiuterio_puolimo_kiek-1]=="{$}") {
       kompiuteris_pataike++;
       lentele[isiminti_puolimo_sk][isiminti_puolimo_indeksa-kompiuterio_puolimo_kiek]="{!}";
       kompiuterio_puolimo_kiek++;
     }
      else {
        zaidejo_laivas_nuskendo++;
        lentele[isiminti_puolimo_sk][isiminti_puolimo_indeksa-kompiuterio_puolimo_kiek]="{!}";
        kompiuterio_puolimo_kiek=1;
        kompiuterio_puolimo_rodiklis=0;
      }
   } 
      else if(apacia==5) {
     if(lentele[isiminti_puolimo_sk-kompiuterio_puolimo_kiek-1][isiminti_puolimo_indeksa]=="{$}") {
       kompiuteris_pataike++;
       lentele[isiminti_puolimo_sk-kompiuterio_puolimo_kiek][isiminti_puolimo_indeksa]="{!}";
       kompiuterio_puolimo_kiek++;
     }
      else {
        zaidejo_laivas_nuskendo++;
        lentele[isiminti_puolimo_sk-kompiuterio_puolimo_kiek][isiminti_puolimo_indeksa]="{!}";
        kompiuterio_puolimo_kiek=1;
        kompiuterio_puolimo_rodiklis=0;
      }
   } 
   else if(virsus==5) {
     if(lentele[isiminti_puolimo_sk+kompiuterio_puolimo_kiek+1][isiminti_puolimo_indeksa]=="{$}") {
       kompiuteris_pataike++;
       lentele[isiminti_puolimo_sk+kompiuterio_puolimo_kiek][isiminti_puolimo_indeksa]="{!}";
       kompiuterio_puolimo_kiek++;
     }
      else {
        zaidejo_laivas_nuskendo++;
        lentele[isiminti_puolimo_sk+kompiuterio_puolimo_kiek][isiminti_puolimo_indeksa]="{!}";
        kompiuterio_puolimo_kiek=1;
        kompiuterio_puolimo_rodiklis=0;
      }
   } 
  }
  void kas_laimejo()
  {
    if(zaidejo_kiek>0 && kompiuterio_kiek==0) cout<<"Sveikiname! jus laimejote! :)"<<endl;
      else if(zaidejo_kiek==0 && kompiuterio_kiek>0) cout<<"Jus pralaimejote! bandykite zaisti is naujo :("<<endl;
  }
};

int main()
{ 
  zaidimas o;
  o.laivu_uzpildymas();
  o.kompiuterio_laivu_uzpildymas();
  o.zaidimo_eiga();
  return 0;
}
