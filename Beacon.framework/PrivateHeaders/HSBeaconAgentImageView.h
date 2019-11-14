#import <UIKit/UIKit.h>
#import "HSView.h"
#import "HSBeaconAgent.h"

@interface HSBeaconAgentImageView: HSView

-(void)setAgent:(HSBeaconAgent *)agent backgroundColor:(UIColor *)backgroundColor borderColor:(UIColor *)borderColor initialsColor:(UIColor *)initialsColor;

@end
