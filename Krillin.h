#ifndef KRILLIN_H
#define KRILLIN_H
#include "Personaje.h"


class Krillin:public Personaje
{
    public:
        Krillin(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes);
        void logic(Uint8* teclas_presionadas);
        virtual ~Krillin();
    protected:
    private:
};

#endif // KRILLIN_H
