//
//  Niveau.h
//  Cube
//
//  Created by Mathias Robert on 17/03/2014.
//  Copyright (c) 2014 Mathias Robert. All rights reserved.
//

#ifndef __Cube__Niveau__
#define __Cube__Niveau__

#include <iostream>
#include "const.h"
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"


class Niveau
{
private:
    sf::String TileMap[H] = {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "0                                                                                                                                                    0",
        "0                                                                                                                                                    0",
        "0                                                                                                                                                    0",
        "0                                                                              kk                                                                    0",
        "0                                                                             k  k    k    k                                                         0",
        "0                      k                                                      k      kkk  kkk  w                                                     0",
        "0                                                                       k     k       k    k                                                         0",
        "0                                                                      kk     k  k                                                                   0",
        "0                                                                     kkk      kk                                                                    0",
        "0               k    kkkkk                                           kkkk                                                                            0",
        "0                                      kk                           kkkkk                                                                            0",
        "0G                                     kk              kk          kkkkkk                                                                            0",
        "0                k       k             kk              kk         kkkkkkk                                                                            0",
        "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
        "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
        "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
    };
    
public:
    Niveau();
    ~Niveau();
    
    sf::String getMap(int i, int j) const;
    
};

#endif /* defined(__Cube__Niveau__) */
