//
//  CWSSDK.h
//  CWSSDK
//
//  Created by Shengsheng on 14/11/16.
//  Copyright © 2016 Cloud Wings. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CWSError.h"

@interface CWSShakeManager : NSObject

+ (void)requestPermission;

+ (void)registerWithAppId:(NSString *)appId appSecret:(NSString *)appSecret shakeForProduction:(BOOL)isProduction success:(void(^)())success failure:(void(^)(CWSError *error))failure;

+ (void)getProductUrlByProductId:(unsigned long long)productId success:(void(^)(NSString *productUrl))success failure:(void(^)(CWSError *error))failure;

@end
