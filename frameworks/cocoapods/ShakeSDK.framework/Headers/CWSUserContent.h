//
//  CWSUserContent.h
//  CWSSDK
//
//  Created by Shengsheng on 6/3/17.
//  Copyright © 2017 Cloud Wings. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 User content type.
 */
typedef enum : NSUInteger {
    CWSUserContentTypeScene = 1,
    CWSUserContentTypeProduct = 2,
    CWSUserContentTypeEvent = 3
} CWSUserContentType;

/**
 User content.
 */
@interface CWSUserContent : NSObject

@property(assign, nonatomic) CWSUserContentType type;
@property(copy, nonatomic) NSString *title;
@property(copy, nonatomic) NSString *desc;
@property(copy, nonatomic) NSString *imageUrl;
@property(copy, nonatomic) NSDictionary *customizedInfo;

@end
