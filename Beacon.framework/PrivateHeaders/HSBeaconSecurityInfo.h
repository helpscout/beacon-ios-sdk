#import <Foundation/Foundation.h>

@class HSBeaconUser;
@class HSBeaconUserDeviceInfo;

@interface HSBeaconSecurityInfo : NSObject

@property (strong, nonatomic) HSBeaconUser *user;
@property (strong, nonatomic) NSString *signature;
@property (strong, nonatomic) NSString *deviceId;

-(BOOL)requiresSynchronization;

-(void)markSynchronized;

-(HSBeaconUserDeviceInfo *)userDeviceInfo;

-(BOOL)hasSignature;

@end
