#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HSBeaconReplyNotificationPayload : NSObject

@property (nonatomic, strong) NSNumber *conversationID;
@property (nonatomic, strong) NSString *mailboxID;
@property (nonatomic, strong) NSString *messageID;
@property (nonatomic, strong) NSString *threadID;
@property (nonatomic, strong) NSString *title;

- (nullable instancetype)initWithUserInfo:(NSDictionary *)userInfo;

@end

NS_ASSUME_NONNULL_END
