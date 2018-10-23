#import <UIKit/UIKit.h>

@class HSBeaconContext;
@class HSBeaconNavigationController;

@protocol HSBeaconNavigationControllerDelegate

- (void)beaconNavigationControllerDismissed:(HSBeaconNavigationController *)navigationController;

@end

@interface HSBeaconNavigationController : UINavigationController

@property (nonatomic, weak) id<HSBeaconNavigationControllerDelegate> beaconNavigationDelegate;
@property (nonatomic, weak) HSBeaconContext *beaconContext;

- (void)updateStatusBar;

@end
