#import <UIKit/UIKit.h>
#import "HSTableViewController.h"
#import "HSBeaconContext.h"

@interface HSBeaconAskSelectionController: HSTableViewController

@property(strong, nonatomic) HSBeaconContext *beaconContext;

@property(weak, nonatomic) IBOutlet UILabel *messageSubtitle;

@property (weak, nonatomic) IBOutlet UIBarButtonItem *closeButton;

@end
