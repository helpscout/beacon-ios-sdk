#import <UIKit/UIKit.h>

#import "HSBeaconContext.h"

@interface HSBeaconAskSelectionController: UITableViewController

@property(strong, nonatomic) HSBeaconContext *beaconContext;

@property(weak, nonatomic) IBOutlet UILabel *messageSubtitle;

@end
