#include <iostream>
#include <sstream>
#include "Nodo.h"


using namespace std;
char gatolol[10]= {'o','1','2','3','4','5','6','7','8','9'};


int checkWin(){
    //horizontal
    if(gatolol[1] == gatolol[2] && gatolol[2] == gatolol[3]){
        return 1;
    }
    else if(gatolol[4] == gatolol[5] && gatolol[5] == gatolol[6]){
        return 1;
    }
    else if(gatolol[7] == gatolol[8] && gatolol[8] == gatolol[9]){
        return 1;
    }
    //vertical
    else if(gatolol[1] == gatolol[4] && gatolol[4] == gatolol[7]){
        return 1;
    }
    else if(gatolol[2] == gatolol[5] && gatolol[5] == gatolol[8]){
        return 1;
    }
    else if(gatolol[3] == gatolol[6] && gatolol[6] == gatolol[9]){
        return 1;
    }
    //diagonal
    else if(gatolol[1] == gatolol[5] && gatolol[5] == gatolol[9]){
        return 1;
    }
    else if(gatolol[7] == gatolol[5] && gatolol[5] == gatolol[3]){
        return 1;
    }
    else if(gatolol[1] !='1' && gatolol[2] !='2' && gatolol[3] !='3' &&
            gatolol[4] !='4' && gatolol[5] !='5' && gatolol[6] !='6' &&
            gatolol[7] !='7' && gatolol[8] !='8' && gatolol[9] !='9' )
            {return 0;}
    else{return -1;}
}
void Tablero(){
    system("cls");
    std::cout <<"\n\n\t EL GATO JUEGO\n\n";
    std::cout <<"Jugador 1(X) - Jugador 2(O)"<<std::endl<<std::endl;
    std::cout<<std::endl;


    cout<<"   |   |   "<<endl;
    cout<<" "<<gatolol[1]<<" | "<< gatolol[2]<<" | "<<gatolol[3]<< endl;
    cout<<"___|___|___"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<" "<<gatolol[4]<<" | "<< gatolol[5]<<" | "<<gatolol[6]<< endl;
    cout<<"___|___|___"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<" "<<gatolol[7]<<" | "<< gatolol[8]<<" | "<<gatolol[9]<< endl;
    cout<<"   |   |   "<<endl;
}

int main() {

    int jugador = 1,i, choice;

    char marka;
    // gato :v

    do{
        Tablero();
        jugador = (jugador%2)?1:2;
        cout<<"Jugador "<< jugador<<" , ingrese el numero: ";
        cin >> choice;
        marka = (jugador == 1)? 'X':'O';

        if(choice == 1 && gatolol[1]=='1')
        {
            gatolol[1] = marka;
        }
        else if(choice == 2 && gatolol[2]=='2')
        {
            gatolol[2] = marka;
        }
        else if(choice == 3 && gatolol[3]=='3')
        {
            gatolol[3] = marka;
        }
        else if(choice == 4 && gatolol[4]=='4')
        {
            gatolol[4] = marka;
        }
        else if(choice == 5 && gatolol[5]=='5')
        {
            gatolol[5] = marka;
        }

        else if(choice == 6 && gatolol[6]=='6')
        {
            gatolol[6] = marka;
        }

        else if(choice == 7 && gatolol[7]=='7')
        {
            gatolol[7] = marka;
        }
        else if(choice == 8 && gatolol[8]=='8')
        {
            gatolol[8] = marka;
        }
        else if(choice == 9 && gatolol[9]=='9')
        {
            gatolol[9] = marka;
        }else
        {
            cout << "movimiento invalido";
            jugador--;
            cin.ignore();
            cin.get();
        }

        i = checkWin();
        jugador++;

    }
    while(i == -1);

    Tablero();
    if(i == 1)
    {
        cout<< "\aWENA ERMANO GANO EL JUGADOR "<< --jugador;
    }
    else{
        cout<<"\aTERMINA EN EMPATE";
    }
    cin.ignore();
    cin.get();

    return 0;
};