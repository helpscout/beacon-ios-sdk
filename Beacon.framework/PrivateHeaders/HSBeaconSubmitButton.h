#import <UIKit/UIKit.h>

#import "HSTintColor.h"

@interface HSBeaconSubmitButton : UIButton

-(void)inactiveState;

-(void)activeState:(HSTintColor *)tintColor;

@end
