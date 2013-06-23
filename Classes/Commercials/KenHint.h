//
//  KenHint.h
//  CrashTestMonkeys
//
//  Created by Admin on 6/23/13.
//
//

#ifndef __CrashTestMonkeys__KenHint__
#define __CrashTestMonkeys__KenHint__

#include "Commercial.h"


class KenHint : public Commercial
{
public:
    virtual ~KenHint();
    KenHint();
    void storeButtonTapped(CCObject*object);
    virtual void update(float dt);
};


#endif /* defined(__CrashTestMonkeys__KenHint__) */
