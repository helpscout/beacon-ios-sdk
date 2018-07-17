#import <UIKit/UIKit.h>

@class HSBeaconContactFormField;

@protocol HSBeaconContactFormFieldDelegate

- (void)contactFormFieldTextChanged:(HSBeaconContactFormField *)field;

@end

@interface HSBeaconContactFormField : UIView

@property (weak, nonatomic) IBOutlet UITextField *inputField;
@property (weak, nonatomic) IBOutlet UIView *topErrorBar;
@property (weak, nonatomic) IBOutlet UIView *bottomErrorBar;
@property (weak, nonatomic) IBOutlet UIImageView *errorIcon;
@property (weak, nonatomic) id<HSBeaconContactFormFieldDelegate> delegate;
@property (strong, nonatomic) IBOutlet UIView *contentView;

- (void)showError;

- (void)hideError;

- (NSString *)text;

- (void)setText:(NSString *)text;

- (void)setPlaceholder:(NSString *)placeholder;

@end
