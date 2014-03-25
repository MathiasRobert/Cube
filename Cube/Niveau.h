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
        "0                                                                                    w                                                               0",
        "0                   w                                  w                   w                                                                         0",
        "0                                      w                                       kk                                                                    0",
        "0                                                                             k  k    k    k                                                         0",
        "0                      c                                                      k      kkk  kkk  w                                                     0",
        "0                                                                       r     k       k    k                                                         0",
        "0                                                                      rr     k  k                                                                   0",
        "0                                                                     rrr      kk                                                                    0",
        "0               c    kckck                                           rrrr                                                                            0",
        "0                                      t0                           rrrrr                                                                            0",
        "0G                                     00              t0          rrrrrr            G                                                               0",
        "0           d    g       d             00              00         rrrrrrr                                                                            0",
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
