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
	Button* create_button_end();	//创建结束按钮
	Button* create_button_pause();//创建暂停按钮
	Button* create_button_restart();//创建回复按钮
	
protected:
	Button* _button_sound = ui::Button::create(
		"sound_on.png",
		"sound_on.png");

};


class MyLayerMusic :public Layer//点击右上角音乐后弹出的菜单
{
public:
	void create_button_music_pause(int _backgroundAudioID);//音乐暂停的按钮
	void create_button_music_up(int _backgroundAudioID);//声音增加的按钮
	void create_button_music_down(int _backgroundAudioID);//声音减小的按钮
    Layer* _pLayer = Layer::create();
private:
	Button* _button_music_down = ui::Button::create("musicdown.png", "musicdown.png");
	Button* _button_music_up = ui::Button::create("musicup.png", "musicup.png");
	Button* _button_music_pause = ui::Button::create("pause.png", "pause.png");
	
};


class MyLayerEnd:public Layer//游戏结束后弹出的弹窗
{
public:
	Sprite* set_bg()const ;//设置背景图片
	Button* create_button_restart();//设置重新开始的按钮
	Button* create_button_exit();//设置退出游戏的按钮
protected:
};


class MyLayerWinner :public MyLayerEnd//胜利者的弹窗
{
public:
	CREATE_FUNC(MyLayerWinner);
	virtual bool init();
};

class MyLayerGameOver :public MyLayerEnd//失败的弹窗
{
public:
	CREATE_FUNC(MyLayerGameOver);
	virtual bool init();
};