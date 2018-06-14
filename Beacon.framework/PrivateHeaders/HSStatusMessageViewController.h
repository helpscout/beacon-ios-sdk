#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface HSStatusMessageViewController : UIViewController

@property (nonatomic, weak) IBOutlet UIImageView *imageView;
@property (nonatomic, weak) IBOutlet UILabel *titleLabel;
@property (nonatomic, weak) IBOutlet UILabel *messageLabel;
@property (nonatomic, weak) IBOutlet NSLayoutConstraint *viewTopConstraint; // For assigning to a Safe Area layout guide
@property (nonatomic, weak) IBOutlet NSLayoutConstraint *titleTopConstraint;

- (instancetype)initWithMessage:(NSString *)errorString;

- (instancetype)initWithTitle:(nullable NSString *)title message:(NSString *)message;

- (void)showStatusInViewController:(UIViewController *)viewController;

- (void)removeStatus;

@end

NS_ASSUME_NONNULL_END
