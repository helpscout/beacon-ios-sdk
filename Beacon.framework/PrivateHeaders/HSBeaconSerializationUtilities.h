#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HSBeaconSerializationUtilities : NSObject

+ (void)saveConversationID:(NSString *)conversationID mappedToBeaconID:(NSString *)beaconID;

+ (nullable NSString *)beaconIDForConversationID:(NSString *)conversationID;

@end

NS_ASSUME_NONNULL_END
