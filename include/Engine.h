#pragma once
#include <vector>
#include <string>
#include <map>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "Object.h"

typedef void (*func) ();





class Engine {
private:
    
    Uint32 m_gameTime;
    double m_deltaTime;
    Uint16 m_fps;
    double m_msPerFrame;
    Uint32 m_delayTime;
    
public:
    bool    quit;
    SDL_Window*  window;
    
    std::map<std::string,TTF_Font*>  fonts;
    
    std::vector<func>                scripts;
    
    std::map<SDL_Keycode, bool>      kbState;
    std::map<SDL_Keycode, bool>      kbStateOnceDown;
    std::map<SDL_Keycode, bool>      kbStateOnceUp;
    
    const Uint32 &                   gameTime;
    const double &                   deltaTime;
    const Uint16 &                   fps;
    
    
    std::vector<Object*>         objects;
    
    // FUNCTIONS-----------------------------------
    
    Engine();
    
    bool    initLibs();
    void    enterMainLoop();
    void    setFPS(const Uint16& newFPS);
    
private:
    void    doCapGtimeCalcDt();
    void    doScripts();
    void    doInput();
    void    doUpdate();
    void    doDelay();
    void    doRender();
};





extern Engine engine;




