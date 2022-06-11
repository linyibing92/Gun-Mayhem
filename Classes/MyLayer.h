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
	Button* create_button_end();	//����������ť
	Button* create_button_pause();//������ͣ��ť
	Button* create_button_restart();//�����ظ���ť
	
protected:
	Button* _button_sound = ui::Button::create(
		"sound_on.png",
		"sound_on.png");

};


class MyLayerMusic :public Layer//������Ͻ����ֺ󵯳��Ĳ˵�
{
public:
	void create_button_music_pause(int _backgroundAudioID);//������ͣ�İ�ť
	void create_button_music_up(int _backgroundAudioID);//�������ӵİ�ť
	void create_button_music_down(int _backgroundAudioID);//������С�İ�ť
    Layer* _pLayer = Layer::create();
private:
	Button* _button_music_down = ui::Button::create("musicdown.png", "musicdown.png");
	Button* _button_music_up = ui::Button::create("musicup.png", "musicup.png");
	Button* _button_music_pause = ui::Button::create("pause.png", "pause.png");
	
};


class MyLayerEnd:public Layer//��Ϸ�����󵯳��ĵ���
{
public:
	Sprite* set_bg()const ;//���ñ���ͼƬ
	Button* create_button_restart();//�������¿�ʼ�İ�ť
	Button* create_button_exit();//�����˳���Ϸ�İ�ť
protected:
};


class MyLayerWinner :public MyLayerEnd//ʤ���ߵĵ���
{
public:
	CREATE_FUNC(MyLayerWinner);
	virtual bool init();
};

class MyLayerGameOver :public MyLayerEnd//ʧ�ܵĵ���
{
public:
	CREATE_FUNC(MyLayerGameOver);
	virtual bool init();
};