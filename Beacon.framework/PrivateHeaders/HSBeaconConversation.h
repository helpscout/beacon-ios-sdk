#import <UIKit/UIKit.h>

#import "HSBeaconAgent.h"
#import "HSBeaconConversationThread.h"

@interface HSBeaconConversation : NSObject

@property (readonly, nonatomic) long conversationId;

@property (readonly, nonatomic) NSString *subject;

@property (readonly, nonatomic) int threadCount;

@property (readonly, nonatomic) NSDate *lastUpdated;

@property (readonly, nonatomic) NSString *lastThreadPreview;

@property (readonly, nonatomic) BOOL waitingForReply;

@property (readonly, nonatomic) NSArray<HSBeaconAgent *> *agents;

-(instancetype)initWithDictionary: (NSDictionary *)dictionary;

-(BOOL)hasMultipleThreads;

@end
