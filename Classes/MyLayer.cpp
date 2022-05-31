#include "MyLayer.h"

bool MyLayer::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if (!Layer::create())
		return false;
	
	_button_sound->setPosition(Vec2(visibleSize) - Vec2(100, 35));
	_button_sound->addClickEventListener([this](Ref* sender) {
		MyLayerMusic::create();
		});
	this->addChild(_button_sound);

	Button* button_end = create_button_end();
	this->addChild(button_end);
	return true;
}

int MyLayer::_backgroundAudioID = AudioEngine::play2d("bgmusic.mp3", true);

Button* MyLayer::create_button_end()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto button_end = ui::Button::create(
		"close.png",
		"close.png", "close.png");
	button_end->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button_end->setPosition(Vec2(visibleSize) - Vec2(35, 35));
	button_end->addClickEventListener([](Ref* sender) {
		Director::getInstance()->end();
		});
	return button_end;
}

bool MyLayerMusic::init()
{
	if(!MyLayer::create())
	    return false;
	_pLayer->setContentSize(Size(274, 79));
	auto sprite_bg = Sprite::create("musiclayer(1).png");
	sprite_bg->setPosition(Vec2(_pLayer->getContentSize()));
	_pLayer->addChild(sprite_bg);

	create_button_music_pause(_backgroundAudioID);
	create_button_music_up(_backgroundAudioID);
	create_button_music_down(_backgroundAudioID);
	create_button_return();
	return true;
}

void MyLayerMusic::create_button_music_pause(int _backgroundAudioID)
{
	_button_music_pause->setPosition(Vec2(_pLayer->getContentSize())/2);
	_button_music_pause->addClickEventListener([_backgroundAudioID](Ref* sender) {
		static int count2 = 0;
		if (count2 % 2 == 0)
			AudioEngine::pause(_backgroundAudioID);
		else
			AudioEngine::resume(_backgroundAudioID);
		count2++;
		});
	_pLayer->addChild(_button_music_pause);
}

 void MyLayerMusic::create_button_music_up(int _backgroundAudioID)
{
	_button_music_up->setPosition(Vec2(_pLayer->getContentSize()) / 2+Vec2(30,0));
	_button_music_up->addClickEventListener([_backgroundAudioID](Ref* sender) {
		static int count4 = 0;
		if (count4 % 2 == 0)
			AudioEngine::pause(_backgroundAudioID);
		else
			AudioEngine::resume(_backgroundAudioID);
		count4++;
		});
	_pLayer->addChild(_button_music_up);
}

void MyLayerMusic::create_button_music_down(int _backgroundAudioID)
{
	_button_music_down->setPosition(Vec2(_pLayer->getContentSize()) / 2-Vec2(30,0));
	_button_music_down->addClickEventListener([_backgroundAudioID](Ref* sender) {
		static int count3 = 0;
		if (count3 % 2 == 0)
			AudioEngine::pause(_backgroundAudioID);
		else
			AudioEngine::resume(_backgroundAudioID);
		count3++;
		});
	_pLayer->addChild(_button_music_down);
}

void MyLayerMusic::create_button_return()
{
	_button_return->setPosition(Vec2(_pLayer->getContentSize()));
	_button_return->addClickEventListener([this](Ref* sender) {
		menuCloseCallback(sender);
		});
	_pLayer->addChild(_button_return);
}

void MyLayerMusic::menuCloseCallback(Ref* psender)
{
	this->removeFromParentAndCleanup(true);
}
