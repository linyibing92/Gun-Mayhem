#pragma once

#include"GameScene.h"
#include "cocos2d.h"
#include "audio/include/AudioEngine.h"
class MyLayer :public Layer
{
public:
	CREATE_FUNC(MyLayer);
	virtual bool  init();
	Button* create_button_end();	
	
protected:
	Button* _button_sound = ui::Button::create(
		"sound_on.png",
		"sound_close.png");

};


class MyLayerMusic :public Layer
{
public:
	void create_button_music_pause(int _backgroundAudioID);
	void create_button_music_up(int _backgroundAudioID);
	void create_button_music_down(int _backgroundAudioID);
	void create_button_return();
	void menuCloseCallback(Ref* psender);
    Layer* _pLayer = Layer::create();
private:
	Button* _button_return = ui::Button::create("return.png", "return.png");
	Button* _button_music_down = ui::Button::create("musicdown.png", "musicdown.png");
	Button* _button_music_up = ui::Button::create("musicup.png", "musicup.png");
	Button* _button_music_pause = ui::Button::create("pause.png", "pause.png");
	
};