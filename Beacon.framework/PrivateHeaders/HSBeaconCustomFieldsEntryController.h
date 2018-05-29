#import <UIKit/UIKit.h>

#import "HSBeaconCustomFieldDefinition.h"
#import "HSBeaconCustomFieldValue.h"
#import "HSBeaconContext.h"

@protocol HSBeaconCustomFieldsEntryControllerDelegate

- (void)customFieldsFormEnableSubmit:(BOOL)enabled;

- (void)showErrorMessage:(NSString *)errorMessage;

@end

@interface HSBeaconCustomFieldsEntryController : UIViewController

@property (nonatomic, strong) HSBeaconContext *beaconContext;

@property (readwrite, nonatomic) NSArray<HSBeaconCustomFieldDefinition *> *fieldDefinitions;
@property (readonly, nonatomic) NSArray<HSBeaconCustomFieldValue *> *fieldValues;
@property (nonatomic) id<HSBeaconCustomFieldsEntryControllerDelegate> delegate;

- (BOOL)validateFieldsWithErrorsDisplayed:(BOOL)showErrors;

- (void)clearFields;

@end
