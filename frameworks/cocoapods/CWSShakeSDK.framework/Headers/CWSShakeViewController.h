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

/**
 * Retrieving timeout.
 * @param controller The shake controller.
 */
- (void)shakeControllerDidTimeout:(CWSShakeViewController *)controller;

@end

@interface CWSShakeViewController : UIViewController

@property (weak, nonatomic) id<CWSShakeDelegate> shakeDelegate;

@property (assign, nonatomic) BOOL shakeEnabled;

/** whether to perform audio tag or audio fingerprint (YES: Audio Tag, NO: Audio Fingerprint) */
@property (assign, nonatomic, readonly) BOOL tagOrFp;

/**
 * Simulate a shake without actually shaking device.
 */
- (void)startShake;

/**
 * Cancel shake.
 */
- (void)cancelShake;

/**
 * Switch between audio tag and audio fingerprint.
 * @return New value of tagOrFp (YES: Audio Tag, NO: Audio Fingerprint). You should check if the tagOrFp value has changed. If the ACR is been processing, switching will fail.
 */
- (BOOL)switchTagOrFp;
@end
