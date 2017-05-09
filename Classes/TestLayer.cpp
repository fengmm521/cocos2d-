#include "TestLayer.h"


TestLayer::TestLayer(void)
{
}


TestLayer::~TestLayer(void)
{
}

bool TestLayer::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		CCSize visibleSize=CCDirector::sharedDirector()->getVisibleSize();
        //HelloWorld
        
        Sprite* background = Sprite::create("HelloWorld.png");
		background->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
		this->addChild(background,kTagBackground);

		clip=CCClippingNode::create();
		clip->setInverted(true);
		clip->setAlphaThreshold(0.0f);
		this->addChild(clip,kTagClipNode);

		CCLayerColor* back=CCLayerColor::create(ccc4(0,0,0,200));
		clip->addChild(back);

		//以下模型是drawnode遮罩
		//CCDrawNode* front=CCDrawNode::create();
		//ccColor4F yellow = {1, 1, 0, 1};
		//CCPoint rect[4]={ccp(-30,30),ccp(30,30),ccp(30,-30),ccp(-30,-30)};
		//front->drawPolygon(rect, 4, yellow, 0, yellow);
		//front->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
		//clip->setStencil(front);

		//以下模型是带图像遮罩
		nodef=CCNode::create();
		CCSprite* close=CCSprite::create("mask.png");
		nodef->addChild(close);
		nodef->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
		clip->setStencil(nodef);

		tip = CCSprite::create("tip.png");
		tip->setScale(0.5f);
		tip->setRotation(60);
		tip->setPosition(ccp(visibleSize.width/2-70,visibleSize.height/2+50));
		this->addChild(tip,kTagTip);

		tip->runAction(CCRepeatForever::create(CCSequence::create(CCScaleBy::create(0.25f,0.95f),CCScaleTo::create(0.25f,0.5),NULL)));

		this->setTouchEnabled(true);
        
        EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
        listener ->onTouchBegan = CC_CALLBACK_2(TestLayer::onTouchBegan, this);
        listener ->onTouchMoved = CC_CALLBACK_2(TestLayer::onTouchMoved, this);
        listener ->onTouchEnded = CC_CALLBACK_2(TestLayer::onTouchEnded, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener , this);
        
        
		bRet=true;

	} while (0);
	return bRet;
}

//void TestLayer::registerWithTouchDispatcher()  
//{  
//	CCDirector *pDirector=CCDirector::sharedDirector();  
//	pDirector->getTouchDispatcher()->addTargetedDelegate(this,0,true);  
//}

bool TestLayer::onTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
//	CCSize visibleSize=CCDirector::sharedDirector()->getVisibleSize();
//
//	CCPoint point=CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
//	CCRect rect=CCRectMake(visibleSize.width/2-30,visibleSize.height/2-30,60,60);
//	if (rect.containsPoint(point))
//	{
//		this->removeChild(tip);
//		this->removeChild(clip);
//		return true;
//	}
	return true;
}
void TestLayer::onTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{

    CCPoint point=CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
    nodef->setPosition(point);
//    CCRect rect=CCRectMake(visibleSize.width/2-30,visibleSize.height/2-30,60,60);
//    if (rect.containsPoint(point))
//    {
//        this->removeChild(tip);
//        this->removeChild(clip);
//        return true;
//    }
//    return false;
}
void TestLayer::onTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    
    CCPoint point=CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
    nodef->setPosition(point);
//    CCSize visibleSize=CCDirector::sharedDirector()->getVisibleSize();
//    
//    CCPoint point=CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
//    CCRect rect=CCRectMake(visibleSize.width/2-30,visibleSize.height/2-30,60,60);
//    if (rect.containsPoint(point))
//    {
//        this->removeChild(tip);
//        this->removeChild(clip);
//        return true;
//    }
//    return false;
}
