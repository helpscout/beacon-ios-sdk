#import <UIKit/UIKit.h>

#import "HSBeaconAgentsView.h"
#import "HSBeaconConversation.h"

@interface HSBeaconMultiThreadConversationCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *timeagoLabel;
@property (weak, nonatomic) IBOutlet UILabel *threadCountLabel;
@property (weak, nonatomic) IBOutlet UILabel *firstThreadPreviewLabel;
@property (weak, nonatomic) IBOutlet UILabel *lastThreadPreviewLabel;
@property (weak, nonatomic) IBOutlet HSBeaconAgentsView *agentsView;

-(void)setConversation: (HSBeaconConversation *)conversation;

@end
