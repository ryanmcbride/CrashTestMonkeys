//
//  HelloWorldScene.cpp
//  MonkeyDroid
//
//  Created by Admin on 3/19/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//
#include "Commercial.h"
#include "SimpleAudioEngine.h"
#include "../ScreenHelper.h"
#include "../FrontEnd/Loading.h"
#include "../FrontEnd/SaveLoad.h"

#include "BoredRoom.h"
#include "CarCrash.h"
#include "CNN.h"
#include "McAcme.h"
#include "KenHint.h"

using namespace cocos2d;
using namespace CocosDenshion;

Commercial::Commercial()
{
    glClearColor(0.0f/255.0f, 0.0f/255.0f, 0.0f/255.0f, 1.0f);
    setTouchEnabled( true );
    ScreenHelper::isCinematic = true;
    m_TimeOut = 3.0f;
    scheduleUpdate();
}
Commercial::~Commercial()
{
    ScreenHelper::isCinematic = false;
}
void Commercial::update(float dt)
{
    m_TimeOut -= dt;
    if(m_TimeOut < 0.0f)
    {
        CCDirector::sharedDirector()->replaceScene(Loading::scene());
        m_TimeOut = 100.0f;
    }
}
CCScene* Commercial::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // add layer as a child to scene
    CCLayer* layer = NULL;
    bool can_show_ken_hint = (SaveLoad::m_SaveData.medalLockLevel==0 && SaveLoad::m_SaveData.currentLevel < 24);
    int random = CCRANDOM_0_1()*(can_show_ken_hint?5.0f:4.0f);
    bool do_boarder = false;
    switch(random)
    {
    default:
    case 0:
        layer = new McAcme();
            do_boarder = true;
        break;
    case 1:
        layer = new CNN();
            do_boarder = true;
        break;
    case 2:
        layer = new BoredRoom();
            do_boarder = true;
        break;
    case 3:
        layer = new CarCrash();
        break;
    case 4:
        layer = new KenHint();
        break;
    }
    if(do_boarder)
    {
        float scale = ScreenHelper::getTextureScale();
        float scaleX = ScreenHelper::getTextureScaleX();
        float scaleY = ScreenHelper::getTextureScaleY();
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        CCPoint point = ccp(-440*scale,-160.0f*scaleY);
        point = ccpAdd(point, ScreenHelper::getAnchorPoint(ScreenHelper::ANCHOR_CENTER));
        CCLayerColor *left_black_bar = CCLayerColor::create(ccc4(0,0,0,255), scale*200, winSize.height);
        left_black_bar->setAnchorPoint(ccp(1.0f,1.0f));
        left_black_bar->setPosition(point);
        layer->addChild(left_black_bar,20);
        
        point = ccp(240*scale,-160.0f*scaleY);
        point = ccpAdd(point, ScreenHelper::getAnchorPoint(ScreenHelper::ANCHOR_CENTER));
        
        CCLayerColor *right_black_bar = CCLayerColor::create(ccc4(0,0,0,255), scale*200, winSize.height);
        right_black_bar->setAnchorPoint(ccp(1.0f,1.0f));
        right_black_bar->setPosition(point);
        layer->addChild(right_black_bar,20);
    }
    
    scene->addChild(layer);
    layer->release();
    
    return scene;
}
void Commercial::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
    //Add a new body/atlas sprite at the touched location
    CCSetIterator it;
    CCTouch* touch;
    
    for( it = touches->begin(); it != touches->end(); it++)
    {
        touch = (CCTouch*)(*it);
        
        if(!touch)
            break;
        
        m_TimeOut = -1.0f;
    }
}
