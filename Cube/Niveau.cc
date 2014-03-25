//
//  Niveau.cc
//  Cube
//
//  Created by Mathias Robert on 17/03/2014.
//  Copyright (c) 2014 Mathias Robert. All rights reserved.
//

#include "Niveau.h"

using namespace std;

Niveau::Niveau() {}
Niveau::~Niveau() {}

sf::String Niveau::getMap( int i, int j) const
{
    return TileMap[i][j];
}
