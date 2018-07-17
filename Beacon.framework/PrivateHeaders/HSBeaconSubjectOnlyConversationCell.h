#import <UIKit/UIKit.h>

#import "HSBeaconConversation.h"

@interface HSBeaconSubjectOnlyConversationCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *subjectLabel;
@property (weak, nonatomic) IBOutlet UIView *convoContainer;

-(void)setConversation: (HSBeaconConversation *)conversation;

@end
