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

class Joueur
{
private:
    int _vies;
    float _dx,_dy;
    sf::FloatRect _rect;
    sf::RectangleShape _rectShape;
    bool _onGround;
    float _offsetX, _offsetY;
    
    Niveau *_niveau;
    
public:
    Joueur();
    ~Joueur();
    
    bool getOnGround() const;
    
    void setNiveau(Niveau *niveau);
    void setOnGround(bool onGround);
    void setDX(int dx);
    void setDY(int dy);
    
    int getVies() const;
    sf::RectangleShape getRectShape() const;
    
    void collision(int num);
    void mouvement(float time);
    
};

#endif /* defined(__Cube__Joueur__) */
