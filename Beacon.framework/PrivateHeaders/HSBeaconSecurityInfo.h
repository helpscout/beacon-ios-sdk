#import <Foundation/Foundation.h>

@class HSBeaconUser;
@class HSBeaconUserDeviceInfo;

@interface HSBeaconSecurityInfo : NSObject

@property (nonatomic) HSBeaconUser *user;
@property (nonatomic) NSString *signature;
@property (nonatomic) NSString *deviceId;
@property (nonatomic) BOOL signatureVerified;

-(BOOL)requiresSynchronization;

-(void)markSynchronized;

-(HSBeaconUserDeviceInfo *)userDeviceInfo;

-(BOOL)hasSignature;

-(BOOL)hasBeaconAuthorization;

-(BOOL)signatureMatches:(NSString *)signature;

@end
