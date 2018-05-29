#import <UIKit/UIKit.h>

#import "HSBeaconConversation.h"
#import "HSBeaconContext.h"

@interface HSBeaconSingleThreadConversationCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *firstThreadPreviewLabel;

@property (weak, nonatomic) IBOutlet UILabel *recievedLabel;

@property (strong, nonatomic) HSBeaconContext *beaconContext;

-(void)setConversation: (HSBeaconConversation *)conversation;

@end
