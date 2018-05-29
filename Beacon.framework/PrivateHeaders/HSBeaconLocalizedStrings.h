#import <Foundation/Foundation.h>

@interface HSBeaconLocalizedStrings: NSObject

@property (strong, nonatomic) NSDictionary<NSString *, NSString *> *configStrings;
@property BOOL useLocalOverrides;

-(NSString *)localizedStringForKey: (NSString *)key;

@end
