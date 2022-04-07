//
//  HLYGoogleAppOpenAd.h
//  UpFrameworkDemo1
//
//  Created by 天才哈士奇 on 2021/3/2.
//  Copyright © 2021 天才哈士奇. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GoogleMobileAds/GoogleMobileAds.h>
NS_ASSUME_NONNULL_BEGIN

@protocol HwGoogleOpenAdDelegate <NSObject>

-(void)hwGoogleOpenAdClose;

@end

@interface HLYGoogleAppOpenAd : NSObject<GADFullScreenContentDelegate>

@property (nonatomic, weak) id<HwGoogleOpenAdDelegate> hwGoogleOpenAdsDelegate;

+ (id)instance;

- (void)initGoogleOpenADByID:(NSString *)adId;

- (void)tryToPresentAd;
@end

NS_ASSUME_NONNULL_END
