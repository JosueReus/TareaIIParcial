#include "Krillin.h"

Krillin::Krillin(int x, int y,SDL_Renderer* renderer,
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

Krillin::~Krillin()
{
    //dtor
}

void Krillin::logic(Uint8* teclas_presionadas)
{
    SDL_Rect temp = this->rectangulo;

    rectangulo.y++;
    rectangulo.x--;
        if(rectangulo.y+rectangulo.h==250)
            {

                rectangulo.y=0;
                rectangulo.x=468;

            }


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
