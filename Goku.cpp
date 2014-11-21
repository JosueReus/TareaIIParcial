#include "Goku.h"
#include<iostream>
#include<math.h>
#include <stdio.h>
#define PI 3.14
#include <stdlib.h>
using namespace std;
    bool primeraVezX=true;
    bool primeraVezY=true;
    bool circulo=true;
    bool menorQueX=true;
    bool menorQueY=true;
    bool mayorQueX=false;
    bool mayorQueY=true;
    int distanciaX=0;
    int distanciaY=0;
    int recorrido=0;
    int xInvetado=0;
    int cont1=0;
    int cont2=0;

    int cosX=500/2;
    int sinY=250.0/2.0;
    int suma=0;
float pi=3.14;
float Two_Pi=pi*2;
void Goku::yF()
{

if(cont2<=50){
cont2++;
rectangulo.y--;
}

}
void Goku::setTarget(int x, int y)
{
    if(menorQueX)
    {
        rectangulo.x++;
        if(rectangulo.x==(x-32))
        {
           menorQueX=false;
           mayorQueX=true;
        }
//        if(x<rectangulo.x)
//            mayorQueX=true;
    }
    if(mayorQueX)
    {
        rectangulo.x--;
        if(rectangulo.x==(x+32))
            mayorQueX=false;
    }

    if(rectangulo.y<y)
    {
        rectangulo.y++;
    }

}


Goku::Goku(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes)
{
    //ctor

    this->rectangulo.x = x;
    this->rectangulo.y = y;
    this->x=x;
    this->y=y;
    this->a=0;
    this->personajes=personajes;
    SDL_Texture *textura = IMG_LoadTexture(renderer, "assets/npcs/npc1/down1.png");
    SDL_QueryTexture(textura, NULL, NULL, &this->rectangulo.w, &this->rectangulo.h);

    texturas_down.push_back(textura);
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc1/down2.png"));

    textura_actual=texturas_down.begin();

    orientacion="down";
}

Goku::~Goku()
{
    //dtor
}
void Goku::getCos(float c)
{
    x=(((500/2)-suma)+(cos(c) *25.0));
}
void Goku::getSin(float s,int Ys)
{
    y=((Ys)+(sin(s) *25.0));
}
void Goku::getSin2(float s,int Ys)
{
    y=((Ys)-(sin(s) *25.0));
}
bool Goku::cmpf(float A, float B)
{
    float epsilon = 0.005f;
    return (fabs(A - B) < epsilon);
}
void Goku::logic(Uint8* teclas_presionadas)
{
    SDL_Rect temp = this->rectangulo;

//    ZIGZAG
    if(primeraVezX==true)
    {
        rectangulo.x++;
        if(rectangulo.x+rectangulo.w==500)
        primeraVezX=false;
    }
     if(primeraVezX==false)
    {
        rectangulo.x--;
        if(rectangulo.x==0)
        primeraVezX=true;
    }

    if(primeraVezY==true)
    {
        rectangulo.y--;
        if(rectangulo.y==0)
        primeraVezY=false;
    }
     if(primeraVezY==false)
    {
        rectangulo.y++;
        if(rectangulo.y+rectangulo.h==250)
        primeraVezY=true;
    }

//    DIAGONAL
//    rectangulo.y++;
//    rectangulo.x--;
//        if(rectangulo.y+rectangulo.h==250)
//            {
//
//                rectangulo.y=0;
//                rectangulo.x=468;
//
//            }


//HORIZONTAL
//rectangulo.x--;
//if(rectangulo.x==0)
//    rectangulo.x=468;
//VERTICAL
//rectangulo.y++;
//if(rectangulo.y+rectangulo.h==250)
//    rectangulo.y=0;

// CIRCULAR

//if(circulo)
//{
//    a+=0.01;
//    getCos(a);
//    getSin2(a,sinY);
//    rectangulo.x=x;
//    rectangulo.y=y;
//   if(cmpf(a,PI))
//   {
//       suma+=50;
//       a=0;
//     circulo=false;
//   }
//}
//if(circulo==false)
//{
//    a-=0.01;
//    getCos(a);
//    getSin2(a,sinY);
//    rectangulo.x=x;
//    rectangulo.y=y;
//   if(cmpf(a,-PI))
//   {
//       suma+=50;
//       a=0;
//
//     circulo=true;
//   }
//
//
//}

//INVENTADO

//    rectangulo.y--;
//    rectangulo.x--;
//        if(rectangulo.y==0)
//            {
//
//                rectangulo.y=218;
//                rectangulo.x=468;
//
//            }




//cout<<circulo<<endl;
//setTarget(x,y);


    for(list<Personaje*>::iterator i = personajes->begin();
            i!=personajes->end();
            i++)
    {
        if(this==(*i))
            continue;
        if(colision(this->rectangulo, (*i)->rectangulo))
            rectangulo=temp;//personajes->erase(i);
            //break;
    }
}
