//
//  GameModel.h
//  Cube
//
//  Created by Mathias Robert on 17/03/2014.
//  Copyright (c) 2014 Mathias Robert. All rights reserved.
//

#ifndef __Cube__GameModel__
#define __Cube__GameModel__

#include "Joueur.h"

class GameModel
{
private:
    Niveau *_niveau; 
    Joueur *_joueur;
    sf::Clock clock;

    
public:
    GameModel();
    ~GameModel();
    
    Niveau getNiveau() const;
    Joueur getJoueur() const;
    
    void nextStep();
    
};

#endif /* defined(__Cube__GameModel__) */
