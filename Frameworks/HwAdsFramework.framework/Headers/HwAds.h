//
//  HwAds.h
//  TestMopub
//
//  Created by game team on 2020/05/20.
//  Copyright © 2020 hly. All rights reserved.
//  current version V9.0.1
//  Max version V10.3.7
#import <UIKit/UIKit.h>

//mopub test id
//#define BANNERID @"0ac59b0996d947309c33f59d6676399f"
//#define INTERID @"4f117153f5c24fa6a3a92b818a5eb630"
//#define REWARDID @"8f000bd5e00246de9c789eed39ff6096"



#define MAXINTERID @""
#define MAXREWARDID @""
#define MAXBANNERID @""

#define GOOGLEOPENADID @""

#define ADLOADINTERVAL 10
#define MAX_COUNTGAMEBRAIN 10

#define HW_INSTALLTIME @"HW_InstalllTime"
#define HW_LASTSHOWADTIME @"HW_LastShowAdTime"
#define HW_COUNTRYCODE @"HW_CountryCode"

#define HW_REWARDID @"HW_REWARDID"
#define HW_INTERID @"HW_INTERID"
#define HW_BANNERID @"HW_BANNERID"
//#define HW_SCENETAG @"HW_SCENETAG"

#define HW_MAXBANNERID @"HW_MAXBANNERID"
#define HW_MAXREWARDID @"HW_MAXREWARDID"
#define HW_MAXINTERID @"HW_MAXINTERID"

#define HW_GOOGLEOPENADID @"HW_GOOGLEOPENADID"

#ifndef HwAds_h
#define HwAds_h

#endif /* HwAds_h */

typedef NS_ENUM(NSInteger, AJHwSDKUACType) {
    
    /**
     * UAC新手引导完成打点
     */
    AJHWGuideFinish = 0,
    /**
     * UAC其他具体事件点
     */
    AJHWLevel ,
    /**
     * UAC看视频用户打点high
     */
    AJHWVideohigh ,
    /**
     * UAC看视频用户打点low
     */
    AJHWVideolow ,
    /**
     * UAC内购用户打点
     */
    AJHWPurchase ,

};

@protocol HwAdsDelegate <NSObject>
@optional
//加载成功  添加delegate
- (void)hwAdsRewardedVideoLoadSuccess;
//加载失败
- (void)hwAdsRewardedVideoLoadFail;
//播放失败，不给奖励
- (void)hwAdsRewardedVideoPlayFail;
//广告展示
- (void)hwAdsRewardedVideoDidAppear;
//广告关闭
- (void)hwAdsRewardedVideoClose;
//广告被点击
- (void)hwAdsRewardedVideoClick;
//广告播放完成，给奖励，最好在这里做标记，在close中给
- (void)hwAdsRewardedVideoGiveReward;
//广告即将展示，建议在收到这个回调时，暂停游戏；
- (void)hwAdsRewardedVideoWillAppear;
@end

@protocol HWAdsInterDelegate <NSObject>
@optional
//插屏加载
- (void)hwAdsInterstitialLoadSuccess;
//加载失败
- (void)hwAdsInterstitialLoadFail;
//插屏点击 add 3.0
- (void)hwAdsInterstitialClick;
//插屏播放 add 3.0
- (void)hwAdsInterstitialShow;
//插屏关闭 add 3.0
- (void)hwAdsInterstitialCloseIsFacebookOrAdmob:(BOOL)isFacebookOrAdmob;
@end

@protocol HWAdsBannerDelegate <NSObject>
@optional
//banner加载 add 3.1
- (void)hwAdsBannerLoadSuccess;
@end

@interface HwAds : NSObject
{
}


@property (nonatomic, weak) id<HwAdsDelegate> hwAdsDelegate;
@property (nonatomic, weak) id<HWAdsInterDelegate> hwAdsInterDelegate;
@property (nonatomic, weak) id<HWAdsBannerDelegate> hwAdsBannerDelegate;

//实例化
+ (id)instance;
//初始化 serverProjectId为项目在game brain对应的ID
- (void)initSDK:(int)serverProjectId;

- (void)showBanner;

- (void)hideBanner;

- (BOOL)isBannerLoad;

- (void)showInter;

- (BOOL)isFacebookInter;

- (BOOL)isInterLoad;

- (void)showReward:(NSString *)tag;

- (BOOL)isRewardLoad;


/// 内购完成打点方法，二次验证也在这个方法内包含不需要再进行二次验证
/// @param number 转换成美元的价格
/// @param myProductId 商品ID
/// @param myPurchaseType 商品类型，1是订阅，0是普通商品
/// @param myOrderId 订单ID
/// @param myPurchaseToken 订单token
- (void)hwAnalyticsPurchaseByNumberOfDollars:(NSString *)number
                                   productId:(NSString *)myProductId
                                   purchaseType:(NSString *)myPurchaseType
                                   orderId:(NSString *)myOrderId
                                   purchaseToken:(NSString *)myPurchaseToken;

/// 自定义Adjust打点
/// @param adjustToken adjust事件token
- (void)hwAdjustEventToken:(NSString *)adjustToken;


/**
 * 获取 SDK 版本
 */

+ (NSString *)sdkVersion;

@end


