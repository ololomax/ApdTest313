
#include "HelloWorldScene.h"
#include "PluginAppodeal/PluginAppodeal.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    createAdMenu();
    
    return true;
}

void HelloWorld::createAdMenu()
{
    sdkbox::PluginAppodeal::setListener(this);
    
    auto menu = Menu::create();
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("Interstitial", "broadway", 12), [](Ref*){
        CCLOG("Interstitial");
        sdkbox::PluginAppodeal::showAd(sdkbox::PluginAppodeal::AppodealShowStyleInterstitial);
    }));
    
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("SkippableVideo", "broadway", 12), [](Ref*){
        CCLOG("SkippableVideo");
        sdkbox::PluginAppodeal::showAd(sdkbox::PluginAppodeal::AppodealShowStyleSkippableVideo);
    }));
    
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("VideoOrInterstitial", "broadway", 12), [](Ref*){
        CCLOG("VideoOrInterstitial");
        sdkbox::PluginAppodeal::showAd(sdkbox::PluginAppodeal::AppodealShowStyleVideoOrInterstitial);
    }));
    
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("Banner", "broadway", 12), [](Ref*){
        CCLOG("Banner");
        sdkbox::PluginAppodeal::showAd(sdkbox::PluginAppodeal::AppodealShowStyleBannerBottom);
    }));
    
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("Hide Banner", "broadway", 12), [](Ref*){
        CCLOG("HideBanner");
        sdkbox::PluginAppodeal::hideBanner();
    }));
    
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("RewardedVideo", "broadway", 12), [](Ref*){
        CCLOG("RewardedVideo");
        sdkbox::PluginAppodeal::showAd(sdkbox::PluginAppodeal::AppodealShowStyleRewardedVideo);
    }));
    
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("NonSkippableVideo", "broadway", 12), [](Ref*){
        CCLOG("NonSkippableVideo");
        sdkbox::PluginAppodeal::showAd(sdkbox::PluginAppodeal::AppodealShowStyleNonSkippableVideo);
    }));
    
    menu->alignItemsVerticallyWithPadding(10);
    addChild(menu);
}

void HelloWorld::onBannerDidLoadAd()
{
    CCLOG("onBannerDidLoadAd");
}

void HelloWorld::onBannerDidFailToLoadAd()
{
    CCLOG("onBannerDidFailToLoadAd");
}

void HelloWorld::onBannerDidClick()
{
    CCLOG("onBannerDidClick");
}

void HelloWorld::onBannerPresent()
{
    CCLOG("onBannerPresent");
}
// just trigger on android
void HelloWorld::onInterstitialDidLoadAd()
{
    CCLOG("onInterstitialDidLoadAd");
}

void HelloWorld::onInterstitialDidFailToLoadAd()
{
    CCLOG("onInterstitialDidFailToLoadAd");
}

void HelloWorld::onInterstitialWillPresent()
{
    CCLOG("onInterstitialWillPresent");
}

void HelloWorld::onInterstitialDidDismiss()
{
    CCLOG("onInterstitialDidDismiss");
}

void HelloWorld::onInterstitialDidClick()
{
    CCLOG("onInterstitialDidClick");
}

void HelloWorld::onVideoDidLoadAd()
{
    CCLOG("onVideoDidLoadAd");
}

void HelloWorld::onVideoDidFailToLoadAd()
{
    CCLOG("onVideoDidFailToLoadAd");
}

void HelloWorld::onVideoDidPresent()
{
    CCLOG("onVideoDidPresent");
}

void HelloWorld::onVideoWillDismiss()
{
    CCLOG("onVideoWillDismiss");
}

void HelloWorld::onVideoDidFinish()
{
    CCLOG("onVideoDidFinish");
}

void HelloWorld::onRewardVideoDidLoadAd()
{
    CCLOG("onRewardVideoDidLoadAd");
}

void HelloWorld::onRewardVideoDidFailToLoadAd()
{
    CCLOG("onRewardVideoDidFailToLoadAd");
}

void HelloWorld::onRewardVideoDidPresent()
{
    CCLOG("onRewardVideoDidPresent");
}

void HelloWorld::onRewardVideoWillDismiss()
{
    CCLOG("onRewardVideoWillDismiss");
}

void HelloWorld::onRewardVideoDidFinish(int amount, const std::string& name)
{
    CCLOG("onRewardVideoDidFinish, amount = %d, name = %s", amount, name.c_str());
}
