//
//  GameView.h
//  Cube
//
//  Created by Mathias Robert on 17/03/2014.
//  Copyright (c) 2014 Mathias Robert. All rights reserved.
//

#ifndef __Cube__GameView__
#define __Cube__GameView__

#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "GameModel.h"

class GameModel;

class GameView {
private:
    int _w, _h;
    
    sf::RenderWindow * _window;
    sf::ContextSettings _settings;
    sf::RectangleShape _rectangle;
    
    GameModel * _model;
    
public:
    GameView(int w, int h);
    ~GameView();
    
    void setModel(GameModel *model);
    void draw();
    bool treatEvents();
    
};

#endif /* defined(__Cube__GameView__) */
