//
//  Joueur.h
//  Cube
//
//  Created by Mathias Robert on 17/03/2014.
//  Copyright (c) 2014 Mathias Robert. All rights reserved.
//

#ifndef __Cube__Joueur__
#define __Cube__Joueur__

#include "Niveau.h"
#include <cmath>

class Joueur
{
private:
    int _vies;
    float _dx,_dy;
    sf::FloatRect _rect;
    sf::RectangleShape _rectShape;
    sf::RectangleShape _rectShapeExplo[8];

    bool _onGround;
    bool _explosion;
    float _offsetX, _offsetY;
    
    const double g = 9.81;
    const double pi = 3.14;
    float v_init = 1.5;
    int angle_init = pi/3;
    float v_x = cos(angle_init)*v_init;
    float v_y = sin(angle_init)*v_init;
    
    Niveau *_niveau;
    
public:
    Joueur();
    ~Joueur();
    
    bool getOnGround() const;
    
    void setNiveau(Niveau *niveau);
    void setOnGround(bool onGround);
    void setDX(float dx);
    void setDY(float dy);
    void setExplosion(bool explosion);
    
    int getVies() const;
    sf::RectangleShape getRectShape() const;
    int getOffSetX() const;
    int getOffSetY() const;
    bool getExplosion() const;

    
    void collision(int num);
    void mouvement(float time);
    
};

#endif /* defined(__Cube__Joueur__) */
