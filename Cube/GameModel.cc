//
//  GameModel.cc
//  Cube
//
//  Created by Mathias Robert on 17/03/2014.
//  Copyright (c) 2014 Mathias Robert. All rights reserved.
//

#include "GameModel.h"

GameModel::GameModel()
{
    _niveau = new Niveau;
    _joueur = new Joueur;
    _joueur->setNiveau(_niveau);
}
GameModel::~GameModel()
{
    delete _niveau;
}

Niveau GameModel::getNiveau() const
{
    return *_niveau;
}
Joueur GameModel::getJoueur() const
{
    return *_joueur;
}

void GameModel::nextStep()
{
    float time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time = time/500;
    if (time > 20) time = 20;
    
    _joueur->mouvement(time);
}