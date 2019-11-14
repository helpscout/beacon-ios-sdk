#import <UIKit/UIKit.h>
#import "HSView.h"
#import "HSBeaconAgent.h"

@interface HSBeaconAgentsView : HSView

@property (nonatomic, strong) UIColor *agentViewBackgroundColor;
@property (nonatomic, strong) UIColor *agentViewBorderColor;
@property (nonatomic, strong) UIColor *agentViewInitialsColor;
@property (nonatomic, assign) BOOL hideAgentsWithoutAvatars;

- (void)setAgents:(NSArray<HSBeaconAgent *> *) agents agentSize:(float)agentSize;

@end
