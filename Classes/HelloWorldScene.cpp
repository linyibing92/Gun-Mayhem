/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include"GameScene.h"
#include"MyLayer.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

   

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // 加入背景图
    auto sprite_bg = Sprite::create("bg(1)(1).jpg");
    sprite_bg->setContentSize(Size(1400, 960));
    if (sprite_bg == nullptr)
    {
        problemLoading("'bg(1)(1).jpg'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite_bg->setPosition(Vec2(visibleSize/2));

        // add the sprite as a child to this layer
        this->addChild(sprite_bg, 0);
    }

    //标题显示
     // add a label shows "Gun-Mayhem"
    // create and initialize a label

    auto label_title = Label::createWithTTF("Gun-Mayhem", "fonts/Marker Felt.ttf", 130);
    if (label_title == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label_title->setPosition(Vec2(visibleSize.width / 2,
            visibleSize.height / 2 + label_title->getContentSize().height*1.4f));

        // add the label as a child to this layer
        this->addChild(label_title, 1);
    }

    //进入游戏的按钮(菜单实现）


    auto replaceItem = MenuItemImage::create(
        "1a(1).png",
        "1b(1).png",
        CC_CALLBACK_1(HelloWorld::menuReplaceCallback, this));

    if (replaceItem == nullptr ||
        replaceItem->getContentSize().width <= 0 ||
        replaceItem->getContentSize().height <= 0)
    {
        problemLoading("'1a(1).png' and '1b(1).png'");
    }
    else
    {
        replaceItem->setScale(2.f);
        replaceItem->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        replaceItem->setPosition(Vec2(visibleSize / 2));
    }

    // create menu, it's an autorelease object
    auto menu_new_game = Menu::create(replaceItem, NULL);
    menu_new_game->setPosition(Vec2::ZERO);
    this->addChild(menu_new_game, 1);



    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "2a(1)(1).png",
                                           "2b(1)(1).png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'2a(1)(1).png' and '2b(1)(1).png'");
    }
    else
    {
        closeItem->setPosition(Vec2(visibleSize / 2) - Vec2(0, closeItem->getContentSize().height+50 ));
    }

    // create menu, it's an autorelease object
    Menu* menu_close = Menu::create(closeItem, NULL);
    menu_close->setPosition(Vec2::ZERO);
    this->addChild(menu_close, 1);

 
    

//音乐等菜单
  

     auto layer = MyLayer::create();
    this->addChild(layer,10);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}


void HelloWorld::menuReplaceCallback(Ref* pSender)
{
    // 清空缓存
    Director::getInstance()->purgeCachedData();

    Scene* pScene = SelectScene::create();

    Director::getInstance()->replaceScene(TransitionFade::create(0.5f, pScene));
}
