#ifndef GOKU_H
#define GOKU_H
#include "Personaje.h"


class Goku:public Personaje
{
    public:
        Goku(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes);
        virtual ~Goku();
        void logic(Uint8* teclas_presionadas);
        void getCos(float c);
        bool cmpf(float A, float B);
        void setTarget(int x, int y);
        void getSin(float s,int m);
        void getSin2(float s,int Ys);
        void yF();
    protected:
    private:
};

#endif // GOKU_H
