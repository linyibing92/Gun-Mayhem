#include"MyLoadingBar.h"
#include "bomb.h"
#include "Box.h"
#include"Character_wmale.h"
#include"Character_robot.h"

class Box;

class GameSceneMountain :public Scene
{
public:
	CREATE_FUNC(GameSceneMountain);
	static Scene* createScene();
	virtual bool init();
	int* getBoxesType();
	int* getBoxesPositionx();
	int* getBoxesPositiony();
	Box* getBoxes();
private:
	//背景图
	Sprite* _gamebg = Sprite::create("gamebg(1)(1)(1).jpg");
	Sprite* _land1 = Sprite::create("land3(2).png");
	Sprite* _land2 = Sprite::create("land3(2).png");
	Sprite* _land3 = Sprite::create("land3(1).png");
	Sprite* _land4 = Sprite::create("land3(2).png");
	Sprite* _land5 = Sprite::create("land3(1).png");
	Sprite* _land6 = Sprite::create("land3(1).png");
	Sprite* character_robot;
	Vec2 offset = Vec2::ZERO;
	Vec2 robot_position = Director::getInstance()->getVisibleSize() / 2;
	Spawn* robot_right;
	Spawn* robot_left;
	Spawn* robot_up;
	Sequence* robot_up1;
	Spawn* robot_down;

	static int _boxes_type[15]; //;
	static int _boxes_positionx[15]; ////�������ֱ��¼��������ͺ�λ��
	static int _boxes_positiony[15];
	static Box* box;
	
};

class GameSceneForest :public Scene
{
public:
	CREATE_FUNC(GameSceneForest);
	static Scene* createScene();
	virtual bool init();
private:
	//背景图
	Sprite* _gamebg = Sprite::create("gamebg2.jpg");

	//土地
	Sprite* _land1 = Sprite::create("land1(1)(1).png");
	Sprite* _land2 = Sprite::create("land1(1)(1).png");
	Sprite* _land3 = Sprite::create("land1(1)(1).png");
	Sprite* _land4 = Sprite::create("land1(1)(1)(1).png");
	Sprite* _land5 = Sprite::create("land1(1).png");
	Sprite* _land6 = Sprite::create("land1(1)(1).png");

};


class MyMenu :public Menu
{
public:
	void menuSingleCallback(cocos2d::Ref* pSender);
	void menuDoubleCallback(cocos2d::Ref* pSender);
	Menu* create_button_single();
	Menu* create_button_double();
};


class ChooseScene :public Scene//���࣬���ѡ�񳡾����еĳ�Ա
{
public:
	void create_button_scene();//选择场景按钮
	void create_button_gun();//选择枪类按钮
	void create_button_begin();//进入游戏按钮
	virtual void SetBG() = 0;//设置背景图片
	virtual Menu* create_button_char() = 0;//选择人物按钮
protected:
	Sprite* _bg;
	bool  _char_whitemale_status = false;
	bool _char_blackmale_status = false;
	bool _char_robot_status = false;
	bool _scene_mountain_status = true;
	bool _scene_forest_status = true;
	Button* _button_mountain = ui::Button::create("button_mountain.png", "button_mountain.png", "button_mountain.png");
	Button* _button_forest = ui::Button::create("button_forest.png", "button_forest.png", "button_forest.png");
	Button* _button_begin = ui::Button::create("begin.png", "begin.png", "begin.png");

};



class  ChooseSingle :public ChooseScene
{
public:
	CREATE_FUNC(ChooseSingle);
	static Scene* createScene();
	void SetBG();
	Menu* create_button_char();
	virtual bool init();

};
class  ChooseDouble :public ChooseScene
{
public:
	CREATE_FUNC(ChooseDouble);
	static Scene* createScene();
	void SetBG();
	Menu* create_button_char();
	virtual bool init();

};