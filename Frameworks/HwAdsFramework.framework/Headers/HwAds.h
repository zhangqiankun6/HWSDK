//
//  HwAds.h
//
//  Created by game team on 2020/05/20.
//  Copyright © 2020 hly. All rights reserved.
//  current version V9.8.33
//  Max version V13.2.0
#import <UIKit/UIKit.h>


#define ADLOADINTERVAL 15
#define MAX_COUNTGAMEBRAIN 10

#define HW_INSTALLTIME @"HW_InstalllTime"
#define HW_LASTSHOWADTIME @"HW_LastShowAdTime"
#define HW_ADJUSTADID @"HW_ADJUSTADID"
#define HW_ABTestRequestTIME @"HW_ABTestRequestTime"
#define HW_InvariantInstallTime @"HW_InvariantInstallTime"

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
- (void)hwAdsRewardedVideoLoadFailWithErrorCode:(NSInteger)errorCode;
//播放失败，不给奖励
- (void)hwAdsRewardedVideoPlayFailWithErrorCode:(NSInteger)errorCode;
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
- (void)hwAdsInterstitialClose;
//插屏展示失败 add 9.5.2
- (void)hwAdsInterstitialFailToShowWithErrorCode:(NSInteger)errorCode;
@end

@protocol HWAdsBannerDelegate <NSObject>
@optional
//banner加载 add 3.1
- (void)hwAdsBannerLoadSuccess;
@end

typedef void (^HWApplePayBlock)(NSString *result);

@interface HwAds : NSObject
{
}


@property (nonatomic, weak) id<HwAdsDelegate> hwAdsDelegate;
@property (nonatomic, weak) id<HWAdsInterDelegate> hwAdsInterDelegate;
@property (nonatomic, weak) id<HWAdsBannerDelegate> hwAdsBannerDelegate;

//实例化
+ (id)instance;
//初始化 serverProjectId为项目在game brain对应的ID  isFirebase是否使用firebase，YES为使用
- (void)initSDK:(int)serverProjectId isFirebase:(BOOL)isFirebase isABTestOpen:(BOOL)isABTestOpen;

- (void)showBanner;

- (void)hideBanner;

- (BOOL)isBannerLoad;

- (void)showInter;

- (BOOL)isFacebookInter;

- (BOOL)isInterLoad;

- (void)showReward:(NSString *)tag;

- (BOOL)isRewardLoad;


/// 内购完成打点方法，二次验证也在这个方法内包含不需要再进行二次验证
/// @param number 内购的金额，传本地化金额
/// @param currency 内购商品的单位，ISO 4217 格式的货币字符串。它应该是3个字符长（例如：对于 1.50 EUR 是 @"EUR"
/// @param myProductId 商品ID 需传入苹果后台创建的商品编号（是一串数字）
/// @param myProductName 商品名称 需传入游戏的具体付费点位名称
/// @param myPurchaseType 商品类型，1是订阅，0是普通商品
/// @param myOrderId 订单的transaction.transactionIdentifier 苹果生成的订单号一段数字 不是本地自己创建的订单号
/// @param myPurchaseToken 订单的transaction receiptString
- (void)hwAnalyticsPurchaseByNumberOfDollars:(NSString *)number
                                   currency:(NSString *)currency
                                   productId:(NSString *)myProductId
                                 productName:(NSString *)myProductName
                                   purchaseType:(NSInteger)myPurchaseType
                                   orderId:(NSString *)myOrderId
                                   purchaseToken:(NSString *)myPurchaseToken;

/// 内购完成打点方法，二次验证也在这个方法内包含不需要再进行二次验证，会返回内购二次验证成功和失败的结果
/// @param number 内购的金额，传本地化金额
/// @param currency 内购商品的单位，ISO 4217 格式的货币字符串。它应该是3个字符长（例如：对于 1.50 EUR 是 @"EUR"
/// @param myProductId 商品ID 需传入苹果后台创建的商品编号（是一串数字）
/// @param myProductName 商品名称 需传入游戏的具体付费点位名称
/// @param myPurchaseType 商品类型，1是订阅，0是普通商品
/// @param myOrderId 订单的transaction.transactionIdentifier 苹果生成的订单号一段数字 不是本地自己创建的订单号
/// @param myPurchaseToken 订单的transaction receiptString
- (void)hwAnalyticsPurchaseByNumberOfDollars:(NSString *)number
                                   currency:(NSString *)currency
                                   productId:(NSString *)myProductId
                                 productName:(NSString *)myProductName
                                   purchaseType:(NSInteger)myPurchaseType
                                   orderId:(NSString *)myOrderId
purchaseToken:(NSString *)myPurchaseToken success:(HWApplePayBlock)success failed:(HWApplePayBlock)failed;


/// 自定义Adjust打点
/// @param adjustToken adjust事件token
- (void)hwAdjustEventToken:(NSString *)adjustToken;

/// 数数关联adjust
/// @param ta_distinct_id 数数访客ID
/// @param ta_account_id 账号 ID (或 角色 ID)，对应 TE 中的 #account_id
- (void)hwAdjustAddTa_distinct_id:(NSString *)ta_distinct_id ta_account_id:(NSString *)ta_account_id;

/// 弹出屏蔽弹窗
- (void)verifyDeviceAndNetworkAvailable;

//设置热更版本号
- (void)setHotfix_version:(NSString *)hotfix_version;

//设置用户是否购买了去广告,YES为已购买去广告
- (void)setRemoveAdsStatus:(BOOL)hasRemoveAds;

/**
 * 记录激励视频按钮点击事件
 * @param adPointName 激励按钮点位的名字
 */
- (void)trackRewardButtonClick:(NSString *)adPointName;


//用于获取Firebase的AB测试值
- (NSString *)getFirebaseAbTestGroup;

/**
 * 获取 SDK 版本
 */

+ (NSString *)sdkVersion;

//用于获取AB测试值
- (NSString *)HwABTestValue;

//用于用户AB测试获取状态判断,获取成功传yes,否传no
- (void)HwAnalyticsUserABTestState:(NSString *)userABTestState;

//add 10.2.61 用于传用户的FB email(经过散列处理后的)和Facebook登录编号
- (void)HwAnalyticsUserFBValue:(NSString *)fbEmail fb_login_id:(NSString *)fb_login_id;

//add 10.2.61 用于打点到Adjust并传用户的FB email(经过散列处理后的)和Facebook登录编号
- (void)HwAdjustTrackWithFBValue:(NSString *)eventToken fbEmail:(NSString *)fbEmail fb_login_id:(NSString *)fb_login_id;

/// 弹出GDPR弹窗
- (void)requestCMP;
//开启UMP测试的方法，需传入测试设备ID，ID可在控制台用UMPDebugSettings.testDeviceIdentifiers查到,测试此方法需在初始化SDK之前调用，正式发布前务必注释此方法
- (void)UMPDebugSetting:(NSString *)testDeviceIdentifiers;

//是否要为用户提供修改其隐私选项的方法
- (BOOL)isPrivacySettingsButtonEnabled;
//撤销GDPR同意
- (void)presentCMPForm;
/// 弹出IDFA弹窗
- (void)hwToAskIDFAAlertView;

/**
 * 检测用户是否为美国用户
 * @param completion 回调block，返回YES表示是美国用户，NO表示不是
 */
- (void)checkIfUserIsUSUser:(void(^)(BOOL isUSUser))completion;

@end


