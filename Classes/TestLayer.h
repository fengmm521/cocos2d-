#pragma once
#include "cocos2d.h"

USING_NS_CC;

const int kTagBackground=0;
const int kTagClipNode=1;
const int kTagTip=2;


class TestLayer : public Layer
{
public:
	TestLayer(void);
	~TestLayer(void);

	CREATE_FUNC(TestLayer);

	virtual bool init();

//    virtual void registerWithTouchDispatcher();
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	//virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);

    virtual void onTouchEnded(Touch *touch, Event *unused_event);
	ClippingNode* clip;
	Sprite* tip;
    Node* nodef;
};

