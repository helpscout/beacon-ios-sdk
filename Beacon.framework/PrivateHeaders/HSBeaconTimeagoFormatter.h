#import <Foundation/Foundation.h>

#import "HSBeaconLocalizedStrings.h"

@interface HSBeaconTimeagoFormatter : NSObject

+ (NSString *)timeagoText:(NSDate *)date localizedStrings:(HSBeaconLocalizedStrings *)localizedStrings;

@end
