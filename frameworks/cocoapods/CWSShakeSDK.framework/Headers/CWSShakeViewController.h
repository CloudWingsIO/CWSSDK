//
//  CWSShakeViewController.h
//  ShakeSDK
//
//  Created by Jet Lee on 30/8/17.
//  Copyright © 2017 Cloud Wings. All rights reserved.
//

#import <UIKit/UIKit.h>

@class CWSShakeViewController, CWSUserContent, CWSError;

@protocol CWSShakeDelegate <NSObject>

@optional

/**
 * Actions if microphone access denied.
 * @param controller The shake controller.
 */
- (void)shakeControllerPermissionDenied:(CWSShakeViewController *)controller;

@required

/**
 * Decide whether user can shake.
 * @param controller The shake controller.
 * @return Whether user can shake.
 */
- (BOOL)shakeControllerCanShake:(CWSShakeViewController *)controller;

/**
 * User has just shook the device.
 * @param controller The shake controller.
 */
- (void)shakeControllerDidShake:(CWSShakeViewController *)controller;

/**
 * Successfully retrieved user content.
 * @param controller The shake controller.
 * @param userContent Retrieved user content.
 */
- (void)shakeController:(CWSShakeViewController *)controller didSucceedWithUserContent:(CWSUserContent *)userContent;

/**
 * User canceled retrieving.
 * @param controller The shake controller.
 */
- (void)shakeControllerDidCancel:(CWSShakeViewController *)controller;

/**
 * Failed to retrieve tag.
 * @param controller The shake controller.
 * @param error Error description.
 */
- (void)shakeController:(CWSShakeViewController *)controller didFailWithError:(CWSError *)error;

@end

@interface CWSShakeViewController : UIViewController

/** Shake delegate for this view controller. */
@property (weak, nonatomic) id<CWSShakeDelegate> shakeDelegate;

/** Enable or disable shake by assigning this field. */
@property (assign, nonatomic) BOOL shakeEnabled;

/**
 * Simulate a shake without actually shaking device.
 */
- (void)startShake;

/**
 * Cancel shake.
 */
- (void)cancelShake;

@end
