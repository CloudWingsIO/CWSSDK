//
//  CWSSDK.h
//  CWSSDK
//
//  Created by Shengsheng on 14/11/16.
//  Copyright © 2016 Cloud Wings. All rights reserved.
//

#import <UIKit/UIKit.h>

@class CWSError;

@interface CWSShakeManager : NSObject

/**
 * Request needed permissions.
 */
+ (void)requestPermission;

/**
 * Register app to SDK server.
 *
 * @param appId AppId.
 * @param appSecret AppSecret.
 * @param success Success callback.
 * @param failure Failure callback.
 */
+ (void)registerWithAppId:(NSString *)appId appSecret:(NSString *)appSecret success:(void(^)(void))success failure:(void(^)(CWSError *error))failure;

/**
 * Get product url for a specific product.
 *
 * @param productId Product id.
 * @param success Success callback.
 * @param failure Failure callback.
 */
+ (void)getProductUrlByProductId:(unsigned long long)productId success:(void(^)(NSString *productUrl))success failure:(void(^)(CWSError *error))failure;

@end
