#import <Foundation/Foundation.h>

#import "HSBeaconActivityLog.h"
#import "HSBeaconConfig.h"
#import "HSBeaconEmailMessage.h"
#import "HSBeaconKeychainWrapper.h"
#import "HSBeaconLocalizedStrings.h"
#import "HSBeaconDocsAPIClient.h"
#import "HSBeaconMessagingAPIClient.h"
#import "HSBeaconCloudFrontAPIClient.h"
#import "HSBeaconSecurityInfo.h"
#import "HSTintColor.h"

NS_ASSUME_NONNULL_BEGIN

@interface HSBeaconContext : NSObject

@property(strong, nonatomic) HSBeaconConfig *config;
@property(readonly) HSBeaconSettings *beaconSettings;
@property(readonly) HSTintColor *tintColorSettings;
@property(readonly) HSBeaconDocsAPIClient *docsApiClient;
@property(readonly) HSBeaconMessagingAPIClient *messagingApiClient;
@property(readonly) HSBeaconCloudFrontAPIClient *cloudFrontApiClient;
@property(readonly) HSBeaconLocalizedStrings *localizedStrings;
@property(readonly) HSBeaconActivityLog *activityLog;
@property(readonly) HSBeaconSecurityInfo *securityInfo;
@property(readonly) HSBeaconKeychainWrapper *keychainWrapper;

@property(nullable) HSBeaconEmailMessage *draftMessage;

- (instancetype _Nonnull)initWithBeaconSettings:(HSBeaconSettings *_Nullable)beaconSettings user:(HSBeaconUser *_Nullable)user signature:(NSString *_Nullable)signature;

@end

NS_ASSUME_NONNULL_END
