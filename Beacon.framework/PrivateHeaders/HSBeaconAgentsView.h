#import <UIKit/UIKit.h>
#import "HSView.h"
#import "HSBeaconAgent.h"

@interface HSBeaconAgentsView : HSView

@property (nonatomic, strong) UIColor *agentViewBackgroundColor;
@property (nonatomic, strong) UIColor *agentViewBorderColor;
@property (nonatomic, strong) UIColor *agentViewInitialsColor;
/// Whether or not the Agent image views should animate in when they're set
/// Defaults to YES
@property (nonatomic, assign) BOOL animateAgentsIn;
@property (nonatomic, assign) BOOL hideAgentsWithoutAvatars;

- (void)setAgents:(NSArray<HSBeaconAgent *> *) agents agentSize:(float)agentSize;

@end
