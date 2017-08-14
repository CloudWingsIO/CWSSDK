//
//  CWSSDK.h
//  CWSSDK
//
//  Created by Shengsheng on 14/11/16.
//  Copyright © 2016 Cloud Wings. All rights reserved.
//

#import <Foundation/Foundation.h>
@class CWSError;

/**
 CWSSDK interface.
 */
@interface CWSSDK : NSObject

/**
 Register a third party app into CWSSDK.
 
 @param appId AppId of the third party app.
 @param appSecret AppSecret of the third party app.
 @param success Called when registration is successful.
 @param failure Called when registration is failed.
 @param timeout Called when registration is timeout.
 */
+ (void)registerWithAppId:(NSString *)appId
                appSecret:(NSString *)appSecret
                  success:(void(^)())success
                  failure:(void(^)(CWSError *error))failure
                  timeout:(void(^)())timeout;

/**
 Retrieve product url for the given productId.
 
 @param productId Product Id.
 */
+ (void)getProductUrlByProductId:(unsigned long long)productId
                         success:(void(^)(NSString *productUrl))success
                         failure:(void(^)(CWSError *error))failure
                         timeout:(void(^)(void))timeout;

@end
