#import <UIKit/UIKit.h>

@interface HSBeaconLoadingViewController : UIViewController

+ (instancetype)instantiateViewController;

@property(weak, nonatomic) IBOutlet UIActivityIndicatorView *spinner;

- (void)displayLoadingViewInsideViewController:(UIViewController *)hostingViewController visible:(BOOL)visible;

@end
