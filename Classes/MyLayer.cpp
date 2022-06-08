#include "MyLayer.h"


bool MyLayer::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if (!Layer::create())
		return false;
	static int _backgroundAudioID = AudioEngine::play2d("bgmusic.mp3", true);

	_button_sound->setPosition(Vec2(visibleSize) - Vec2(180, 35));
	_button_sound->addClickEventListener([this,visibleSize](Ref* sender) {
        auto sprite_bg = Sprite::create("musiclayer(1).png");
		sprite_bg->setPosition(Vec2(visibleSize/2));
		sprite_bg->setContentSize(Size(500, 150));
		auto label=Label::createWithTTF("music", "fonts/Marker Felt.ttf", 40);
		label->setPosition(Vec2(visibleSize / 2) + Vec2(0, 42));
		MyLayerMusic mymusiclayer;
		MyLayerMusic* m1=& mymusiclayer;
		auto pLayer = mymusiclayer._pLayer;
		pLayer->addChild(sprite_bg);
		pLayer->addChild(label);
		mymusiclayer.create_button_music_pause(_backgroundAudioID);
		mymusiclayer.create_button_music_up(_backgroundAudioID);
		mymusiclayer.create_button_music_down(_backgroundAudioID);
		Button* _button_return = ui::Button::create("return.png", "return.png");
		_button_return->setScale(1.8f);
		_button_return->setPosition(Vec2(pLayer->getContentSize()) / 2 + Vec2(200, 30));
		_button_return->addClickEventListener([pLayer](Ref* sender) {
			pLayer->removeAllChildren();
			});
		pLayer->addChild(_button_return);
		pLayer->setContentSize(Size(500, 150));
		
		this->addChild(pLayer);
		});
	    
	this->addChild(_button_sound);

	Button* button_end = create_button_end();
	this->addChild(button_end);
	Button* button_pause = create_button_pause();
	this->addChild(button_pause);
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

Button* MyLayer::create_button_pause()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto button_pause = ui::Button::create(
		"pause.png",
		"pause.png", "pause.png");
	button_pause->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button_pause->setPosition(Vec2(visibleSize) - Vec2(100, 35));
	button_pause->addClickEventListener([this](Ref* sender) {
		Director::getInstance()->stopAnimation();
		auto button_restart = create_button_restart();
		this->addChild(button_restart);
		});
	return button_pause;

}

Button* MyLayer::create_button_restart()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto button_restart = ui::Button::create(
		"restart.png",
		"restart.png", "restart.png");
	button_restart->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button_restart->setPosition(Vec2(visibleSize/2));
	button_restart->addClickEventListener([button_restart](Ref* sender) {
		Director::getInstance()->startAnimation();
		button_restart->setVisible(false);
		});
	return button_restart;
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


bool MyLayerWinner::init()
{
	if(!Layer::create())
	     return false;
	auto visibleSize = Director::getInstance()->getVisibleSize();
    Sprite* bg =set_bg();
	this->addChild(bg);
	auto button_exit = create_button_exit();
	auto button_restart = create_button_restart();
	auto label = Label::createWithTTF("You win!", "fonts/Marker Felt.ttf", 60);
	label->setPosition(Vec2(visibleSize / 2) + Vec2(0, 135));
	this->addChild(label);
	return true;
}

bool MyLayerGameOver::init()
{
	if (!Layer::create())
		return false;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	MyLayerEnd mylayerend;
	if (!Layer::create())
		return false;
	Sprite* bg = mylayerend.set_bg();
	this->addChild(bg);
	auto button_exit = create_button_exit();
	auto button_restart = create_button_restart();
	auto label=Label::createWithTTF("Game Over","fonts/Marker Felt.ttf", 60);
	label->setPosition(Vec2(visibleSize / 2) + Vec2(0, 135));
	this->addChild(label);
	return true;
}

Sprite* MyLayerEnd::set_bg() 
{
	auto bg = Sprite::create("layerbg.png");
	bg->setScale(3.f);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	bg->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	bg->setPosition(Vec2(visibleSize / 2));
	return bg;
}

Button* MyLayerEnd::create_button_restart()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Button* button_restart = ui::Button::create("restart.png", "restart.png");
	button_restart->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button_restart->setPosition(Vec2(visibleSize / 2) );
	button_restart->addClickEventListener([](Ref* sender) {
		Scene* pScene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(0.5f, pScene));
		});
	this->addChild(button_restart);
	return button_restart;
}

Button* MyLayerEnd::create_button_exit()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Button* button_exit = ui::Button::create("exit.png", "exit,png");
	button_exit->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button_exit->setPosition(Vec2(visibleSize / 2) - Vec2(0, 140));
	button_exit->addClickEventListener([](Ref* sender) {
		Director::getInstance()->end();
		});
	this->addChild(button_exit);
	return button_exit;
}
