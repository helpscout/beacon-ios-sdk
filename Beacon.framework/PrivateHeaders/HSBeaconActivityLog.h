#import <Foundation/Foundation.h>

@interface HSBeaconActivityLog: NSObject

- (void)addActivityOfType: (NSString *)type attributes: (NSDictionary *)dictionary;

- (NSArray<NSDictionary *> *)asArray;

- (void)clearLog;

@end
