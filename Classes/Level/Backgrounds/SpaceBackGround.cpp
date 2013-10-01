//
//  HelloWorldScene.cpp
//  MonkeyDroid
//
//  Created by Admin on 3/19/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//
#include "SpaceBackGround.h"
#include "SimpleAudioEngine.h"
#include "../../ScreenHelper.h"
#include "../Level.h"

using namespace cocos2d;
using namespace CocosDenshion;


SpaceBackGround::SpaceBackGround()
{
}
void SpaceBackGround::InitBG(cocos2d::CCNode *layer)
{
    glClearColor(0.0f/255.0f, 0.0f/255.0f, 0.0f/255.0f, 1.0f);
    m_layer = layer;
    pNode = CCParallaxNodeTile::create();
    m_layer->addChild(pNode);
    
        
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    //////////////
    //Adding some comments to test out a git pull request
    //
    //
    bool nasaObjsLoaded = true;
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("spaceBG.plist","spaceBG.png");
    
    float scale = ScreenHelper::getTextureScale();
    float scaleX = ScreenHelper::getTextureScaleX();
    float scaleY = ScreenHelper::getTextureScaleY();
    
    CCSprite *sprite = CCSprite::create("ctm_SpaceGradient_Merged_BG.png");
    sprite->setScaleX(s.width/940.0f);
    sprite->setScaleY(s.width/940.0f);
    pNode->addChild(sprite,0,CCPointMake(1.0f,0.0f),ScreenHelper::getAnchorPointPlusOffset(ScreenHelper::ANCHOR_CENTER,0.0f,40.0f));
    
    CCSprite *moon;
    switch (RandomInt(0, 7)) {
        default:
        case 0:
            moon = CCSprite::create("ctm_Nasa_Jupitor.png");
            break;
        case 1:
            moon = CCSprite::create("ctm_Nasa_Mars.png");
            break;
        case 2:
            moon = CCSprite::create("ctm_Nasa_Mercury.png");
            break;
        case 3:
            moon = CCSprite::create("ctm_Nasa_Neptune.png");
            break;
        case 4:
            moon = CCSprite::create("ctm_Nasa_Saturn.png");
            break;
        case 5:
            moon = CCSprite::create("ctm_Nasa_Uranus.png");
            break;
        case 6:
            moon = CCSprite::create("ctm_Nasa_Venus.png");
            break;
    }
    moon->setAnchorPoint(ccp(0.5f,0.5f));
    moon->setScale(scale);
    pNode->addChild(moon,0,CCPointMake(1.0f,0.0f),ScreenHelper::getAnchorPointPlusOffset(ScreenHelper::ANCHOR_CENTER,RandomFloat(-200.0f, 100.0f),RandomFloat(-25.0f, 25.0f)));
    
    m_Parallax1 = CCArray::createWithCapacity(4);
    m_Parallax1->retain();
    for(int i = 0; i < 4; i++)
    {
        char temp[64];
        sprintf(temp,"ctm_Moon_%02d.png",i+1);
        sprite = CCSprite::create(temp);
        sprite->setScale(scale);
        m_Parallax1Points[i] = ScreenHelper::getAnchorPointPlusOffset(ScreenHelper::ANCHOR_BOTTOM_LEFT, 256.0f*i, 53.0f);
        pNode->addChild(sprite,1,CCPointMake(0.90f,0.0f),m_Parallax1Points[i]);
        m_Parallax1->addObject(sprite);
        
    }
    
    if(nasaObjsLoaded)
    {
        m_Parallax2 = CCArray::createWithCapacity(4);
        m_Parallax2->retain();
        m_Parallax3 = CCArray::createWithCapacity(4);
        m_Parallax3->retain();
        
        int last = -1;
        std::vector<int> poster_rand;
        std::vector<int> retro_rand;
        object_vals.clear();
        for(int i = 0; i < 4; i++)
        {

            //head
            char name[64];
            if(last != 0 && RandomInt(0, 100)>90)
            {
                if(poster_rand.size()>0){
                    int new_rand;
                    bool found = false;
                    do{
                        found = false;
                        new_rand = RandomInt(1, 7);
                        for(int j=0; j < poster_rand.size(); j++){
                            int val = poster_rand[j];
                            if(val == new_rand){
                                found = true;
                                break;
                            }
                        }
                    }while(found);
                    poster_rand.push_back(new_rand);
                }else{
                    poster_rand.push_back(RandomInt(1, 7));
                }
                last = 0;
                sprintf(name,"ctm_SpacePoster_%02d.png",poster_rand.back());
                sprite = CCSprite::createWithSpriteFrameName(name);
                sprite->setScale(scale);
                m_Parallax2Points[i] = ScreenHelper::getAnchorPointPlusOffset(ScreenHelper::ANCHOR_BOTTOM_LEFT, 256.0f*i-192.0f, 103.0f);
                pNode->addChild(sprite,2,CCPointMake(0.90f,0.0f),m_Parallax2Points[i]);
                m_Parallax2->addObject(sprite);
            }
            else
            {
                last = 1;
                if(retro_rand.size()>0){
                    int new_rand;
                    bool found = false;
                    do{
                        found = false;
                        new_rand = RandomInt(1, 6);
                        for(int j=0; j < retro_rand.size(); j++){
                            int val = retro_rand[j];
                            if(val == new_rand){
                                found = true;
                                break;
                            }
                        }
                    }while(found);
                    retro_rand.push_back(new_rand);
                }else{
                    retro_rand.push_back(RandomInt(1, 6));
                }
                sprintf(name,"ctm_space_Retro%02d.png",(RandomInt(1, 6)));
                CCNode *object = getBGObject();
                m_Parallax2Points[i] = ScreenHelper::getAnchorPointPlusOffset(ScreenHelper::ANCHOR_BOTTOM_LEFT, 256.0f*i-128.0f+object->getPositionX(), 103.0f+object->getPositionY());
                pNode->addChild(object,object->getZOrder(),CCPointMake(0.90f,0.0f),m_Parallax2Points[i]);
                m_Parallax2->addObject(object);
            }
            
            //torch
            CCNode *object = getBGObject();
            m_Parallax3Points[i] = ScreenHelper::getAnchorPointPlusOffset(ScreenHelper::ANCHOR_BOTTOM_LEFT, 256.0f*i+object->getPositionX(), 103.0f+object->getPositionY());
            pNode->addChild(object,object->getZOrder(),CCPointMake(0.90f,0.0f),m_Parallax3Points[i]);
            m_Parallax3->addObject(object);
        }
        
    }
    else
    {
        m_Parallax2 = NULL;
    }
    
    
    
    m_Track = CCArray::createWithCapacity(4);
    m_Track->retain();
    for(int i = 0; i < 4; i++)
    {
        int r = 2.999f * CCRANDOM_0_1();
        switch(r){
            default:
            case 0:
                sprite = CCSprite::create("Space_Panels_01.png");
                break;
            case 1:
                sprite = CCSprite::create("Space_Panels_02.png");
                break;
            case 2:
                sprite = CCSprite::create("Space_Panels_03.png");
                break;
        }
        sprite->setScaleX(scaleX);
        sprite->setScaleY(scaleY);
        m_TrackPoints[i] = ScreenHelper::getAnchorPoint(ScreenHelper::ANCHOR_BOTTOM_LEFT);
        m_TrackPoints[i].x += (256.0f*i)*scaleX;
        m_TrackPoints[i].y += -28.0f*scale;
        sprite->setPosition(m_TrackPoints[i]);
        m_layer->addChild(sprite,4);
        m_Track->addObject(sprite);
        
        /*       sprite = CCSprite::create("ctm_256_Front_hazardstripe.png");
         sprite->setScaleX(scaleX);
         sprite->setScaleY(scaleY);
         sprite->setPosition(ScreenHelper::getAnchorPointPlusOffset(ScreenHelper::ANCHOR_BOTTOM_LEFT, 256.0f*i, 55.0f));
         addChild(sprite,4);
         */
    }
    
    
}
CCNode *SpaceBackGround::getBGObject()
{
    float scale = ScreenHelper::getTextureScale();
    CCSprite *sprite = NULL;
    CCNode *node = NULL;
    
    char name[64];
    
    if(object_vals.size()>=7)object_vals.clear();
    if(object_vals.size()>0){
        int new_rand;
        bool found = false;
        do{
            found = false;
            new_rand = RandomInt(1, 8);
            for(int j=0; j < object_vals.size(); j++){
                int val = object_vals[j];
                if(val == new_rand){
                    found = true;
                    break;
                }
            }
        }while(found);
        object_vals.push_back(new_rand);
    }else{
        object_vals.push_back(RandomInt(1, 8));
    }
    
    switch(object_vals.back())
    {
        default:
        case 1:
        /*    sprintf(name,"ctm_space_saucer%02d.png",(RandomInt(1, 7)));
            sprite = CCSprite::createWithSpriteFrameName(name);
            node = CCNode::create();
            sprite->setPosition(ccp(RandomFloat(-10.0f, 10.0f),RandomFloat(100, 300)));
            sprite->runAction(
                CCRepeatForever::create(
                    CCSequence::create(
                        CCMoveBy::create(RandomFloat(10, 20), ccp(RandomFloat(100, 500),0.0f)),
                        CCMoveBy::create(RandomFloat(10, 20), ccp(RandomFloat(-100, -500),0.0f)),
                        NULL)));
            node->addChild(sprite);
            node->setZOrder(0);*/
            node = CCNode::create();
            break;
        case 2:
            sprintf(name,"ctm_Space_Buggy%02d.png",(RandomInt(1, 3)));
            sprite = CCSprite::createWithSpriteFrameName(name);
            sprite->setPosition(ccp(RandomFloat(-10.0f, 10.0f),RandomFloat(-60.0f, -20.0f)));
            node = sprite;
            node->setZOrder(2);
            sprite->setScale(scale);
            break;
        case 3:
            sprintf(name,"ctm_Space_nasa%02d.png",(RandomInt(1, 5)));
            sprite = CCSprite::createWithSpriteFrameName(name);
            sprite->setPosition(ccp(RandomFloat(-10.0f, 10.0f),RandomFloat(5.0f, 0.0f)));
            node = sprite;
            node->setZOrder(2);
            sprite->setScale(scale);
            break;
        case 4:
        /*    sprintf(name,"ctm_Space_Satelite%02d.png",(RandomInt(1, 5)));
            sprite = CCSprite::createWithSpriteFrameName(name);
            node = CCNode::create();
            sprite->setPosition(ccp(RandomFloat(-10.0f, 10.0f),RandomFloat(100, 300)));
            node->addChild(sprite);
            node->setZOrder(0);
            node->runAction(CCRepeatForever::create(CCRotateBy::create(RandomFloat(10.0f, 30.0f), 360.0f)));
            break;*/
        case 5:
           /* if(RandomInt(0, 10)>5)
                sprintf(name,"ctm_Space_Mercury1.png");
            else
                sprintf(name,"ctm_Space_Mercury1small.png");
            sprite = CCSprite::createWithSpriteFrameName(name);
            sprite->setPosition(ccp(RandomFloat(-10.0f, 10.0f),RandomFloat(100,300)));
            node = CCNode::create();
            node->addChild(sprite);
            node->setZOrder(0);
            node->runAction(CCRepeatForever::create(CCRotateBy::create(RandomFloat(10.0f, 30.0f), 360.0f)));*/
            node = CCNode::create();
            break;
        case 6:
            sprintf(name,"ctm_Space_Shuttle01.png");
            sprite = CCSprite::createWithSpriteFrameName(name);
            sprite->setPosition(ccp(RandomFloat(-10.0f, 10.0f),0.0f));
            node = sprite;
            node->setZOrder(2);
            sprite->setScale(scale);
            break;
        case 7:
            sprintf(name,"ctm_Space_module01.png");
            sprite = CCSprite::createWithSpriteFrameName(name);
            node = CCNode::create();
            sprite->setPosition(ccp(RandomFloat(-10.0f, 10.0f),-20.0f));
            node = sprite;
            node->setZOrder(2);
            sprite->setScale(scale);
            break;
    };
    
    
    return node;
}

