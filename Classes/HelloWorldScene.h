#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PluginAppodeal/PluginAppodeal.h"

class HelloWorld : public cocos2d::Layer, public sdkbox::AppodealListener
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
private:
    void createAdMenu();
    
    virtual void onBannerDidLoadAd();
    virtual void onBannerDidFailToLoadAd();
    virtual void onBannerDidClick();
    virtual void onBannerPresent(); // just trigger on android
    
    virtual void onInterstitialDidLoadAd();
    virtual void onInterstitialDidFailToLoadAd();
    virtual void onInterstitialWillPresent();
    virtual void onInterstitialDidDismiss();
    virtual void onInterstitialDidClick();
    
    virtual void onVideoDidLoadAd();
    virtual void onVideoDidFailToLoadAd();
    virtual void onVideoDidPresent();
    virtual void onVideoWillDismiss();
    virtual void onVideoDidFinish();
    
    virtual void onRewardVideoDidLoadAd();
    virtual void onRewardVideoDidFailToLoadAd();
    virtual void onRewardVideoDidPresent();
    virtual void onRewardVideoWillDismiss();
    virtual void onRewardVideoDidFinish(int amount, const std::string& name);

};

#endif // __HELLOWORLD_SCENE_H__
