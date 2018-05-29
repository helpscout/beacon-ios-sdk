#import <Foundation/Foundation.h>

@interface HSBeaconReplyMessage : NSObject

@property(readonly, nonatomic) long conversationId;
@property(strong, nonatomic) NSString *text;
@property(strong, nonatomic) NSArray<NSString *> *attachmentIds;

-(instancetype)initWithConversationId:(long)conversationId;

-(NSDictionary *)toDictionary;

@end
