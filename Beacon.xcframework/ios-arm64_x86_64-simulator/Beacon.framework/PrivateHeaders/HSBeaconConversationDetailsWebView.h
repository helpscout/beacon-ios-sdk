#import <UIKit/UIKit.h>
#import <HSWebView.h>
#import <HSBeaconContext.h>
#import <HSBeaconConversationThread.h>

@interface HSBeaconConversationDetailsWebView : HSWebView

extern NSString *const ShowMorePath;

@property (nonatomic) HSBeaconContext *beaconContext;

- (void)setup;

- (void)addHeader:(NSString *)header;

- (void)addThreads:(NSArray <HSBeaconConversationThread *> *)threads oldestThread:(HSBeaconConversationThread *_Nullable)oldestThread;

- (void)scrollToLast;

- (void)clearThreads;

- (void)showWaiting:(NSString *)receivedText waitingText:(NSString *)waitingText;

@end
