//
//  CWSUserContentScene.h
//  CWSSDK
//
//  Created by Shengsheng on 18/3/17.
//  Copyright © 2017 Cloud Wings. All rights reserved.
//

#import "CWSUserContent.h"
@class CWSUserContentProduct;

/**
 Scene.
 */
@interface CWSUserContentScene : CWSUserContent

@property(assign, nonatomic) unsigned long long sceneId;
@property(copy, nonatomic) NSString *source;
@property(assign, nonatomic) NSUInteger imageWidth;
@property(assign, nonatomic) NSUInteger imageHeight;
@property(strong, nonatomic) NSArray<CWSUserContentProduct *> *products;

@end
