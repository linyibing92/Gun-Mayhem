#pragma once

#include"GameScene.h"
#include "cocos2d.h"

#include"HelloWorldScene.h"

#include "audio/include/AudioEngine.h"
class MyLayer :public Layer
{
public:
	CREATE_FUNC(MyLayer);
	virtual bool  init();
	Button* create_button_end();	

	Button* create_button_pause();
	Button* create_button_restart();

	
protected:
	Button* _button_sound = ui::Button::create(
		"sound_on.png",
		"sound_on.png");


};


class MyLayerMusic :public Layer
{
public:
	void create_button_music_pause(int _backgroundAudioID);
	void create_button_music_up(int _backgroundAudioID);
	void create_button_music_down(int _backgroundAudioID);

    Layer* _pLayer = Layer::create();
private:

	Button* _button_music_down = ui::Button::create("musicdown.png", "musicdown.png");
	Button* _button_music_up = ui::Button::create("musicup.png", "musicup.png");
	Button* _button_music_pause = ui::Button::create("pause.png", "pause.png");
	
};


class MyLayerEnd:public Layer
{
public:
	Sprite* set_bg() ;
	Button* create_button_restart();
	Button* create_button_exit();
protected:
};


class MyLayerWinner :public MyLayerEnd
{
public:
	CREATE_FUNC(MyLayerWinner);
	virtual bool init();
};

class MyLayerGameOver :public MyLayerEnd
{
public:
	CREATE_FUNC(MyLayerGameOver);
	virtual bool init();

};