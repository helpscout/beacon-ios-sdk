#import <Foundation/Foundation.h>

@interface HSBeaconReplyNotificationPayload : NSObject

@property (nonatomic, strong, nonnull) NSNumber *conversationID;
@property (nonatomic, strong, nonnull) NSString *mailboxID;
@property (nonatomic, strong, nonnull) NSString *messageID;
@property (nonatomic, strong, nonnull) NSString *threadID;
@property (nonatomic, strong, nullable) NSString *title;

- (nullable instancetype)initWithUserInfo:(NSDictionary *_Nullable)userInfo;

@end
