#import <UIKit/UIKit.h>

@class HSBeaconNavigationController;

@protocol HSBeaconNavigationControllerDelegate

- (void)beaconNavigationControllerDismissed:(HSBeaconNavigationController *)navigationController;

@end

@interface HSBeaconNavigationController : UINavigationController

@property (nonatomic, weak) id<HSBeaconNavigationControllerDelegate> beaconNavigationDelegate;

@end
