//
//  Error.h
//  iJuGou
//
//  Created by Shengsheng on 5/8/16.
//  Copyright © 2016 CAP_NTU. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Error.
 */
@interface CWSError : NSObject

@property(assign, nonatomic) NSUInteger errorCode;
@property(copy, nonatomic) NSString *message;

+ (instancetype)errorWithErrorCode:(NSUInteger)errorCode message:(NSString *)message;
+ (instancetype)errorFromDict:(NSDictionary *)dict;

@end