void SpaceBackGround::Step(float xpos, float ypos)
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
        
        
        if(m_Parallax2)
        {
            CCPoint newPoint2;
            CCSprite *parallaxPiece2;
            
            newPoint2.x = m_Parallax2Points[ii].x*zoom;
            newPoint2.y = m_Parallax2Points[ii].y*zoom;
            parallaxPiece2 = (CCSprite *)(m_Parallax2->objectAtIndex(ii));
            ((CCParallaxNodeTile*)pNode)->setOffset(newPoint2, parallaxPiece2);
            parallaxPiece2->setScale(scaleX*zoom);
            if ( (newPoint2.x + size) < (xpos*(1.0f-xRatio)))
            {
                m_Parallax2Points[ii].x += 256.0f*scaleX*count;
            }
            if ( (newPoint2.x + size) > ((xpos*(1.0f-xRatio))+256.0f*scaleX*count - 150.0f*scaleX))
            {
                m_Parallax2Points[ii].x -= 256.0f*scaleX*count;
            }
            
            newPoint2.x = m_Parallax3Points[ii].x*zoom;
            newPoint2.y = m_Parallax3Points[ii].y*zoom;
            parallaxPiece2 = (CCSprite *)(m_Parallax3->objectAtIndex(ii));
            ((CCParallaxNodeTile*)pNode)->setOffset(newPoint2, parallaxPiece2);
            parallaxPiece2->setScale(scaleX*zoom);
            if ( (newPoint2.x + size) < (xpos*(1.0f-xRatio)))
            {
                m_Parallax3Points[ii].x += 256.0f*scaleX*count;
            }
            if ( (newPoint2.x + size) > ((xpos*(1.0f-xRatio))+256.0f*scaleX*count - 150.0f*scaleX))
            {
                m_Parallax3Points[ii].x -= 256.0f*scaleX*count;
            }            
        }
        
        
        if ( (newPoint.x + size) < (xpos*(1.0f-xRatio)))
        {
            m_Parallax1Points[ii].x += 256.0f*scaleX*count;
        }
        if ( (newPoint.x + size) > ((xpos*(1.0f-xRatio))+256.0f*scaleX*count - 150.0f*scaleX))
        {
            m_Parallax1Points[ii].x -= 256.0f*scaleX*count;
        }
    }
}
SpaceBackGround::~SpaceBackGround()
{
}
