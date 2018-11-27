#import "HSBeaconCoordinator.h"
#import "HSBeaconContext.h"
#import "HSBeaconSuggestionsContainerController.h"

NS_ASSUME_NONNULL_BEGIN

@class HSSuggestionsCoordinator;

#pragma mark - HSSuggestionsCoordinatorDelegate

@protocol HSSuggestionsCoordinatorDelegate

- (void)suggestionsCoordinatorRequestsDismissal:(HSSuggestionsCoordinator *)suggestionsCoordinator;

@end

#pragma mark - HSSuggestionsCoordinator

@interface HSSuggestionsCoordinator : NSObject <HSBeaconCoordinator, HSBeaconSuggestionsContainerControllerDelegate>

@property (nonatomic, weak) id<HSSuggestionsCoordinatorDelegate> delegate;
@property (nonatomic, readonly) UINavigationController *navigationController;
@property (readonly) HSBeaconContext *beaconContext;
@property (nonatomic) BOOL navigateWithAnimation;

- (instancetype)initWithNavigationController:(UINavigationController *)navigationController beaconContext:(HSBeaconContext *)context;

- (void)start;

- (void)runSearch:(NSString *)text;

@end

NS_ASSUME_NONNULL_END
