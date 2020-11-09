#import <Foundation/Foundation.h>

@class HSBeaconRouting;

@protocol HSBeaconRoutingFulfilling <NSObject>

- (void)fulfillRouting:(HSBeaconRouting *)routing;

@end
