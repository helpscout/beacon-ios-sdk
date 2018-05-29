#import <Foundation/Foundation.h>

@interface HSBeaconCustomFieldValue : NSObject

@property (readonly, nonatomic) NSNumber *fieldId;

@property (nonatomic) NSString *value;

- (instancetype) initWithFieldId:(NSNumber *)fieldId;

- (NSDictionary *) asDictionary;

@end
