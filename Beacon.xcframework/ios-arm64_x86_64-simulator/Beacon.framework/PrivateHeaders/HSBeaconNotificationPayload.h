#import <Foundation/Foundation.h>

#import <Beacon/HSBeaconReplyNotificationPayload.h>
#import <Beacon/HSBeaconChatNotificationPayload.h>

NS_ASSUME_NONNULL_BEGIN

@interface HSBeaconNotificationPayload : NSObject

@property (nonatomic, strong, nullable) NSString *action;
@property (nonatomic, strong, nullable) HSBeaconReplyNotificationPayload *replyPayload;
@property (nonatomic, strong, nullable) HSBeaconChatNotificationPayload *chatPayload;

- (nullable instancetype)initWithUserInfo:(NSDictionary *)userInfo;

@end

NS_ASSUME_NONNULL_END
