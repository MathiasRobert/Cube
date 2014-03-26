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
    _rect = sf::FloatRect(100,13*16,16,32);
    _rectShape.setSize(sf::Vector2f(16,32));
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
    _rect.left += _dx * time;
    collision(0);
    
    if (!_onGround)
        _dy = _dy + 0.0005 * time;
    _rect.top += _dy * time;
    _onGround=false;
    collision(1);

    if (_rect.left>200)
        _offsetX = _rect.left-200;
    
    _rectShape.setPosition(_rect.left - _offsetX, _rect.top - _offsetY);
    
    _dx=0;
}

void Joueur::collision(int num)
{
	
	for (int i = _rect.top/16 ; i<(_rect.top+_rect.height)/16; i++)
		for (int j = _rect.left/16; j<(_rect.left+_rect.width)/16; j++)
        {
            if ((_niveau->getMap(i, j)=='P') || (_niveau->getMap(i, j)=='k') || (_niveau->getMap(i, j)=='0') || (_niveau->getMap(i, j)=='r') || (_niveau->getMap(i, j)=='t') || (_niveau->getMap(i, j)=='d') || (_niveau->getMap(i, j)=='c') || (_niveau->getMap(i, j)=='g'))
            {
                if (_dy>0 && num==1)
                {
                    _rect.top =   i*16 -  _rect.height;
                    _dy=0;
                    _onGround=true;
                }
                if (_dy<0 && num==1)
                {
                    _rect.top = i*16 + 16;
                    _dy=0;
                }
                if (_dx>0 && num==0)
                {
                    _rect.left =  j*16 -  _rect.width;
                }
                if (_dx<0 && num==0)
                {
                    _rect.left =  j*16 +16;
                }
            }
        }
}

