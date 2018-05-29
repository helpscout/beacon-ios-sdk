#import <UIKit/UIKit.h>

#import "HSBeaconPickerView.h"

@interface HSBeaconDropdownPickerView : HSBeaconPickerView

@property (weak, nonatomic) IBOutlet UIPickerView *picker;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *clearBarButtonItem;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *doneBarButtonItem;

@end
