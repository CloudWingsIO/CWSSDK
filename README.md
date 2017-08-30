Date: 05-Jun-2017

Revision: 2.0.1

Change log:

- 2.0.1

- fixed archieve error bitcode bundle could not be generated because was built without full bitcode

- 2.0.0

Breaking API change.

- 1.0.21

Minor updates.

- 1.0.20

Mixed compatible and incompatible.

- 1.0.19-c

Compatible with old audio tag algorithm.

- 1.0.19

Minor optimization.

- 1.0.18

Remove support to the old audio tag algorithm.

- 1.0.6

Supporting new audio tag algorithm.

- 1.0.4

Supporting IPV6 in production environment.

- 1.0.3

Add IPV6 support(for experimental use only, please do not use it in product env)

- 1.0.2

Add IPV6 support(for experimental use only, please do not use it in product env)

- 1.0.1

CWSSDK interface updated.

## Preface

This document demonstrates how to integrate CWS SDK into your iOS project.

## SDK

**Version**: 1.0.6

**Description**: The SDK provides ACR(Automatic Content Recognition) function which allows 3rd party apps to retrieve user-defined contents by listening to audio sources.

## Prerequisities

**Language**: Objective-C

**IDE**: XCode 8

**Credentials**: appId & appSecret

## Install

### Installation with CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries like CWSSDK in your projects. You can install it with the following command:

```bash
$ gem install cocoapods
```

> CocoaPods 0.39.0+ is required to build CWSSDK 1.0.0+.

#### Podfile

To integrate CWSSDK into your Xcode project using CocoaPods, specify it in your `Podfile`:

```ruby
platform :ios, '8.0'

target 'Target' do
    use_frameworks!
    inhibit_all_warnings!

    pod 'CWSSDK', '~> 1.0'
    target 'TargetTests' do
        inherit! :search_paths
        # Pods for testing
    end
end
```

Then, run the following command:

```bash
$ pod install
```

### Manually

1. Download [CWSSDK_iOS_1.0.6.zip](https://cwspro.oss-ap-southeast-1.aliyuncs.com/SDK/iOS/CWSSDK_iOS_1.0.6.zip "CWSSDK_iOS_1.0.6.zip") and unzip it. You will get the following files:

	- **CWSSDK.framework**: Framework file to be linked to your iOS project.
	- **CWSSDKDemo**: Demo iOS app project which has already integrated the SDK.

2. Copy **CWSSDK.framework** to your project folder and add it to your project.

3. Link the framework file to your project.

	Click **Project** > **Target** > **General tab** > **Plus symbol in the Linked Frameworks and Libraries** > **Add Other...**:

4. Create a new copy file phase and copy the framework file as framework.

	In the same view, click **Build Phases** > **Plus symbol in the top left** > **New Copy File Phase**:

## Getting Started

1. Add **NSMicrophoneUsageDescription** to the **Info.plist** of your project.

	Note that our SDK uses microphone when the user triggers the shake event. And it is compulsory to add the abovementioned key value pair to the Info.plist. Otherwise, the app will not be able to run.

2. Import SDK header file.

```
#import <CWSSDK/CWSSDK.h>
```

7. Make your view controller extends CWSViewController.

```
@interface ViewController : CWSShakeViewController
```

8. Make your view controller or any other object confirm to CWSShakeDelegate and implements all the required methods defined in the delegate.

The CWSDelegate is a protocol defined in the SDK. The declaration is as follows:

```
@protocol CWSShakeDelegate <NSObject>

@required

- (void)shakeControllerDidShake:(CWSShakeViewController *)controller;

- (void)shakeController:(CWSShakeViewController *)controller didSucceedWithUserContent:(CWSUserContent *)userContent;

- (void)shakeControllerDidCancel:(CWSShakeViewController *)controller;

- (void)shakeController:(CWSShakeViewController *)controller didFailWithError:(CWSError *)error;

- (void)shakeControllerDidTimeout:(CWSShakeViewController *)controller;
@end
```

Confirm to this protocol:

```
@interface ViewController () <CWSShakeDelegate>

self.shakeDelegate = self;
```

9. Call the **register** method with your **appId** and **appSecret** before using any other functions of the SDK.

```
[CWSSDK registerWithAppId:APP_ID appSecret:APP_SECRET success:^{

} failure:^(CWSError *error) {

} timeout:^{

}];
```

10. Compile and run the application.

Since our SDK uses microphone to record audio and the only way to trigger the recording is by shaking, you have to test the app in a real device. You may need a demo video to test the ACR functionality. You can test your application with this demo video: https://shake2buy.com/
