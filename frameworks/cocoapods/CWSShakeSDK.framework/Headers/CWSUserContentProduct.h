//
//  CWSUserContentProduct.h
//  CWSSDK
//
//  Created by Shengsheng on 6/3/17.
//  Copyright © 2017 Cloud Wings. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CWSUserContent.h"

/**
 Product position of the scene.
 */
typedef struct {
    /** 0: position not exist, 1: top-left, 2: top-right, 3: bottom-right, 4: bottom-left */
    NSUInteger direction;
    NSUInteger left;
    NSUInteger top;
}CWSUserContentProductPosition;

/**
 Product.
 */
@interface CWSUserContentProduct : CWSUserContent

@property(assign, nonatomic) unsigned long long productId;
@property(assign, nonatomic) float price;
@property(copy, nonatomic) NSString *currency;
@property(copy, nonatomic) NSString *source;
@property(copy, nonatomic) NSString *seller;
@property(assign, nonatomic) CWSUserContentProductPosition position;

@end
