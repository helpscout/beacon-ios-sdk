#import <Foundation/Foundation.h>

#import <Beacon/HSBeaconBaseAPIClient.h>
#import <Beacon/HSBeaconSecurityInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface HSBeaconMessagingAPIClient: HSBeaconBaseAPIClient

- (NSURLSessionDataTask *)registerForPushNotificationsWithVendorID:(NSString *)vendorID securityInfo:(HSBeaconSecurityInfo *)securityInfo token:(NSData *)token completion:(ErrorCompletionHandler)completion;

- (NSURLSessionDataTask *)registerForPushNotificationsWithVendorID:(NSString *)vendorID securityInfo:(HSBeaconSecurityInfo *)securityInfo token:(NSData *)token email:(nullable NSString *)email completion:(ErrorCompletionHandler)completion;

- (NSURLSessionDataTask *)subscribeToNotificationsForConversation:(NSString *)conversationID securityInfo:(HSBeaconSecurityInfo *)securityInfo completion:(ErrorCompletionHandler)completion;

- (NSURLSessionDataTask *)validateSignature:(HSBeaconSecurityInfo *)securityInfo completion:(BooleanCompletionHandler)completion;

- (NSURLSessionDataTask *)identifyUser:(HSBeaconSecurityInfo *)securityInfo completion:(BooleanCompletionHandler)completion;

@end

NS_ASSUME_NONNULL_END
