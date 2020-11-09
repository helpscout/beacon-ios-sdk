#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (Beacon)

+ (UIColor *)hsPrimaryText;
+ (UIColor *)hsSecondaryText;
+ (UIColor *)hsTertiaryText;
+ (UIColor *)beaconBackground;
+ (UIColor *)secondaryBeaconBackground;
+ (UIColor *)tertiaryBeaconBackground;
+ (UIColor *)searchBarPlaceholderText;
+ (UIColor *)primaryActionColor;
+ (UIColor *)toolbarButton;
+ (UIColor *)badgeColor;
+ (UIColor *)borderButtonColor;
+ (UIColor *)yellow800;
+ (UIColor *)brightOrange;

// used in tests as default beacon color
+ (UIColor *)defaultBeaconColor;
+ (UIColor *)lightBeaconColor;

@end

NS_ASSUME_NONNULL_END
