//
//  HelloWorldScene.cpp
//  MonkeyDroid
//
//  Created by Admin on 3/19/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//
#include "CityBackGround.h"
#include "SimpleAudioEngine.h"
#include "../../ScreenHelper.h"
#include "../Level.h"

using namespace cocos2d;
using namespace CocosDenshion;


CityBackGround::CityBackGround()
{
}
void CityBackGround::InitBG(cocos2d::CCNode *layer)
{
    glClearColor(191.0f/255.0f, 92.0f/255.0f, 0.0f/255.0f, 1.0f);
    m_layer = layer;
    pNode = CCParallaxNodeTile::create();
    m_layer->addChild(pNode);
    
    
    CCTextureCache::sharedTextureCache()->addPVRImage("CityScape.pvr.ccz");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("CityScape.plist");
    
    bool cityObjsLoaded = true;
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("CityBG02.plist","CityBG02.png");

    bool balloonObjsLoaded = true;
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("cityBallon.plist","cityBallon.png");
    
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    
    float scale = ScreenHelper::getTextureScale();
    float scaleX = ScreenHelper::getTextureScaleX();
    float scaleY = ScreenHelper::getTextureScaleY();
    
    CCSprite *sprite = CCSprite::create("ctm_City_Merged_BG_01.png");
    sprite->setScaleX(s.width/940.0f);
    sprite->setScaleY(s.width/940.0f);
    pNode->addChild(sprite,0,CCPointMake(1.0f,0.0f),ScreenHelper::getAnchorPointPlusOffset(ScreenHelper::ANCHOR_CENTER,0.0f,40.0f));
    
    if(cityObjsLoaded)
    {
        sprite = CCSprite::createWithSpriteFrameName("ctm_Back_CityScape_01.png");
        pNode->addChild(sprite,0,CCPointMake(1.0f,0.0f),ScreenHelper::getAnchorPointPlusOffset(ScreenHelper::ANCHOR_CENTER,(-256.0f),-80.0f));
        sprite->setScaleX(scaleX);
        sprite->setScaleY(scaleY);
        
        sprite = CCSprite::createWithSpriteFrameName("ctm_Back_CityScape_02.png");
        pNode->addChild(sprite,0,CCPointMake(1.0f,0.0f),ScreenHelper::getAnchorPointPlusOffset(ScreenHelper::ANCHOR_CENTER,(256.0f),-80.0f));
        sprite->setScaleX(scaleX);
        sprite->setScaleY(scaleY);
    }
    
    if(balloonObjsLoaded)
    {
        m_Parallax2 = CCArray::createWithCapacity(4);
        m_Parallax2->retain();
        for(int i = 0; i < 4; i++)
        {
            char name[64];
            sprintf(name,"ctm_BalloonString_%02d.png",i%2+1);
            
            sprite = CCSprite::createWithSpriteFrameName(name);
            sprite->setScale(scale);
            m_Parallax2Points[i] = ScreenHelper::getAnchorPointPlusOffset(ScreenHelper::ANCHOR_BOTTOM_LEFT, 512.0f*i, 110.0f);
            pNode->addChild(sprite,0,CCPointMake(0.91f,0.0f),m_Parallax2Points[i]);
            m_Parallax2->addObject(sprite);
            
            sprintf(name,"ctm_Balloon__%02d.png",(RandomInt(1, 22)));
            
            CCSprite *balloon = CCSprite::createWithSpriteFrameName(name);
            balloon->setPosition(ccp(75.0f,i%2?258:200.0f));
            sprite->addChild(balloon);
            
        }
    }
    
    
    m_Parallax1 = CCArray::createWithCapacity(4);
    m_Parallax1->retain();
    for(int i = 0; i < 4; i++)
    {
        sprite = CCSprite::createWithSpriteFrameName("ctm_Front_CityScape_01A.png");
        sprite->setScale(scale);
        m_Parallax1Points[i] = ScreenHelper::getAnchorPointPlusOffset(ScreenHelper::ANCHOR_BOTTOM_LEFT, 512.0f*i, 73.0f);
        pNode->addChild(sprite,0,CCPointMake(0.90f,0.0f),m_Parallax1Points[i]);
        m_Parallax1->addObject(sprite);
        
    }
    
    m_Track = CCArray::createWithCapacity(4);
    m_Track->retain();
    for(int i = 0; i < 4; i++)
    {
        int r = (2.999f * CCRANDOM_0_1());
        switch(r){
            default:
            case 0:
                sprite = CCSprite::create("City_GraffitiPanels_01.png");
                break;
            case 1:
                sprite = CCSprite::create("City_GraffitiPanels_02.png");
                break;
            case 2:
                sprite = CCSprite::create("City_GraffitiPanels_03.png");
                break;
        }

        sprite->setScaleX(scaleX);
        sprite->setScaleY(scale);
        m_TrackPoints[i] = ScreenHelper::getAnchorPoint(ScreenHelper::ANCHOR_BOTTOM_LEFT);
        m_TrackPoints[i].x += (256.0f*i)*scaleX;
        m_TrackPoints[i].y += -28.0f*scale;
        sprite->setPosition(m_TrackPoints[i]);
        m_layer->addChild(sprite,4);
        m_Track->addObject(sprite);
    }
    
    
}
void CityBackGround::Step(float xpos, float ypos)
{
    float scale = ScreenHelper::getTextureScale();
    float scaleX = ScreenHelper::getTextureScaleX();
    float zoom  = ScreenHelper::getCameraZoom();
    
    BackGround::Step(xpos,ypos);
    
    float count = m_Parallax1->count();
    for ( int ii = 0  ; ii < m_Parallax1->count() ; ii++ )
    {
        CCSprite * parallaxPiece = (CCSprite *)(m_Parallax1->objectAtIndex(ii));
        parallaxPiece->setScale(scaleX*zoom);
        
        CCPoint newPoint;
        newPoint.x = m_Parallax1Points[ii].x*zoom;
        newPoint.y = m_Parallax1Points[ii].y*zoom;
        
        float xRatio = ((CCParallaxNodeTile*)pNode)->getRatio(parallaxPiece).x;
        ((CCParallaxNodeTile*)pNode)->setOffset(newPoint, parallaxPiece);
        //parallaxPiece->setPosition(newPoint);
        
        float size = parallaxPiece->getContentSize().width*scaleX*zoom;
        
               
        if ( (newPoint.x + size) < (xpos*(1.0f-xRatio)))
        {
            m_Parallax1Points[ii].x += 512.0f*scaleX*count;
        }
        if ( (newPoint.x + size) > ((xpos*(1.0f-xRatio))+512.0f*scaleX*count - 150.0f*scaleX))
        {
            m_Parallax1Points[ii].x -= 512.0f*scaleX*count;
        }
    }
}
CityBackGround::~CityBackGround()
{
    if(m_Parallax2)
    {
        m_Parallax2->release();
    }
}
