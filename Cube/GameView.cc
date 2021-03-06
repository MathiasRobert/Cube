//
//  GameView.cc
//  Cube
//
//  Created by Mathias Robert on 17/03/2014.
//  Copyright (c) 2014 Mathias Robert. All rights reserved.
//

#include "GameView.h"

using namespace sf;

GameView::GameView(int w, int h): _w(w), _h(h){
	_settings.antialiasingLevel = 8;
    _window = new RenderWindow(VideoMode(w, h), "Cube", Style::Close, _settings);
    
}

GameView::~GameView(){
    if(_window!= NULL)
        delete _window;
}

void GameView::setModel(GameModel * model){
    _model = model;
}

void GameView::draw(){
    
    int offsetX = _model->getJoueur()->getOffSetX();
    int offsetY = _model->getJoueur()->getOffSetY();
    
    
    
    _window->clear(Color::White);
    
    _rectangle.setSize(Vector2f(TAILLECUBE,TAILLECUBE));
    _rectangle.setFillColor(Color::Black);
    
    for (int i=0; i<H; i++)
    {
        for (int j=0; j<W; j++)
        {
            if ((_model->getNiveau()->getMap(i,j)==' ') || (_model->getNiveau()->getMap(i,j)=='0')) continue;
            
            _rectangle.setPosition((j*TAILLECUBE)-offsetX,(i*TAILLECUBE)-offsetY);
            _window->draw(_rectangle);
        }
    }
    
    _window->draw(_model->getJoueur()->getRectShape());
    
    _window->display();
}


bool GameView::treatEvents(){
    bool result = false;
    
    if(_window->isOpen()){
        result = true;
        Event event;
        while (_window->pollEvent(event)) {
            if ((event.type == Event::Closed) ||
                ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))) {
                _window->close();
                result = false;
            }
        }
    
    
    if (Keyboard::isKeyPressed(Keyboard::Left))
        _model->getJoueur()->setDX(-0.2);
    if (Keyboard::isKeyPressed(Keyboard::Right))
        _model->getJoueur()->setDX(0.2);
    if (Keyboard::isKeyPressed(Keyboard::Space))
        if (_model->getJoueur()->getOnGround()) {
            _model->getJoueur()->setDY(-0.35);
            _model->getJoueur()->setOnGround(false);
        }
    if (Keyboard::isKeyPressed(Keyboard::E))
        _model->getJoueur()->setExplosion(true);
    return result;
    }
    return result;
}
