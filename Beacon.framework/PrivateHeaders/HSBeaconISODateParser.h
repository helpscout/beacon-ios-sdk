#import <Foundation/Foundation.h>

@interface HSBeaconISODateParser : NSObject

- (NSDate *)dateFromString:(NSString *)dateString;

- (NSDate *)dateFromStringWithMicroseconds:(NSString *)dateString;

@end
