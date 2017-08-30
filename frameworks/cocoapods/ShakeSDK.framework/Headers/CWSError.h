//
//  CWSErrorModel.h
//  ShakeSDK
//
//  Created by Jet Lee on 23/8/17.
//  Copyright © 2017 Cloud Wings. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CWSError : NSObject

@property (assign, nonatomic, readonly) NSInteger code;
@property (copy, nonatomic, readonly) NSString *domain;
@property (copy, nonatomic, readonly) NSString *message;
@property (assign, nonatomic, readonly, getter=isReadableMsg) BOOL readableMsg;

- (instancetype)initWithDomain:(NSString *)domain code:(NSInteger)code message:(NSString *)message readableMsg:(BOOL)readableMsg;

+ (instancetype)errorWithNSError:(NSError *)error;
+ (instancetype)errorWithResponse:(NSDictionary *)responseObject andDomain:(NSString *)domain;
+ (instancetype)errorWithDomain:(NSString *)domain code:(NSInteger)code message:(NSString *)message readableMsg:(BOOL)readableMsg;
@end
