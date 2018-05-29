#import <Foundation/Foundation.h>

@class HSBeaconUser;

/*
 * This is the user info stored in the keychain for non-secure users.
 * It's stored after they send their first message and retrieved when the Beacon is opened
 */
@interface HSBeaconUserDeviceInfo : NSObject

@property (readonly, nonatomic) NSString *deviceId;
@property (readonly, nonatomic) NSString *email;
@property (readonly, nonatomic) NSString *name;

- (instancetype)initWithUser:(HSBeaconUser *)user deviceId:(NSString *)deviceId;

@end
