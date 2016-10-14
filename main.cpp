#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <conio.h>


using namespace std;

bool statek[10][10];
bool strzal[10][10];
bool zaznaczenia[10][10];
bool strzal_kom[10][10];
int punk,punk_kom;
char wyb;

void zerowanie();
void zaznacz();
void rysuj();
void wylicz();
void zaznaczrysuj();
void ruch();
void atak();
int menu();


int main()
{
    HANDLE hOut;

    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, 15 );

        menu();

}
void zerowanie()
{
    punk=0;
    punk_kom=0;
    for(int i=0;i<10;i++)
    {
       for(int j=0;j<10;j++)
    {
         statek[j][i]=false;
         strzal[j][i]=false;
         zaznaczenia[j][i]=false;
         strzal_kom[j][i]=false;
    }
    }
}
int menu()
{
    for(;;)
    {
        system("pause");
        system("cls");
    cout<<"1.GRAJ"<<endl;
    cout<<"2.WYJ—IE"<<endl;
    wyb=getch();
    system("cls");
    switch(wyb)
    {
      case '1':{
    zerowanie();
    zaznacz();
    wylicz();
    rysuj();
    do
    {
     ruch();
     atak();
     rysuj();
    }while(punk<20&&punk_kom<20);
    }break;
    case '2':{
        return 0;
    }break;
    }
    }

}
void atak()
{
   int iii,jjj;
    srand(time(NULL));
    do
    {


    do
{

 jjj=rand()%10;
 iii=rand()%10;
}while(strzal_kom[jjj][iii]==true);
strzal_kom[jjj][iii]=true;
 if(zaznaczenia[jjj][iii]==true&&strzal_kom[jjj][iii]==true&&punk_kom<20&&punk<20)
 {
    rysuj();
    system("cls");
     if(punk_kom==20)
           {
               system("cls");
           }
 }
    }while(zaznaczenia[jjj][iii]==true&&strzal_kom[jjj][iii]==true&&punk<20&&punk_kom<20);
}
void zaznaczrysuj()
{
HANDLE hOut;

    hOut = GetStdHandle( STD_OUTPUT_HANDLE );

 cout<<"|---|---|---|---|---|---|---|---|---|---|"<<endl;
    for(int j=0;j<=9;j++)
    {

    for(int i=0;i<=9;i++)
    {
    if (zaznaczenia[j][i]==true)
    {
      cout<<"| ";
    SetConsoleTextAttribute( hOut, 2 );
    cout<<"Y ";
    SetConsoleTextAttribute( hOut, 15 );
    }

    else
     cout<<"|"<<j<<","<<i;
    }
    cout<<"|"<<endl<<"|---|---|---|---|---|---|---|---|---|---|"<<endl;
    }
}
void zaznacz()
{
  char ii,jj;
  int iii,jjj;

  for(int i=0;i<20;i++)
  {

  zaznaczrysuj();
    do{
      jj=getch();
      jjj=jj-48;
      ii=getch();
      iii=ii-48;


    if(zaznaczenia[jjj][iii]==true)
    {
     system("cls");
     zaznaczrysuj();
     cout<<"to pole ju? zaznaczy3eo wybierz inne"<<endl;
     }
     if(jjj>=10||iii>=10||jjj<0||iii<0)
     {
     system("cls");
     zaznaczrysuj();
     cout<<"pole z poza zakresem"<<endl;
     }

  }while(zaznaczenia[jjj][iii]==true||jjj>=10||iii>=10||jjj<0||iii<0);
  zaznaczenia[jjj][iii]=true;
  system("cls");
  }
}
void ruch()
{
  char ii,jj;
  int jjj,iii;
  do
  {
   do
  {
      jj=getch();
      jjj=jj-48;
      ii=getch();
      iii=ii-48;

     if(strzal[jjj][iii]==true)
     {
     system("cls");
     rysuj();
     cout<<"to pole ju? zaznaczy3eo wybierz inne"<<endl;
     }
     if(jjj>=10||iii>=10||jjj<0||iii<0)
     {
     system("cls");
     rysuj();
     cout<<"pole z poza zakresem"<<endl;
     }
  }while(strzal[jjj][iii]==true||jjj>=10||iii>=10||jjj<0||iii<0);


  strzal[jjj][iii]=true;
  system("cls");
  if(statek[jjj][iii]==true&&strzal[jjj][iii]==true&&punk<20&&punk_kom<20)
     {
      rysuj();
        if(punk==20)
           {
               system("cls");
           }
     }
  }while(statek[jjj][iii]==true&&strzal[jjj][iii]==true&&punk<20&&punk_kom<20);

}
void wylicz()
{
    int iii,jjj;
    srand(time(NULL));
    for(int i=0;i<20;i++)
{


do
{

 jjj=rand()%10;
 iii=rand()%10;
}while(statek[jjj][iii]==true);
 statek[jjj][iii]=true;


}
}
void rysuj()
{
HANDLE hOut;

    hOut = GetStdHandle( STD_OUTPUT_HANDLE );

        punk=0;
        punk_kom=0;
       cout<<"|---|---|---|---|---|---|---|---|---|---|    |-|-|-|-|-|-|-|-|-|-|"<<endl;
    for(int j=0;j<=9;j++)
    {

    for(int i=0;i<=9;i++)
    {
        if(statek[j][i]==true&&strzal[j][i]==true)
        {
            punk++;
            cout<<"| ";
            SetConsoleTextAttribute( hOut, 4 );

            cout<<"X ";
            SetConsoleTextAttribute( hOut, 15 );

        }
        else if(strzal[j][i]==true)
        {
          cout<<"| ";
          SetConsoleTextAttribute( hOut, 1 );
          cout<<"O ";
          SetConsoleTextAttribute( hOut, 15 );

        }
        else
         {
             cout<<"|"<<j<<","<<i;
         }

    }
    cout<<"|    ";
    for(int i=0;i<=9;i++)
    {
        if(zaznaczenia[j][i]==true&&strzal_kom[j][i]==true)
        {
           cout<<"|";
           SetConsoleTextAttribute( hOut, 4 );
           cout<<"X";
           SetConsoleTextAttribute( hOut, 15 );
           punk_kom++;
        }
        else if(strzal_kom[j][i]==true){
           cout<<"|";
        SetConsoleTextAttribute( hOut, 1 );
        cout<<"O";
        SetConsoleTextAttribute( hOut, 15 );
        }


        else if(zaznaczenia[j][i]==true)
        {
          cout<<"|";
        SetConsoleTextAttribute( hOut, 2 );
        cout<<"Y";
        SetConsoleTextAttribute( hOut, 15 );
        }

        else
        cout<<"| ";
    }

    cout<<"|"<<endl<<"|---|---|---|---|---|---|---|---|---|---|    |-|-|-|-|-|-|-|-|-|-|"<<endl;

    }
    cout<<"TY: "<<punk<<" PRZECIWNIK: "<<punk_kom<<endl;
    if(punk==5&&punk_kom==20)
    {
       cout<<"REMIS"<<endl;
    }
    else if(punk_kom==20)
    {
        cout<<"PRZEGRYWASZ"<<endl;
    }
    else if(punk==20)
    {
     cout<<"WYGRYWASZ"<<endl;
    }


}
