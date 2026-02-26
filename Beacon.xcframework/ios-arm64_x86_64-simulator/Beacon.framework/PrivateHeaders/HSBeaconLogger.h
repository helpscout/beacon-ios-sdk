#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HSBeaconLogger : NSObject

+ (void)log:(NSString *)format, ... NS_FORMAT_FUNCTION(1, 2);

@end

#define HSBeaconLog(...) [HSBeaconLogger log:__VA_ARGS__]

NS_ASSUME_NONNULL_END
