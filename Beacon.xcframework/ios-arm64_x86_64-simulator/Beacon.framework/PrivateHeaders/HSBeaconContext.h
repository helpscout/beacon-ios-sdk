#import <Foundation/Foundation.h>

#import <Beacon/HSBeaconConfig.h>
#import <Beacon/HSBeaconSettings.h>
#import <Beacon/HSBeaconFocusMode.h>
#import <Beacon/HSBeaconKeychainWrapper.h>
#import <Beacon/HSBeaconLocalizedStrings.h>
#import <Beacon/HSBeaconMessagingAPIClient.h>
#import <Beacon/HSBeaconNotificationPayload.h>
#import <Beacon/HSBeaconSecurityInfo.h>
#import <Beacon/HSBeaconSuggestionItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface HSBeaconContext : NSObject

@property (strong, nonatomic) HSBeaconConfig *config;
@property (readonly, nonatomic) HSBeaconSettings *beaconSettings;

/* these are readwrite for testing purposes */
@property (nonatomic) HSBeaconMessagingAPIClient *messagingApiClient;
@property (nonatomic) id<HSBeaconStringLocalizer> localizedStrings;

@property (readonly, nonatomic) HSBeaconSecurityInfo *securityInfo;
@property (readonly, nonatomic) HSBeaconKeychainWrapper *keychainWrapper;

@property (readonly, nonatomic) BOOL messagingEnabled;
@property (readonly, nonatomic) BOOL docsOnly;
@property (readonly, nonatomic) BOOL docsEnabled;
@property (readonly, nonatomic) BOOL messagingOnly;
@property (readonly, nonatomic) BOOL chatEnabled;
@property (readonly, nonatomic) BOOL chatRatingsEnabled;
@property (readonly, nonatomic) BOOL chatRequiresEmail;
@property (readonly, nonatomic) BOOL validConfig;
@property (readonly, nonatomic) BOOL previousMessagesEnabled;
@property (readonly, nonatomic) BOOL showNameEnabled;
@property (readonly, nonatomic) BOOL showSubjectEnabled;
@property (readonly, nonatomic) BOOL attachmentsEnabled;
@property (readonly, nonatomic) BOOL customFieldsEnabled;
@property (readonly, nonatomic) BOOL showPreviousMessagesEnabled;
@property (readonly, nonatomic) HSBeaconFocusMode focusMode;

@property (strong, nonatomic) NSArray<id<HSBeaconSuggestionItem>> *customSuggestions;

@property (atomic) BOOL loadFailed;

@property (nonatomic) BOOL hasPreviousMessages;

@property (nonatomic) NSInteger unreadMessageCount;

- (instancetype _Nonnull)initWithBeaconSettings:(HSBeaconSettings *_Nullable)beaconSettings user:(HSBeaconUser *_Nullable)user signature:(NSString *_Nullable)signature;

@end

NS_ASSUME_NONNULL_END
