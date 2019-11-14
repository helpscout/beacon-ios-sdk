#import <UIKit/UIKit.h>
#import "HSView.h"
#import "HSBeaconFontIcons.h"

@interface HSBeaconNavigationTabView : HSView

- (void)addTab:(HSIcon)icon text:(NSString *)text pressed:(BOOL)pressed tabColor:(UIColor *)color;

- (void)setTabAction:(int)index target:(id)target action:(SEL)action;

@end
