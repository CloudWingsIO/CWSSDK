Date: 18-Oct-2017

Revision: 3.2.0

Change log:

- 3.2.0

Shake delegate timeout callback combined to failure callback.
Added more comments.

- 3.1.1

Fixed Xcode 9 block warning

- 3.0.1

Combined Tag and Fp

- 2.3.2

Tag algorithm recognize bug fixed

- 2.3.1

Tag algorithm memory leak fixed

- 2.3.0

Old algo removed

- 2.2.0

Retry bug fixed

- 2.1.0

Name changed

- 2.0.3

fix fp crash bug

- 2.0.2

fixed archieve error bitcode bundle could not be generated because was built without full bitcode

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

This document demonstrates how to integrate CWSShakeSDK into your iOS project.

## SDK

**Version**: 3.2.0<br>
**Description**: The SDK provides ACR(Automatic Content Recognition) functionality which allows 3rd party apps to retrieve user-defined contents by listening to audio sources.<br>

## Prerequisites

**Language**: Objective-C<br>
**IDE**: XCode<br>
**Credentials**: appId & appSecret

## Installation

### Cocoapods

```
pod 'CWSSDK'
```

### Manual

1. Download [**CWSShakeSDK_iOS_3.2.0.zip**](http://cwspro.oss-ap-southeast-1.aliyuncs.com/SDK/iOS/archive/CWSShakeSDK_iOS_3.2.0.zip "CWSShakeSDK_iOS_3.2.0.zip") and unzip it. You will get the following files:
  - **CWSShakeSDK.framework**: Framework file to be linked to your iOS project.
  - **ShakeSDKDemo**: Demo iOS app project which has already integrated the SDK.
  - **iOS_CWSShakeSDK_Integration_Manual.pdf**: Integration manual.

2. Copy **CWSShakeSDK.framework** to your project folder and add it to your project.
![](http://cwspro.oss-ap-southeast-1.aliyuncs.com/SDK/iOS/resource/IntegrationManual/screenshots_2/1_import.jpeg)

3. Create a new copy file phase and copy the framework file as framework.<br><br>
In the project view, click **Build Phases** > **Plus symbol in the top left** > **New Copy File Phase**:
![](http://cwspro.oss-ap-southeast-1.aliyuncs.com/SDK/iOS/resource/IntegrationManual/screenshots_2/2_new_build_phase.jpeg)
Switch destination to **Frameworks** and add the **CWSShakeSDK.framework** file:
![](http://cwspro.oss-ap-southeast-1.aliyuncs.com/SDK/iOS/resource/IntegrationManual/screenshots_2/3_copy_framework_phase.jpeg)

## Usage

1. Import SDK header file.
  ```
  #import <CWSShakeSDK/CWSShakeSDK.h>
  ```

2. Make your view controller extend CWSShakeViewController.
  ```
  @interface ViewController : CWSShakeViewController
  ```

3. Make your view controller or any other object confirm to CWSShakeDelegate and implements all the required methods defined in the delegate.<br><br>
The CWSShakeDelegate is a protocol defined in the SDK. The declaration is as follows:
  ```
  @protocol CWSShakeDelegate <NSObject>
  @optional
  - (void)shakeControllerPermissionDenied:(CWSShakeViewController *)controller;
  @required
  - (BOOL)shakeControllerCanShake:(CWSShakeViewController *)controller;
  - (void)shakeControllerDidShake:(CWSShakeViewController *)controller;
  - (void)shakeController:(CWSShakeViewController *)controller didSucceedWithUserContent:(CWSUserContent *)userContent;
  - (void)shakeControllerDidCancel:(CWSShakeViewController *)controller;
  - (void)shakeController:(CWSShakeViewController *)controller didFailWithError:(CWSError *)error;
  ```
Confirm to this protocol:
  ```
  @interface ViewController () <CWSShakeDelegate>
  ```
Set the delegate to the view controller:
  ```
  self.shakeDelegate = self;
  ```

4. Call the **requestPermission** method of the SDK to ask for needed permissions from the user.
  ```
  [CWSShakeManager requestPermission];
  ```

5. Call the **register** method with your **appId** and **appSecret** before using any other functions of the SDK.
  ```
  [CWSShakeManager registerWithAppId:APP_ID appSecret:APP_SECRET success:^{

  } failure:^(CWSError *error) {

  }];
  ```

6. Add **NSMicrophoneUsageDescription** to the **Info.plist** of your project. Note that our SDK uses microphone when the user triggers the shake event. And it is compulsory to add the abovementioned key value pair to the Info.plist. Otherwise, the app will not be able to run.
![](http://cwspro.oss-ap-southeast-1.aliyuncs.com/SDK/iOS/resource/IntegrationManual/screenshots_2/4_microphone_privilege.jpeg)

7. Compile and run the application in a real iOS device or simulator. You may need a demo video to test the ACR functionality. Please refer to this site for demo videos: https://shake2buy.com

