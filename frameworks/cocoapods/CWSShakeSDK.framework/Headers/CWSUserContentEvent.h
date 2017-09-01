//
//  CWSUserContentEvent.h
//  CWSSDK
//
//  Created by Shengsheng on 6/3/17.
//  Copyright © 2017 Cloud Wings. All rights reserved.
//

#import "CWSUserContent.h"

/**
 Event.
 */
@interface CWSUserContentEvent : CWSUserContent

@property(assign, nonatomic) unsigned long long eventId;
@property(copy, nonatomic) NSString *url;
@property(assign, nonatomic) float price;
@property(copy, nonatomic) NSString *currency;
@property(copy, nonatomic) NSString *date;
@property(copy, nonatomic) NSString *sponsor;

@end
