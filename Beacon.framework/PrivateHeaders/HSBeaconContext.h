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
#import "HSBeaconTintColor.h"
#import "HSBeaconReplyNotificationPayload.h"

NS_ASSUME_NONNULL_BEGIN

@interface HSBeaconContext : NSObject

@property (strong, nonatomic) HSBeaconConfig *config;
@property (readonly) HSBeaconSettings *beaconSettings;
@property (readonly) HSBeaconTintColor *tintColorSettings;
@property (readonly) HSBeaconDocsAPIClient *docsApiClient;
@property (readonly) HSBeaconMessagingAPIClient *messagingApiClient;
@property (readonly) HSBeaconCloudFrontAPIClient *cloudFrontApiClient;
@property (readonly) id<HSBeaconStringLocalizer> localizedStrings;
@property (readonly) HSBeaconActivityLog *activityLog;
@property (readonly) HSBeaconSecurityInfo *securityInfo;
@property (readonly) HSBeaconKeychainWrapper *keychainWrapper;

@property (readonly) NSMutableDictionary<NSNumber *, HSBeaconReplyMessage *> *draftReplies;
@property (readonly) BOOL messagingEnabled;
@property (readonly) BOOL docsOnly;
@property (readonly) BOOL docsEnabled;
@property (readonly) BOOL messagingOnly;
@property (readonly) BOOL validConfig;

@property (readonly, nonatomic) BOOL showNameEnabled;
@property (readonly, nonatomic) BOOL showSubjectEnabled;
@property (readonly, nonatomic) BOOL attachmentsEnabled;
@property (readonly, nonatomic) BOOL customFieldsEnabled;
@property (readonly, nonatomic) BOOL showGetInTouchEnabled;

@property (atomic) BOOL loadFailed;

@property (nullable) HSBeaconEmailMessage *draftMessage;

- (instancetype _Nonnull)initWithBeaconSettings:(HSBeaconSettings *_Nullable)beaconSettings user:(HSBeaconUser *_Nullable)user signature:(NSString *_Nullable)signature;

- (instancetype _Nonnull)initWithBeaconSettings:(HSBeaconSettings *_Nullable)beaconSettings
                                           user:(HSBeaconUser *_Nullable)user
                                      signature:(NSString *_Nullable)signature
                                stringLocalizer:(id<HSBeaconStringLocalizer>)stringLocalizer
                                messagingClient:(HSBeaconMessagingAPIClient *_Nullable)messagingClient;

- (void)lookupUserDeviceInfo;

@end

NS_ASSUME_NONNULL_END
