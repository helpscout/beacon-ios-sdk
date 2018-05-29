#import <UIKit/UIKit.h>

@class HSBeaconUser;
@class HSBeaconSettings;

NS_ASSUME_NONNULL_BEGIN

/**
 `HSBeacon` provides the APIs necessary to display the Beacon SDK. It allows you
 to open the Beacon from the current view controller on screen, or a specific
 view controller of your choice.

 ### Opening the Beacon From The Current View Controller

 The Beacon SDK requires an `HSBeaconSettings` object, which can be initialized
 using your Beacon ID.

     HSBeaconSettings *settings = [[HSBeaconSettings alloc] initWithBeaconId:@"beacon-id"];
     [HSBeacon openBeacon:settings];

 ### Authenticating Users

 Authenticating with Beacon is optional, but if you have information you'd like
 to associate with users, you can do so using `HSBeaconUser` and the `login:`
 method before showing the Beacon.

     HSBeaconUser *user = [[HSBeaconUser alloc] init];
     user.email = self.emailTextField.text;
     user.name = self.nameTextField.text;

     [HSBeacon login:user];

     HSBeaconSettings *settings = [[HSBeaconSettings alloc] initWithBeaconId:@"beacon-id"];
     [HSBeacon openBeacon:settings];
 */
@interface HSBeacon : NSObject

/**
 Opens the Beacon SDK from the current view controller.
 */
+ (void)openBeacon:(HSBeaconSettings *)beaconSettings;

/**
 Opens the Beacon SDK from the current view controller, using a signature.
 */
+ (void)openBeacon:(HSBeaconSettings *)beaconSettings signature:(NSString *)signature;

/**
 Opens the Beacon SDK from a specific view controller. The Beacon view controller
 will be presented as a modal.
 */
+ (void)openBeacon:(HSBeaconSettings *)beaconSettings fromViewController:(UIViewController *)viewController;

/**
 Opens the Beacon SDK from a specific view controller. The Beacon view controller
 will be presented as a modal.
 */
+ (void)openBeacon:(HSBeaconSettings *)beaconSettings fromViewController:(UIViewController *)viewController signature:(NSString *)signature;

/**
 Signs in with a Beacon user. This gives Beacon access to the user's name, email
 address, and signature.
 */
+ (instancetype)login:(HSBeaconUser *)user;

/**
 Returns the current user, providing they are signed in.
 */
+ (HSBeaconUser * _Nullable)currentUser;

/**
 Logs the current Beacon user out and clears out their information from local
 storage.
 */
+ (void)logout;

#pragma mark - Unavailable Methods

/**
 `-[HSBeacon init]` is not available because `HSBeacon` cannot be created directly.
 Use the `openBeacon:` methods to display the Beacon SDK.
 */
- (instancetype)init __attribute__((unavailable("HSBeacon cannot be created directly")));

@end

NS_ASSUME_NONNULL_END
