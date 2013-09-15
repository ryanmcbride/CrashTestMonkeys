//
//  MonkeyDroidAppDelegate.cpp
//  MonkeyDroid
//
//  Created by Admin on 3/19/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ScreenHelper.h"
#include "FrontEnd/SaveLoad.h"
#include "FrontEnd/FirstLoad.h"
#include "Commercials/CNN.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "StoreBridge/cocos2dx_StoreController.h"
#include "StoreBridge/cocos2dx_EventHandlers.h"
#endif

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    handler = new EventHandler();
#endif
}

AppDelegate::~AppDelegate()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    cocos2dx_EventHandlers::getInstance()->removeHandler(handler);
	delete handler;
#endif
    SaveLoad::Release();
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // turn on display FPS
    pDirector->setDisplayStats(false);
    pDirector->setDepthTest(false);
    pDirector->setAlphaBlending(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    ScreenHelper::Init();
    SaveLoad::Init();
    
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    /**
     * The initialization of StoreController. This is the first and ONLY time it's initialized.
     **/
    cocos2dx_StoreController::initialize("monkeygibberishsecret");
	cocos2dx_EventHandlers::getInstance()->addHandler(handler);
#endif
    
    // run
    pDirector->runWithScene(FirstLoad::scene());
    
    //pDirector->runWithScene(CNN::scene());
    
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
