//
//  KenHint.cpp
//  CrashTestMonkeys
//
//  Created by Admin on 6/23/13.
//
//

#include "KenHint.h"
#include "SimpleAudioEngine.h"
#include "../ScreenHelper.h"
#include "../AudioManager.h"
#include "../FrontEnd/Store/Store.h"

using namespace cocos2d;
using namespace CocosDenshion;

KenHint::KenHint()
{
    
    float scale = ScreenHelper::getTextureScale();
    
    CCSprite *hintsprite = NULL;
    int hintnum = CCRANDOM_0_1()*5;
    switch(hintnum)
    {
        default:
        case 0:
            hintsprite = CCSprite::create("Hints_0000.png");
            break;
        case 1:
            hintsprite = CCSprite::create("Hints_0001.png");
            break;
        case 2:
            hintsprite = CCSprite::create("Hints_0002.png");
            break;
        case 3:
            hintsprite = CCSprite::create("Hints_0003.png");
            break;
        case 4:
            hintsprite = CCSprite::create("Hints_0004.png");
            break;
    }
    
    hintsprite->setPosition(ScreenHelper::getAnchorPoint(ScreenHelper::ANCHOR_CENTER));
    hintsprite->setScale(ScreenHelper::getTextureScale());
    
    addChild(hintsprite);
    
    CCSprite *normal = CCSprite::createWithSpriteFrameName("ctm_Button_17.png");
    CCSprite *down = CCSprite::createWithSpriteFrameName("ctm_Button_17_Down.png");
    normal->setOpacity(0);
    down->setOpacity(0);
    
    CCMenuItem *StoreButton = CCMenuItemSprite::create(normal, down, this, menu_selector(KenHint::storeButtonTapped));
    StoreButton->setScale(scale);
    StoreButton->setPosition(ScreenHelper::getAnchorPointPlusOffset(ScreenHelper::ANCHOR_BOTTOM_RIGHT,-55.0f,40.0f));
    
    CCMenu* menu = CCMenu::create(StoreButton, NULL);
    menu->setPosition(ScreenHelper::getAnchorPointPlusOffset(ScreenHelper::ANCHOR_BOTTOM_LEFT,0.0f,0.0f));
    addChild(menu,4);
    
    //StoreButton->setVisible(false);
    m_TimeOut = 5.0f;
    
}
void KenHint::update(float dt)
{
    Commercial::update(dt);
    if(!SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic("CTMThemeMusicv3.3gp", true);
}
void KenHint::storeButtonTapped(CCObject*object)
{
    m_TimeOut = 5.0f;
    SimpleAudioEngine::sharedEngine()->playEffect("Select.wav", false);
    CCDirector::sharedDirector()->pushScene(Store::scene());
}
KenHint::~KenHint()
{
    
}
