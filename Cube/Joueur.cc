//
//  Joueur.cc
//  Cube
//
//  Created by Mathias Robert on 17/03/2014.
//  Copyright (c) 2014 Mathias Robert. All rights reserved.
//

#include "Joueur.h"

Joueur::Joueur()
{
    _vies = 3;
    _rect = sf::FloatRect(100,13*TAILLECUBE,TAILLECUBE,TAILLECUBE*2);
    _rectShape.setSize(sf::Vector2f(TAILLECUBE,TAILLECUBE*2));
    _rectShape.setPosition(_rect.left, _rect.top);
    _rectShape.setFillColor(sf::Color::Red);
    _dx=_dy=0.1;
    _offsetX=_offsetY=0;
    _onGround=false;
}

Joueur::~Joueur()
{
    delete _niveau;
}

sf::RectangleShape Joueur::getRectShape() const
{
    return _rectShape;
}

bool Joueur::getOnGround() const
{
    return _onGround;
}
int Joueur::getOffSetX() const
{
    return _offsetX;
}
int Joueur::getOffSetY() const
{
    return _offsetY;
}

void Joueur::setNiveau(Niveau *niveau)
{
    _niveau = niveau;
}
void Joueur::setOnGround(bool onGround)
{
    _onGround = onGround;
}
void Joueur::setDX(float dx)
{
    _dx = dx;
}
void Joueur::setDY(float dy)
{
    _dy = dy;
}

void Joueur::mouvement(float time)
{
    _rect.left += _dx * time * v_x;
    collision(0);
    
    if (!_onGround)
        _dy = _dy + 0.0005 * time;
    _rect.top += _dy * time * v_y;
    _onGround=false;
    collision(1);

    if (_rect.left>200)
        _offsetX = _rect.left-200;
    
    _rectShape.setPosition(_rect.left - _offsetX, _rect.top - _offsetY);
    
    _dx=0;
}

void Joueur::collision(int num)
{
	
	for (int i = _rect.top/TAILLECUBE ; i<(_rect.top+_rect.height)/TAILLECUBE; i++)
		for (int j = _rect.left/TAILLECUBE; j<(_rect.left+_rect.width)/TAILLECUBE; j++)
        {
            if ((_niveau->getMap(i, j)=='P') || (_niveau->getMap(i, j)=='k') || (_niveau->getMap(i, j)=='0'))
            {
                if (_dy>0 && num==1)
                {
                    _rect.top =   i*TAILLECUBE -  _rect.height;
                    _dy=0;
                    _onGround=true;
                }
                if (_dy<0 && num==1)
                {
                    _rect.top = i*TAILLECUBE + TAILLECUBE;
                    _dy=0;
                }
                if (_dx>0 && num==0)
                {
                    _rect.left =  j*TAILLECUBE -  _rect.width;
                }
                if (_dx<0 && num==0)
                {
                    _rect.left =  j*TAILLECUBE + TAILLECUBE;
                }
            }
        }
}

