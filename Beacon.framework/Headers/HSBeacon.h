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

#pragma mark - Push Notifications

/**
 Initializes push notifications for the Beacon SDK. This should be called if you
 intend to receive push notifications, whether they are handled automatically or
 manually.
 */
+ (void)initializeBeaconPushNotificationSupport;

/**
 Initializes automatic push notification handling for the Beacon SDK. This should
 be called if you do not have to handle any push notifications that aren't from
 Beacon.

 @param methodSwizzling Whether to override push notification methods on the
 App Delegate.
 @param overrideDelegate Whether to override `UNUserNotificationCenter`'s delegate
 method for automatic handling of push notifications.
 */
+ (void)initializeAutomaticPushNotificationHandlingWithMethodSwizzling:(BOOL)methodSwizzling overrideUserNotificationCenterDelegate:(BOOL)overrideDelegate;

/**
 Sets the push notification device token.
 */
+ (void)setDeviceToken:(NSData *)deviceToken;

/**
 Checks whether a given push notification came from Help Scout. You should call
 this method before calling `handlePushNotification:`.
 */
+ (BOOL)isBeaconPushNotification:(NSDictionary *)userInfo;

/**
 Handles a Beacon push notification. If the user info dictionary does not match
 the expected format, this method does nothing.

 @param userInfo The user info payload from the notification.
 @param settings The Beacon settings from which to load Beacon.

 @note Displays Beacon from the application delegate's window root view controller.
 */
+ (void)handlePushNotification:(NSDictionary *)userInfo beaconSettings:(HSBeaconSettings *)settings;

/**
 Handles a Beacon push notification. If the user info dictionary does not match
 the expected format, this method does nothing.

 @param userInfo The user info payload from the notification.
 @param settings The Beacon settings from which to load Beacon.
 @param viewController The view controller to display Beacon from.
 */
+ (void)handlePushNotification:(NSDictionary *)userInfo beaconSettings:(HSBeaconSettings *)settings viewController:(UIViewController *)viewController;

/**
 Handles a Beacon push notification. If the user info dictionary does not match
 the expected format, this method does nothing.

 @param userInfo The user info payload from the notification.
 @param settings The Beacon settings from which to load Beacon.
 @param signature The signature to provide, if you are using secure mode.

 @note Displays Beacon from the application delegate's window root view controller.
 */
+ (void)handlePushNotification:(NSDictionary *)userInfo beaconSettings:(HSBeaconSettings *)settings signature:(NSString * _Nullable)signature;

/**
 Handles a Beacon push notification. If the user info dictionary does not match
 the expected format, this method does nothing.

 @param userInfo The user info payload from the notification.
 @param settings The Beacon settings from which to load Beacon.
 @param viewController The view controller to display Beacon from.
 @param signature The signature to provide, if you are using secure mode.
 */
+ (void)handlePushNotification:(NSDictionary *)userInfo beaconSettings:(HSBeaconSettings *)settings viewController:(UIViewController *)viewController signature:(NSString * _Nullable)signature;

#pragma mark - Unavailable Methods

/**
 `-[HSBeacon init]` is not available because `HSBeacon` cannot be created directly.
 Use the `openBeacon:` methods to display the Beacon SDK.
 */
- (instancetype)init __attribute__((unavailable("HSBeacon cannot be created directly")));

@end

NS_ASSUME_NONNULL_END
