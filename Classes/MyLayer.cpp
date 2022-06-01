#include "MyLayer.h"


bool MyLayer::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if (!Layer::create())
		return false;
	static int _backgroundAudioID = AudioEngine::play2d("bgmusic.mp3", true);

	_button_sound->setPosition(Vec2(visibleSize) - Vec2(100, 35));
	_button_sound->addClickEventListener([this,visibleSize](Ref* sender) {
        auto sprite_bg = Sprite::create("musiclayer(1).png");
		sprite_bg->setPosition(Vec2(visibleSize/2));
		sprite_bg->setContentSize(Size(500, 150));
		auto label=Label::createWithTTF("music", "fonts/Marker Felt.ttf", 40);
		label->setPosition(Vec2(visibleSize / 2) + Vec2(0, 42));
		MyLayerMusic mymusiclayer;
		auto pLayer = mymusiclayer._pLayer;
		pLayer->addChild(sprite_bg);
		pLayer->addChild(label);
		mymusiclayer.create_button_music_pause(_backgroundAudioID);
		mymusiclayer.create_button_music_up(_backgroundAudioID);
		mymusiclayer.create_button_music_down(_backgroundAudioID);
	//	mymusiclayer.create_button_return();
		pLayer->setContentSize(Size(500, 150));
		
		this->addChild(pLayer);
		});
	    
	this->addChild(_button_sound);

	Button* button_end = create_button_end();
	this->addChild(button_end);
	return true;
}



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


void MyLayerMusic::create_button_music_pause(int _backgroundAudioID)
{
	_button_music_pause->setScale(1.13f);
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
	 _button_music_up->setScale(1.6f);
	_button_music_up->setPosition(Vec2(_pLayer->getContentSize()) / 2+Vec2(150,0));
	_button_music_up->addClickEventListener([_backgroundAudioID](Ref* sender) {
		AudioEngine::setVolume(_backgroundAudioID, 1.5);
		});
	_pLayer->addChild(_button_music_up);
}

void MyLayerMusic::create_button_music_down(int _backgroundAudioID)
{
	_button_music_down->setScale(1.6f);
	_button_music_down->setPosition(Vec2(_pLayer->getContentSize()) / 2-Vec2(150,0));
	_button_music_down->addClickEventListener([_backgroundAudioID](Ref* sender) {
		AudioEngine::setVolume(_backgroundAudioID, 0.5);
		});
	_pLayer->addChild(_button_music_down);
}

void MyLayerMusic::create_button_return()
{
	_button_return->setScale(1.8f);
	_button_return->setPosition(Vec2(_pLayer->getContentSize())/2+Vec2(200,30));
	_button_return->addClickEventListener([this](Ref* sender) {
		menuCloseCallback(sender);
		});
	_pLayer->addChild(_button_return);
}

void MyLayerMusic::menuCloseCallback(Ref* psender)
{
	this->removeFromParentAndCleanup(false);
}
