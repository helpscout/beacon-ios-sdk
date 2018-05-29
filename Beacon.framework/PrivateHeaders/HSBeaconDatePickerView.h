#import "HSBeaconPickerView.h"

@protocol HSBeaconDatePickerViewDelegate

- (void)dateChanged:(NSDate *)date;

@end

@interface HSBeaconDatePickerView : HSBeaconPickerView

@property (weak) id<HSBeaconDatePickerViewDelegate> delegate;

@property (weak, nonatomic) IBOutlet UIDatePicker *datePicker;
@property (weak, nonatomic) IBOutlet UIToolbar *clearButton;
@property (weak, nonatomic) IBOutlet UIToolbar *doneButton;

@end
