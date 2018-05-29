#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `HSBeaconSettings` allows you to customize the Beacon SDK and provide the
 Beacon identifier to use.

 ### Initialization

     HSBeaconSettings *settings = [[HSBeaconSettings alloc] initWithBeaconId:@"beacon-id"];
     settings.useNavigationBarAppearance = NO;
 */
@interface HSBeaconSettings: NSObject

/**
 The Beacon ID to use.

 @note This can be found during Beacon creation.
 */
@property(strong, nonatomic) NSString *beaconId;

/**
 The title used in the main Beacon interface. This is `Support` by default.
 */
@property(strong, nonatomic) NSString *beaconTitle;

/**
 * Display strings from BeaconLocalizable.strings instead of those setup in the Beacon Web UI
 */
@property BOOL useLocalTranslationOverrides;

/**
 Allows the Beacon SDK to use the `UIAppearance` settings for `UINavigationController`.
 This is false by default, and will instead use the Beacon color defined in the Beacon Builder.
 */
@property BOOL useNavigationBarAppearance;

// also use translations from the API or local translation strings (maybe)

// later will add settings here for push notifications
// ex from Smooch https://docs.smooch.io/api/ios/Classes/SKTSettings.html
//enableAppDelegateSwizzling
//enableUserNotificationCenterDelegateOverride
//requestPushPermissionOnFirstMessage

- (instancetype)initWithBeaconId:(NSString *)beaconId;

@end

NS_ASSUME_NONNULL_END
